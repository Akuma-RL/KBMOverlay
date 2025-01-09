#include "pch.h"
#include "Render.h"
#include "KBMOverlay.h"
#include "Utils.h"

Rect Render::GetKeyRegion(KBMOverlay* plugin, const std::string& actionKey) {
	if (plugin->keyRegions.find(actionKey) != plugin->keyRegions.end()) {
		return plugin->keyRegions[actionKey];
	}
	return { 0, 0, 0, 0 }; // Default empty Rect
}

bool Render::IsPlaceholderRegion(const Rect& region, float scaleFactor) {
	constexpr int placeholderX = 0;
	constexpr int placeholderY = 0;
	constexpr int originalWidth = 158;
	constexpr int originalHeight = 128;

	// Calculate scaled dimensions
	float scaledWidth = originalWidth / scaleFactor;
	float scaledHeight = originalHeight / scaleFactor;

	// Check for placeholder attributes
	return (region.x == placeholderX && region.y == placeholderY &&
		region.width == originalWidth && region.height == originalHeight) ||
		(region.width <= scaledWidth + 1 && region.height <= scaledHeight + 1);
}

void Render::RenderCanvas(KBMOverlay* plugin, CanvasWrapper& canvas) {
    if (*enableOverlay == false) { return; }
    
    // Use canvasPosition as the origin for the entire canvas
    Vector2 canvasOrigin = (canvasPosition != nullptr) ? *canvasPosition : Vector2{ 0, 0 };

    std::set<std::string> renderedKeys; // Track rendered keys

    // Render the keyboard overlay
    if (plugin->keyboardImage && plugin->keyboardImage->IsLoadedForCanvas()) {
        for (const auto& [action, regionPtr] : plugin->actionRegions) {
            if (!regionPtr) continue;

            Rect region = *regionPtr;

            // Find the associated key for this action
            auto it = plugin->actionKeyMap.find(action);
            if (it == plugin->actionKeyMap.end()) continue;


            const std::string& dkey = it->second;

            // Skip if the key has already been rendered
            if (renderedKeys.find(dkey) != renderedKeys.end()) {
                continue;
            }

            // Mark the key as rendered
            renderedKeys.insert(dkey);

            const std::string& key = it->second;

            // Adjust for pressed state
            if (plugin->keyStates[key].pressed) {
                region.y += *offsetBy; // Shift Y for "pressed" texture
            }

            // Get the original position for this action
            auto posIt = plugin->actionPositions.find(action);
            if (posIt == plugin->actionPositions.end()) continue;

            ImVec2 originalPos = posIt->second;

            // Apply scaling and canvas offset
            Vector2F scaledPos(
                (*canvasPosition).X + (originalPos.x * (*overallScaleFactor)),
                (*canvasPosition).Y + (originalPos.y * (*overallScaleFactor))
            );
            canvas.SetPosition(scaledPos);

            // Draw the keyboard key
            canvas.DrawTile(
                plugin->keyboardImage.get(),
                region.width / plugin->scaleFactor * (*overallScaleFactor),
                region.height / plugin->scaleFactor * (*overallScaleFactor),
                region.x, region.y,
                region.width, region.height,
                { 1, 1, 1, 1 }, 0, 1
            );
        }
    }
    // Use canvasPosition and overallScaleFactor directly

    // Render the mouse overlay if enabled
    if (*gUseMouseOverlay && plugin->mouseImage && plugin->mouseImage->IsLoadedForCanvas()) {
        for (const auto& [action, regionPtr] : plugin->mouseActionRegions) {
            if (!regionPtr) continue;

            Rect region = *regionPtr;

            // Find the associated key for this action
            auto it = plugin->actionKeyMap.find(action);
            if (it == plugin->actionKeyMap.end()) continue;

            const std::string& key = it->second;

            // Adjust for pressed state
            if (plugin->keyStates[key].pressed) {
                region.y += 131; // Shift Y for "pressed" texture
            }

            // Get the original position for this action
            auto posIt = plugin->mouseActionPositions.find(action);
            if (posIt == plugin->mouseActionPositions.end()) continue;

            ImVec2 originalPos = posIt->second;

            // Apply scaling and canvas offset
            Vector2F scaledPos(
                (*canvasPosition).X + (originalPos.x * (*overallScaleFactor)),
                (*canvasPosition).Y + (originalPos.y * (*overallScaleFactor))
            );
            canvas.SetPosition(scaledPos);

            // Draw the mouse button
            canvas.DrawTile(
                plugin->mouseImage.get(),
                region.width / plugin->scaleFactor * (*overallScaleFactor),
                region.height / plugin->scaleFactor * (*overallScaleFactor),
                region.x, region.y,
                region.width, region.height,
                { 1, 1, 1, 1 }, 0, 1
            );
        }
    }
}

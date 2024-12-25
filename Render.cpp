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
    if (!plugin->keyboardImage || !plugin->keyboardImage->IsLoadedForCanvas()) {
        LOG("[KBMOverlay] No image loaded for rendering.");
        return;
    }

    std::set<std::string> renderedKeys; // Track rendered keys

    // Use canvasPosition as the origin for the entire canvas
    Vector2F canvasOrigin = (canvasPosition != nullptr) ? *canvasPosition : Vector2F{ 0.F, 0.F };

    for (const auto& [action, regionPtr] : plugin->actionRegions) {
        if (!regionPtr) {
            continue;
        }

        Rect region = *regionPtr;
        const auto& key = plugin->actionKeyMap[action];

        if (IsPlaceholderRegion(region, plugin->scaleFactor)) {
            continue;
        }

        // Get the key associated with this action
        auto it = plugin->actionKeyMap.find(action);
        if (it == plugin->actionKeyMap.end()) {
            continue; // Skip if no key is mapped
        }

        const std::string& dkey = it->second;

        // Skip if the key has already been rendered
        if (renderedKeys.find(dkey) != renderedKeys.end()) {
            continue;
        }

        // Mark the key as rendered
        renderedKeys.insert(dkey);

        // Get original position for the key
        ImVec2 originalPos = plugin->actionPositions[action];
        float canvasScaleFactor = *overallScaleFactor;
        // Apply overall scaling and canvas position offset
        ImVec2 scaledPos(
            canvasOrigin.X + originalPos.x * canvasScaleFactor,
            canvasOrigin.Y + originalPos.y * canvasScaleFactor
        );

        // Update canvas position for this key
        canvas.SetPosition(Vector2F{ scaledPos.x, scaledPos.y });

        // Handle key press adjustment
        if (plugin->keyStates[key].pressed) {
            region.y += 131; // Shift Y by 131 pixels for the pressed texture
        }

        // Adjust the region dimensions based on scale
        float scaledWidth = (region.width / plugin->scaleFactor) * canvasScaleFactor;
        float scaledHeight = (region.height / plugin->scaleFactor) * canvasScaleFactor;

        // Render the key region from the scaled image
        canvas.DrawTile(
            plugin->keyboardImage.get(),
            scaledWidth,        // XL: Scaled width of the drawn region
            scaledHeight,       // YL: Scaled height of the drawn region
            region.x,           // U: X-coordinate of the source region
            region.y,           // V: Y-coordinate of the source region
            region.width,       // UL: Original width in the source image
            region.height,      // VL: Original height in the source image
            { 1, 1, 1, 1 },     // White tint
            0,                  // ClipTile
            1                   // Blend
        );
    }
}
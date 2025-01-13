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
    if (!(*enableOverlay)) return;

    // Draw the keys
    for (const auto& [key, position] : plugin->keyPositions) {
        Rect region = plugin->keyRegions[key];
        Vector2F scaledPos(
            (*canvasPosition).X + (position.x * (*overallScaleFactor)),
            (*canvasPosition).Y + (position.y * (*overallScaleFactor))
        );
        canvas.SetPosition(scaledPos);

        if (plugin->keyStates[key].pressed) {
            region.y += *offsetBy;
        }

        // Draw the key
        canvas.DrawTile(
            plugin->keyboardImage.get(),
            region.width / plugin->scaleFactor * (*overallScaleFactor),
            region.height / plugin->scaleFactor * (*overallScaleFactor),
            region.x, region.y,
            region.width, region.height,
            { 1, 1, 1, 1 }, 0, 1
        );
    }

    // Draw the action titles if enabled
    if (*enableActionTitles) {
        for (const auto& [action, position] : plugin->actionPositions) {
            if (plugin->actionTitles.find(action) == plugin->actionTitles.end()) {
                continue; // Skip actions without a valid title
            }

            Rect titleRect = plugin->actionTitles[action];
            Vector2F scaledTitlePos(
                (*canvasPosition).X + (position.x * (*overallScaleFactor)),
                (*canvasPosition).Y + (position.y * (*overallScaleFactor))
            );
            canvas.SetPosition(scaledTitlePos);
            canvas.DrawTile(
                plugin->keyboardImage.get(),
                titleRect.width / plugin->scaleFactor * (*overallScaleFactor),
                titleRect.height / plugin->scaleFactor * (*overallScaleFactor),
                titleRect.x, titleRect.y,
                titleRect.width, titleRect.height,
                { 1, 1, 1, 1 }, 0, 1
            );
        }
    }
}

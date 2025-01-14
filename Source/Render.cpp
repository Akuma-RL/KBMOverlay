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

    // Parent offsets and scaling
    Vector2F parentOffset(
        (*parentCanvasPosition).X,
        (*parentCanvasPosition).Y
    );

    float parentScale = *parentScaleFactor;

    // Draw the keyboard keys
    for (const auto& [key, position] : plugin->keyPositions) {

        // Skip mouse keys when rendering the keyboard canvas
        if (key == Mouse::ThumbMouseButton || key == Mouse::ThumbMouseButton2 ||
            key == Mouse::LeftMouseButton || key == Mouse::RightMouseButton ||
            key == Mouse::MouseScrollUp || key == Mouse::MouseScrollDown ||
            key == Mouse::MiddleMouseButton || key == Mouse::MouseX ||
            key == Mouse::MouseY || key == Mouse::Body) {
            continue;
        }
        Rect region = plugin->keyRegions[key];
        Vector2F scaledPos(
            parentOffset.X + ((*keyboardCanvasPosition).X + position.x * (*keyboardScaleFactor)) * parentScale,
            parentOffset.Y + ((*keyboardCanvasPosition).Y + position.y * (*keyboardScaleFactor)) * parentScale
        );
        canvas.SetPosition(scaledPos);

        if (plugin->keyStates[key].pressed) {
            region.y += *offsetBy;
        }

        // Draw the key
        canvas.DrawTile(
            plugin->keyboardImage.get(),
            region.width / plugin->scaleFactor * (*keyboardScaleFactor) * parentScale,
            region.height / plugin->scaleFactor * (*keyboardScaleFactor) * parentScale,
            region.x, region.y,
            region.width, region.height,
            { 1, 1, 1, 1 }, 0, 1
        );
    }

    // Draw the mouse overlay on its own canvas
    if (*gUseMouseOverlay) {
        for (const auto& [mouseKey, position] : plugin->keyPositions) {
            // Process only mouse keys
            if (mouseKey == Mouse::ThumbMouseButton || mouseKey == Mouse::ThumbMouseButton2 ||
                mouseKey == Mouse::LeftMouseButton || mouseKey == Mouse::RightMouseButton ||
                mouseKey == Mouse::MouseScrollUp || mouseKey == Mouse::MouseScrollDown ||
                mouseKey == Mouse::MiddleMouseButton || mouseKey == Mouse::MouseX ||
                mouseKey == Mouse::MouseY || mouseKey == Mouse::Body) {

                Rect region = plugin->keyRegions[mouseKey];
                Vector2F scaledMousePos(
                    parentOffset.X + ((*mouseCanvasPosition).X + position.x * (*mouseScaleFactor)) * parentScale,
                    parentOffset.Y + ((*mouseCanvasPosition).Y + position.y * (*mouseScaleFactor)) * parentScale
                );

                canvas.SetPosition(scaledMousePos);

                // Apply key-specific offsets based on the selected index
                ImVec2 offset = Assign::MouseKeyOffset(mouseKey, *gColorIndex);
                scaledMousePos.X += offset.x;
                scaledMousePos.Y += offset.y;

                if (plugin->keyStates[mouseKey].pressed) {
                    region.x += offset.x;
                    region.y += offset.y;
                }

                canvas.DrawTile(
                    plugin->keyboardImage.get(), // Same image as keyboard
                    region.width / plugin->scaleFactor * (*mouseScaleFactor) * parentScale,
                    region.height / plugin->scaleFactor * (*mouseScaleFactor) * parentScale,
                    region.x, region.y,
                    region.width, region.height,
                    { 1, 1, 1, 1 }, 0, 1
                );
            }
        }
    }
    
    // Draw the action titles if enabled
    if (*enableActionTitles) {
        for (const auto& [action, position] : plugin->actionPositions) {
            if (plugin->actionTitles.find(action) == plugin->actionTitles.end()) {
                continue; // Skip actions without a valid title
            }

            Rect titleRect = plugin->actionTitles[action];
            Vector2F scaledTitlePos(
                parentOffset.X + ((*keyboardCanvasPosition).X + position.x * (*keyboardScaleFactor)) * parentScale,
                parentOffset.Y + ((*keyboardCanvasPosition).Y + position.y * (*keyboardScaleFactor)) * parentScale
            );
            canvas.SetPosition(scaledTitlePos);
            canvas.DrawTile(
                plugin->keyboardImage.get(),
                titleRect.width / plugin->scaleFactor * (*keyboardScaleFactor) * parentScale,
                titleRect.height / plugin->scaleFactor * (*keyboardScaleFactor) * parentScale,
                titleRect.x, titleRect.y,
                titleRect.width, titleRect.height,
                { 1, 1, 1, 1 }, 0, 1
            );
        }
    }
}

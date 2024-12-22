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

void Render::OnKeyPressed(KBMOverlay* plugin, const std::string& rawKey) {
	std::string normalizedKey = Utils::NormalizeKey(rawKey);

	// Ensure the key exists in actionKeyMap to avoid unnecessary states
	if (std::find_if(plugin->actionKeyMap.begin(), plugin->actionKeyMap.end(),
		[&normalizedKey](const auto& pair) { return pair.second == normalizedKey; }) != plugin->actionKeyMap.end()) {
		plugin->keyStates[normalizedKey].pressed = true; // Set key's pressed to true
		LOG("[KBMOverlay] Key '{}' pressed.", normalizedKey);
	}
	else {
		LOG("[KBMOverlay] Key '{}' not mapped to any action; ignoring.", normalizedKey);
	}
}
void Render::OnKeyReleased(KBMOverlay* plugin, const std::string& key) {
	// Normalize key
	std::string normalizedKey = Utils::Trim(key);
	std::transform(normalizedKey.begin(), normalizedKey.end(), normalizedKey.begin(), ::tolower);

	// Set the key state to released
	plugin->keyStates[normalizedKey].pressed = false; // Set key's pressed to false
	LOG("[KBMOverlay] Key '{}' released.", normalizedKey);
}

void Render::RenderCanvas(KBMOverlay* plugin, CanvasWrapper& canvas) {

	if (!plugin->keyboardImage || !plugin->keyboardImage->IsLoadedForCanvas()) {
		LOG("[KBMOverlay] No image loaded for rendering.");
		return;
	}

	std::set<std::string> renderedKeys; // Track rendered keys

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
			//LOG("[KBMOverlay] Skipping duplicate key '{}'", dkey);
			continue;
		}

		// Mark the key as rendered
		renderedKeys.insert(dkey);

		ImVec2 pos = plugin->actionPositions[action]; // Screen position for the action

		//if (pos.x != 0 || pos.y != 0) {
		//	// Use `pos` for rendering
		//	LOG("[KBMOverlay] Rendering action '{}' at position ({}, {}).", action, pos.x, pos.y);
		//}
		// 
		// Check if the key is pressed and adjust the Y-position
		if (plugin->keyStates[key].pressed) {
			region.y += 131; // Shift Y by 131 pixels for the pressed texture
		}

		// Adjust the region to reflect the scaled image
		float scaledWidth = region.width / plugin->scaleFactor;
		float scaledHeight = region.height / plugin->scaleFactor;

		// Render the key region from the scaled image
		canvas.DrawTile(
			plugin->keyboardImage.get(),
			scaledWidth,		// XL: Width of the drawn region on the screen
			scaledHeight,		// YL: Height of the drawn region on the screen
			region.x,			// U: Scaled X-coordinate of the source region
			region.y,			// V: Scaled Y-coordinate of the source region
			region.width,		// UL: Original width in the source image
			region.height,		// VL: Original height in the source image
			{ 1, 1, 1, 1 },		// White tint
			0,					// ClipTile
			1					// Blend
		);
	}
}
#include "pch.h"
#include "KBMOverlay.h"
#include "Globals.h"
#include "Settings.h"
#include "Render.h"
#include "Config.h"
#include "Utils.h"

Render render;
Config cfg;

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

std::map<std::string, ImVec2> keyPositions;

// Plugin setup
BAKKESMOD_PLUGIN(KBMOverlay, "Keyboard & Mouse Overlay", plugin_version, PLUGINTYPE_FREEPLAY)

void KBMOverlay::onLoad() {
	_globalCvarManager = cvarManager;

	// Initialize screen size
	Vector2 screenSize = gameWrapper->GetScreenSize();
	*ScreenSize = Vector2(screenSize.X, screenSize.Y);

	RegisterCVAR();

	cfg.SetupConfigFile();
	cfg.LoadSettingsFromFile();
	cfg.ReloadBindsFromFile();

	// Initialize default layout
	UpdateLayout();

	Init::KeyStates(keyStates, gameWrapper.get());
	

	gameWrapper->HookEvent("Function Engine.GameViewportClient.Tick",
		std::bind(&KBMOverlay::onTick, this, std::placeholders::_1));

	SetImage();

	// Register canvas rendering
	gameWrapper->RegisterDrawable([this](CanvasWrapper canvas) {
		render.RenderCanvas(this, canvas);
		});

	LOG("[KBMOverlay] Plugin loaded.");
}

void KBMOverlay::SetImage() {
	// Construct the image path
	std::string imagePath = (gameWrapper->GetDataFolder() / "KBMOverlay" / "kbm.png").string();
	LOG("[KBMOverlay] Constructed image path: {}", imagePath);

	// Check if the image file exists
	if (!std::filesystem::exists(imagePath)) {
		LOG("[KBMOverlay] Image path does not exist: {}", imagePath);
		return;
	}

	keyboardImage = std::make_shared<ImageWrapper>(imagePath, true, false);
	keyboardImage->LoadForCanvas();

	if (!keyboardImage->IsLoadedForCanvas()) {
		LOG("[KBMOverlay] Failed to load keyboard image from: {}", imagePath);
		keyboardImage = nullptr; // Clear the pointer to avoid accidental use
		return;
	}
	if (!keyboardImage) {
		LOG("[KBMOverlay] No keyboard image; skipping rendering.");
		return;
	}
}

void KBMOverlay::UpdatePressedKeys() {
	pressedKeys.clear();

	for (auto& [key, keyState] : keyStates) {
		int keyIndex = keyState.index; // Use stored index to avoid redundant lookups
		bool isCurrentlyPressed = gameWrapper->IsKeyPressed(keyIndex);

		// Special handling for mouse keys
		if (key == Mouse::ThumbMouseButton || key == Mouse::ThumbMouseButton2 ||
			key == Mouse::LeftMouseButton || key == Mouse::RightMouseButton ||
			key == Mouse::MouseScrollUp || key == Mouse::MouseScrollDown ||
			key == Mouse::MiddleMouseButton || key == Mouse::MouseX ||
			key == Mouse::MouseY) {
			// Check mouse-specific input
			isCurrentlyPressed = gameWrapper->IsKeyPressed(keyIndex);
		}

		if (isCurrentlyPressed) {
			pressedKeys.insert(key); // Add key to pressed keys
			// Log the key and its state
			//LOG("[KBMOverlay] Key state updated: {} -> {}", key, isCurrentlyPressed ? "Pressed" : "Released");
		}

		// Update key state
		keyState.pressed = isCurrentlyPressed;
	}
}

void KBMOverlay::UpdateLayout() {
	// Clear previous mappings
	actionRegions.clear();
	actionPositions.clear();
	keyRegions.clear();
	actionTitles.clear();
	actionKeyMap.clear();
	mouseBinds.clear();
	keyPositions.clear();

	// Initialize positions and mappings
	Init::KeyRegions(keyRegions);
	Init::ActionTitles(actionTitles);
	Init::ActionKeyMap(actionKeyMap, mouseBinds);
	Init::KeyPositions(keyPositions);

	std::map<std::string, std::string> keyToActionMap; // Tracks which action is assigned to each key

	// Determine if the player is airborne
	bool isAirborne = Utils::IsPlayerAirborne(gameWrapper.get());

	for (const auto& [action, key] : actionKeyMap) {
		if (key.empty()) {
			continue; // Skip unbound actions
		}

		// Determine the key position
		auto keyPosIt = keyPositions.find(key);
		if (keyPosIt == keyPositions.end()) {
			continue; // Skip actions with keys not in the current layout
		}

	

		// Skip certain actions based on player state
		if (!isAirborne) {
			// Skip aerial actions while on the ground
			if (action == Action::PitchUp || action == Action::PitchDown ||
				action == Action::YawLeft || action == Action::YawRight || action == Action::ToggleRoll) {
				continue;
			}
		}
		else {
			// Skip ground-only actions while airborne
			if (action == Action::ThrottleForward && key != Key::Up || action == Action::ThrottleReverse && key != Key::Down ||
				action == Action::SteerLeft || action == Action::SteerRight || action == Action::Handbreak && key != Key::RControl) {
				continue;
			}
		}

		// Base key position
		ImVec2 keyPos = keyPosIt->second;

		// Apply custom offset
		ImVec2 offset = GetCustomOffset(key);

		// Calculate final title position
		ImVec2 titlePos;
		if (std::find(mouseBinds.begin(), mouseBinds.end(), key) != mouseBinds.end()) {
			// Use mouse canvas for mouse keys
			titlePos = {
				(*mouseCanvasPosition).X + keyPos.x * (*mouseScaleFactor) + offset.x * (*mouseScaleFactor),
				(*mouseCanvasPosition).Y + keyPos.y * (*mouseScaleFactor) + offset.y * (*mouseScaleFactor)
			};
		}
		else {
			// Use keyboard canvas for keyboard keys
			titlePos = {
				(*keyboardCanvasPosition).X + keyPos.x * (*keyboardScaleFactor) + offset.x * (*keyboardScaleFactor),
				(*keyboardCanvasPosition).Y + keyPos.y * (*keyboardScaleFactor) + offset.y * (*keyboardScaleFactor)
			};
		}

		// Assign to actionPositions
		actionPositions[action] = titlePos;
	}
}

void KBMOverlay::onTick(std::string eventName) {
	static int lastLayoutIndex = *gLayoutIndex;
	static bool wasAirborne = false;

	bool isCurrentlyAirborne = Utils::IsPlayerAirborne(gameWrapper.get());

	// Check if the layout index has changed
	if (*gLayoutIndex != lastLayoutIndex) {
		lastLayoutIndex = *gLayoutIndex;
		UpdateLayout(); // Update the layout dynamically
	}

	// Check if the airborne state has changed
	if (isCurrentlyAirborne != wasAirborne) {
		wasAirborne = isCurrentlyAirborne;
		UpdateLayout(); // Update the layout dynamically
	}

	// Update pressed key states
	UpdatePressedKeys();
}

void KBMOverlay::RegisterCVAR()
{
	cvarManager->registerCvar("kbm_enable_overlay", "1", "Enable the KBM overlay", true, true, 0, true, 1, true).bindTo(enableOverlay);
}

void KBMOverlay::RenderSettings() {
	settings.RenderSettings();
}

void KBMOverlay::onUnload()
{

}

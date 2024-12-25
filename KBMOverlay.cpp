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

// Plugin setup
BAKKESMOD_PLUGIN(KBMOverlay, "Keyboard & Mouse Overlay", plugin_version, PLUGINTYPE_FREEPLAY)

void KBMOverlay::onLoad() {
	_globalCvarManager = cvarManager;

	// Screen size initialization
	Vector2 screenSize = gameWrapper->GetScreenSize();
	*ScreenSize = Vector2F(screenSize.X, screenSize.Y);

	Init::ActionPositions(actionPositions);

	LOG("[KBMOverlay] Initialized actionPositions with default values:");
	for (const auto& [action, pos] : actionPositions) {
		LOG("Action: {}, Position: ({}, {})", action, pos.x, pos.y);
	}

	cfg.SetupConfigFile(); // Ensures reloadBindsFromFile is called

	Init::KeyStates(keyStates, gameWrapper.get());

	gameWrapper->HookEvent("Function Engine.GameViewportClient.Tick",
		std::bind(&KBMOverlay::onTick, this, std::placeholders::_1));

	// Initialize key regions and assign regions to actions
	Init::KeyRegions(keyRegions);
	Init::ActionKeyMap(actionKeyMap);

	Assign::ActionRegions(actionKeyMap, keyRegions, actionRegions);

	// Load keyboard image
	std::string imagePath = (gameWrapper->GetDataFolder() / "KBMOverlay" / "Keyboard" / "keyboard_red.png").string();
	LOG("[KBMOverlay] Attempting to load keyboard image from: {}", imagePath);
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

	LOG("[KBMOverlay] Keyboard image loaded successfully from: {}", imagePath);

	gameWrapper->RegisterDrawable([this](CanvasWrapper canvas)
		{
			render.RenderCanvas(this, canvas);
		});

	LOG("[KBMOverlay] Plugin loaded.");
}

void KBMOverlay::onTick(std::string eventName) {
	if (!gameWrapper->IsInCustomTraining()) {
		if (gameWrapper->IsInGame() || gameWrapper->IsInOnlineGame()) {
			for (auto& [key, keyState] : keyStates) {
				//LOG("[KBMOverlay] Checking Key '{}', fNameIndex: {}", key, keyState.index);

				// Check if the key is pressed
				bool isCurrentlyPressed = gameWrapper->IsKeyPressed(keyState.index);

				// Update and log state changes
				if (keyState.pressed != isCurrentlyPressed) {
					keyState.pressed = isCurrentlyPressed;
				}
			}
		}
	}
}

void KBMOverlay::RenderSettings() {
	settings.RenderSettings();
}

void KBMOverlay::onUnload()
{

}
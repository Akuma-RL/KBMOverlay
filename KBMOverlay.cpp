#include "pch.h"
#include "KBMOverlay.h"
#include "Keys.h"
#include "Globals.h"
#include "Settings.h"
#include "Render.h"
#include <fstream>
#include <filesystem>
#include <format>

namespace fs = std::filesystem;

Render render;

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

// Plugin setup
BAKKESMOD_PLUGIN(KBMOverlay, "Keyboard & Mouse Overlay", plugin_version, PLUGINTYPE_FREEPLAY)

void KBMOverlay::onLoad() {
	_globalCvarManager = cvarManager;

	Vector2 screenSize = gameWrapper->GetScreenSize();

	*ScreenSize = screenSize;

	SetupConfigFile(); // Ensures reloadBindsFromFile is called

	Init::KeyStates(keyStates, gameWrapper.get());

	gameWrapper->HookEvent("Function Engine.GameViewportClient.Tick",
		std::bind(&KBMOverlay::onTick, this, std::placeholders::_1));

	// Initialize key regions and assign regions to actions
	Init::KeyRegions(keyRegions);
	Init::ActionKeyMap(actionKeyMap);
	Assign::ActionRegions(actionKeyMap, keyRegions, actionRegions);

	// Load keyboard image
	std::string imagePath = (gameWrapper->GetDataFolder() / "keyboard.png").string();
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

	gameWrapper->HookEvent("InputPressed", [this](const std::string& eventName) {
		render.OnKeyPressed(this, eventName);
		});
	gameWrapper->HookEvent("InputReleased", [this](const std::string& eventName) {
		render.OnKeyReleased(this, eventName);
		});

	gameWrapper->RegisterDrawable([this](CanvasWrapper canvas)
		{
			render.RenderCanvas(this, canvas);
		});

	LOG("[KBMOverlay] Plugin loaded.");
}

void KBMOverlay::SetupConfigFile() {
	fs::path filePath(cfgFile);
	if (!fs::exists(filePath.parent_path())) {
		fs::create_directories(filePath.parent_path());
		LOG("No file exists in {}, generating one now", filePath.string());
	}

	if (!fs::exists(filePath)) {
		exportBindsToFile();
		LOG("Exporting binds to {}", filePath.string());
	}
	else {
		reloadBindsFromFile();
		LOG("Reloading binds from {}", filePath.string());
	}
}

// Function to export keybinds to a file
void KBMOverlay::exportBindsToFile() {
	// Get the current keybinds from the game
	SettingsWrapper settings = gameWrapper->GetSettings();

	std::ofstream file(cfgFile);
	if (file.is_open()) {
		for (const auto& bind : settings.GetAllPCBindings()) {
			const std::string& action = bind.second;
			const std::string& key = bind.first;

			// Check if the action is in the relevant set
			if (relevantActions.find(action) != relevantActions.end()) {
				file << "Action: " << action << " | Key: " << key << "\n";
				LOG("[KBMOverlay] Writing bind to file: Action: {}, Key: {}", action, key);
			}
		}
		file.close();
		LOG("[KBMOverlay] Keybinds exported to: {}", cfgFile);
	}
	else {
		LOG("[KBMOverlay] Failed to open file: {}", cfgFile);
	}
}

void KBMOverlay::reloadBindsFromFile() {
	std::ifstream file(cfgFile);
	if (!file.is_open()) {
		LOG("[KBMOverlay] Failed to open config file: {}", cfgFile);
		return;
	}

	LOG("[KBMOverlay] Reloading binds from config file: {}", cfgFile);

	std::string line;
	while (std::getline(file, line)) {
		//LOG("[KBMOverlay] Parsing line: {}", line);

		auto delimiter = line.find(" | Key: ");
		if (delimiter != std::string::npos) {
			std::string action = line.substr(8, delimiter - 8);
			std::string key = line.substr(delimiter + 8);

			if (!action.empty() && !key.empty()) {
				// Normalize the key
				std::string normalizedKey = Utils::Trim(key);
				std::transform(normalizedKey.begin(), normalizedKey.end(), normalizedKey.begin(), ::tolower);

				// Assign to relevant shared pointer based on the action
				if (action == Action::ThrottleForward) {
					*ForwardKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *ForwardKey);
				}
				else if (action == Action::ThrottleReverse) {
					*ReverseKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *ReverseKey);
				}
				else if (action == Action::SteerRight) {
					*SteerRKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *SteerRKey);
				}
				else if (action == Action::SteerLeft) {
					*SteerLKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *SteerLKey);
				}
				else if (action == Action::YawRight) {
					*YawRKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *YawRKey);
				}
				else if (action == Action::YawLeft) {
					*YawLKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *YawLKey);
				}
				else if (action == Action::PitchDown) {
					*PitchDownKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *PitchDownKey);
				}
				else if (action == Action::PitchUp) {
					*PitchUpKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *PitchUpKey);
				}
				else if (action == Action::RollRight) {
					*ARRKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *ARRKey);
				}
				else if (action == Action::RollLeft) {
					*ARLKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *ARLKey);
				}
				else if (action == Action::Boost) {
					*BoostKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *BoostKey);
				}
				else if (action == Action::Jump) {
					*JumpKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *JumpKey);
				}
				else if (action == Action::Handbreak) {
					*HandbreakKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *HandbreakKey);
				}
				else if (action == Action::SecondaryCamera) {
					*BallCamKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *BallCamKey);
				}
				else if (action == Action::ToggleRoll) {
					*FreeRollKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *FreeRollKey);
				}
				else if (action == Action::RearCamera) {
					*RearCamKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *RearCamKey);
				}
				else if (action == Action::ToggleScoreboard) {
					*ScoreboardKey = normalizedKey;
					//LOG("[KBMOverlay] {} mapped to key: {}", action, *ScoreboardKey);
				}
				else {
					LOG("[KBMOverlay] Skipping irrelevant Action '{}'", action);
				}

				// Add to actionKeyMap
				if (relevantActions.find(action) != relevantActions.end()) {
					actionKeyMap[action] = normalizedKey;
					//LOG("[KBMOverlay] Mapped Action '{}' to Key '{}'", action, normalizedKey);
				}
			}
		}
		else {
			LOG("[KBMOverlay] Line format incorrect: {}", line);
		}
	}

	file.close();

	// Filter the actionKeyMap to resolve conflicts and remove unbound actions
	Utils::FilterActionKeyMap(actionKeyMap);
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

					// Log key state change
					//LOG("[KBMOverlay] Key '{}' is now {}", key, isCurrentlyPressed ? "pressed" : "released");
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
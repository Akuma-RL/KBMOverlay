	#include "pch.h"
#include "Config.h"
#include "Tools/json.hpp"
#include <fstream>
#include <filesystem>
#include <format>
#include "KBMOverlay.h"
#include "Globals.h"
#include "Keys.h"

KBMOverlay kbm;

void Config::SetupConfigFile() {
	std::filesystem::path filePath(kbm.cfgFile);

	// Ensure the parent directory exists
	if (!std::filesystem::exists(filePath.parent_path())) {
		std::filesystem::create_directories(filePath.parent_path());
		LOG("[KBMOverlay] No directory exists in {}, generating it now.", filePath.parent_path().string());
	}

	// Always overwrite the config file with the latest binds
	LOG("[KBMOverlay] Overwriting or regenerating binds in {}", filePath.string());
	ExportBindsToFile();

	// Verify the file content after writing
	if (std::filesystem::exists(filePath)) {
		if (isConfigCorrupted(filePath)) {
			LOG("[KBMOverlay] Config file {} is corrupted after writing, regenerating.", filePath.string());
			ExportBindsToFile(); // Regenerate the config file
		}
		else {
			ReloadBindsFromFile(); // Reload binds if the file is valid
			LOG("[KBMOverlay] Reloading binds from {}", filePath.string());
		}
	}
	else {
		LOG("[KBMOverlay] Failed to write or find the config file: {}", filePath.string());
	}
}


void Config::ExportBindsToFile() {
	// Get the current keybinds from the game
	SettingsWrapper settings = kbm.gameWrapper->GetSettings();

	std::ofstream file(kbm.cfgFile);
	if (file.is_open()) {
		for (const auto& bind : settings.GetAllPCBindings()) {
			const std::string& action = bind.second;
			const std::string& key = bind.first;

			// Check if the action is in the relevant set
			if (relevantActions.find(action) != relevantActions.end()) {
				ImVec2 pos = kbm.actionPositions[action]; // Fetch the position for the action

				// Write action, key, and position to the file
				file << "Action: " << action
					<< " | Key: " << key
					<< " | Position: " << pos.x << "," << pos.y << "\n";
			}
		}
		file.close();
		LOG("[KBMOverlay] Keybinds exported to: {}", kbm.cfgFile);
	}
	else {
		LOG("[KBMOverlay] Failed to open file: {}", kbm.cfgFile);
	}
}

void Config::ReloadBindsFromFile() {
	std::ifstream file(kbm.cfgFile);
	if (!file.is_open()) {
		LOG("[KBMOverlay] Failed to open config file: {}", kbm.cfgFile);
		return;
	}

	LOG("[KBMOverlay] Reloading binds from config file: {}", kbm.cfgFile);

	std::string line;
	while (std::getline(file, line)) {
		// Find delimiters for parsing
		auto keyDelimiter = line.find(" | Key: ");
		auto posDelimiter = line.find(" | Position: ");
		if (keyDelimiter != std::string::npos && posDelimiter != std::string::npos) {
			// Extract parts of the line
			std::string action = line.substr(8, keyDelimiter - 8);
			std::string key = line.substr(keyDelimiter + 8, posDelimiter - (keyDelimiter + 8));

			// Suggested addition: Parse position
			auto actionPosDelimiter = line.find(" | Position: ");
			if (actionPosDelimiter != std::string::npos) {
				std::string position = line.substr(actionPosDelimiter + 12);
				try {
					int x = std::stoi(position.substr(0, position.find(',')));
					int y = std::stoi(position.substr(position.find(',') + 1));
					kbm.actionPositions[action] = ImVec2(x, y);
				}
				catch (const std::exception& e) {
					LOG("[KBMOverlay] Failed to parse position for action '{}': '{}'. Error: {}", action, position, e.what());
					continue;
				}
			}

			// Update key mappings
			kbm.actionKeyMap[action] = key;

			// Normalize the key
			std::string normalizedKey = Utils::Trim(key);
			std::transform(normalizedKey.begin(), normalizedKey.end(), normalizedKey.begin(), ::tolower);

			// Map normalized key to shared pointers for specific actions
			if (relevantActions.find(action) != relevantActions.end()) {

				if (action == Action::ThrottleForward) *ForwardKey = normalizedKey;
				else if (action == Action::ThrottleReverse) *ReverseKey = normalizedKey;

				else if (action == Action::SteerRight) *SteerRKey = normalizedKey;
				else if (action == Action::SteerLeft) *SteerLKey = normalizedKey;

				else if (action == Action::LookUp) *LookUpKey = normalizedKey;
				else if (action == Action::LookDown) *LookDownKey = normalizedKey;
				else if (action == Action::LookRight) *LookRightKey = normalizedKey;
				else if (action == Action::LookLeft) *LookLeftKey = normalizedKey;


				else if (action == Action::YawRight) *YawRKey = normalizedKey;
				else if (action == Action::YawLeft) *YawLKey = normalizedKey;

				else if (action == Action::PitchDown) *PitchDownKey = normalizedKey;
				else if (action == Action::PitchUp) *PitchUpKey = normalizedKey;

				else if (action == Action::RollRight) *ARRKey = normalizedKey;
				else if (action == Action::RollLeft) *ARLKey = normalizedKey;

				else if (action == Action::Boost) *BoostKey = normalizedKey;

				else if (action == Action::Jump) *JumpKey = normalizedKey;

				else if (action == Action::Handbreak) *HandbreakKey = normalizedKey;

				else if (action == Action::SecondaryCamera) *BallCamKey = normalizedKey;

				else if (action == Action::ToggleRoll) *FreeRollKey = normalizedKey;

				else if (action == Action::RearCamera) *RearCamKey = normalizedKey;

				else if (action == Action::UsePickup) *UsePickupKey = normalizedKey;

				else if (action == Action::NextPickup) *NextPickupKey = normalizedKey;

				else if (action == Action::Grab) *GrabKey = normalizedKey;

				else if (action == Action::ToggleMidGameMenu) *MenuKey = normalizedKey;

				else if (action == Action::ToggleScoreboard) *ScoreboardKey = normalizedKey;

				else if (action == Action::Chat) *ChatKey = normalizedKey;

				else if (action == Action::TeamChat) *TeamChatKey = normalizedKey;

				else if (action == Action::PartyChat) *PartyChatKey = normalizedKey;

				else if (action == Action::ChatPreset1) *ChatPreset1Key = normalizedKey;
				else if (action == Action::ChatPreset2) *ChatPreset2Key = normalizedKey;
				else if (action == Action::ChatPreset3) *ChatPreset3Key = normalizedKey;
				else if (action == Action::ChatPreset4) *ChatPreset4Key = normalizedKey;

				else if (action == Action::PushToTalk) *PushToTalkKey = normalizedKey;

				else if (action == Action::ResetTraining) *ResetTrainingKey = normalizedKey;
			}
		}
		else {
			LOG("[KBMOverlay] Malformed line in config: {}", line);
		}
	}

	file.close();
}

bool Config::isConfigCorrupted(const std::filesystem::path& filePath) {
	std::ifstream file(filePath);
	if (!file.is_open()) {
		LOG("Unable to open config file for corruption check: {}", filePath.string());
		return true; // Consider it corrupted if we can't open it
	}

	std::string line;
	while (std::getline(file, line)) {
		auto delimiter = line.find(" | Key: ");
		if (delimiter == std::string::npos) {
			LOG("Invalid line in config file: {}", line);
			return true; // If any line is invalid, consider it corrupted
		}

		std::string action = line.substr(8, delimiter - 8);
		std::string key = line.substr(delimiter + 8);

		if (action.empty() || key.empty()) {
			LOG("Malformed action or key in line: {}", line);
			return true; // Corruption if action or key is empty
		}
	}

	LOG("Config file passed corruption check: {}", filePath.string());
	return false; // File is not corrupted
}

void Config::SaveSettingsToFile() {
	std::filesystem::path filePath(kbm.settingsFile);

	nlohmann::json settingsJson;
	settingsJson["enableOverlay"] = *enableOverlay;
	settingsJson["enableActionTitles"] = *enableActionTitles;
	settingsJson["layoutIndex"] = *gLayoutIndex;
	settingsJson["colorIndex"] = *gColorIndex;
	settingsJson["parentScaleFactor"] = *parentScaleFactor;
	settingsJson["parentCanvasPosition"] = { (*parentCanvasPosition).X, (*parentCanvasPosition).Y };
	settingsJson["keyboardScaleFactor"] = *keyboardScaleFactor;
	settingsJson["keyboardCanvasPosition"] = { (*keyboardCanvasPosition).X, (*keyboardCanvasPosition).Y };
	settingsJson["mouseScaleFactor"] = *mouseScaleFactor;
	settingsJson["mouseCanvasPosition"] = { (*mouseCanvasPosition).X, (*mouseCanvasPosition).Y };


	std::ofstream file(filePath);
	if (file.is_open()) {
		file << settingsJson.dump(4); // Pretty-print with 4 spaces
		file.close();
		LOG("[KBMOverlay] Settings saved to: {}", filePath.string());
	}
	else {
		LOG("[KBMOverlay] Failed to open file for saving settings: {}", filePath.string());
	}
}

void Config::LoadSettingsFromFile() {
	std::filesystem::path filePath(kbm.settingsFile);

	if (!std::filesystem::exists(filePath)) {
		SaveSettingsToFile();
		return;
	}

	std::ifstream file(filePath);
	if (file.is_open()) {
		nlohmann::json settingsJson;
		file >> settingsJson;
		file.close();

		try {
			*enableOverlay = settingsJson["enableOverlay"].get<bool>();
			*enableActionTitles = settingsJson["enableActionTitles"].get<bool>();
			*gLayoutIndex = settingsJson["layoutIndex"].get<int>();
			*gColorIndex = settingsJson["colorIndex"].get<int>();
			*parentScaleFactor = settingsJson["parentScaleFactor"].get<float>();
			(*parentCanvasPosition).X = settingsJson["parentCanvasPosition"][0].get<float>();
			(*parentCanvasPosition).Y = settingsJson["parentCanvasPosition"][1].get<float>();
			*keyboardScaleFactor = settingsJson["keyboardScaleFactor"].get<float>();
			(*keyboardCanvasPosition).X = settingsJson["keyboardCanvasPosition"][0].get<float>();
			(*keyboardCanvasPosition).Y = settingsJson["keyboardCanvasPosition"][1].get<float>();
			*mouseScaleFactor = settingsJson["mouseScaleFactor"].get<float>();
			(*mouseCanvasPosition).X = settingsJson["mouseCanvasPosition"][0].get<float>();
			(*mouseCanvasPosition).Y = settingsJson["mouseCanvasPosition"][1].get<float>();

			LOG("[KBMOverlay] Settings loaded and applied from: {}", filePath.string());
		}
		catch (const std::exception& e) {
			LOG("[KBMOverlay] Failed to parse settings file: {}. Error: {}", filePath.string(), e.what());
		}
	}
	else {
		LOG("[KBMOverlay] Failed to open file for loading settings: {}", filePath.string());
	}
}

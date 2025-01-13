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
		LOG("No file exists in {}, generating one now", filePath.string());
	}
	// If the config file does not exist, generate it
	if (!std::filesystem::exists(filePath)) {
		ExportBindsToFile();
		LOG("Exporting binds to {}", filePath.string());
	}

	else {
		// Check if the config file is corrupted
		if (isConfigCorrupted(filePath)) {
			LOG("Config file {} is corrupted, regenerating.", filePath.string());
			ExportBindsToFile(); // Regenerate the config file
		}
		else {
			ReloadBindsFromFile(); // Reload binds if the file is valid
			LOG("Reloading binds from {}", filePath.string());
		}
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
	settingsJson["overallScaleFactor"] = *overallScaleFactor;
	settingsJson["canvasPosition"] = { (*canvasPosition).X, (*canvasPosition).Y };
	settingsJson["selectedIndex"] = *gSelectedIndex;

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
			*overallScaleFactor = settingsJson["overallScaleFactor"].get<float>();
			(*canvasPosition).X = settingsJson["canvasPosition"][0].get<float>();
			(*canvasPosition).Y = settingsJson["canvasPosition"][1].get<float>();
			*gSelectedIndex = settingsJson["selectedIndex"].get<int>();

			// Apply the loaded selectedIndex to update related settings
			switch (*gSelectedIndex) {
			case 0: *offsetBy = 131; break; // Red
			case 1: *offsetBy = 262; break; // Orange
			case 2: *offsetBy = 393; break; // Yellow
			case 3: *offsetBy = 524; break; // Green
			case 4: *offsetBy = 655; break; // Teal
			case 5: *offsetBy = 786; break; // Cyan
			case 6: *offsetBy = 917; break; // Blue
			case 7: *offsetBy = 1048; break; // Purple
			case 8: *offsetBy = 1179; break; // Pink
			case 9: *offsetBy = 1310; break; // Bubblegum
			case 10: *offsetBy = 1441; break; // Black
			case 11: *offsetBy = 1572; break; // Custom
			default: *offsetBy = 131; break; // Default
			}

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

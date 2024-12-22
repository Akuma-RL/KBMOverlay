#include "pch.h"
#include "Config.h"
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
		exportBindsToFile();
		LOG("Exporting binds to {}", filePath.string());
	}

	else {
		// Check if the config file is corrupted
		if (isConfigCorrupted(filePath)) {
			LOG("Config file {} is corrupted, regenerating.", filePath.string());
			exportBindsToFile(); // Regenerate the config file
		}
		else {
			reloadBindsFromFile(); // Reload binds if the file is valid
			LOG("Reloading binds from {}", filePath.string());
		}
	}
}

void Config::exportBindsToFile() {
	SettingsWrapper settings = kbm.gameWrapper->GetSettings();

	std::ofstream file(kbm.cfgFile);
	if (file.is_open()) {
		for (const auto& bind : settings.GetAllPCBindings()) {
			const std::string& action = bind.second;
			const std::string& key = bind.first;

			// Check if the action is relevant
			if (relevantActions.find(action) != relevantActions.end()) {
				ImVec2 pos = kbm.actionPositions[action]; // Fetch position for the action
				file << "Action: " << action
					<< " | Key: " << key
					<< " | Position: " << pos.x << "," << pos.y << "\n";

				LOG("[KBMOverlay] Writing bind to file: Action: {}, Key: {}, Position: {},{}",
					action, key, pos.x, pos.y);
			}
		}
		file.close();
		LOG("[KBMOverlay] Keybinds exported to: {}", kbm.cfgFile);
	}
	else {
		LOG("[KBMOverlay] Failed to open file: {}", kbm.cfgFile);
	}
}

void Config::reloadBindsFromFile() {
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
			std::string posStr = line.substr(posDelimiter + 13);

			// Parse position
			float posX = 0.0f, posY = 0.0f;
			if (sscanf(posStr.c_str(), "%f,%f", &posX, &posY) != 2) {
				LOG("[KBMOverlay] Failed to parse position for action '{}': '{}'", action, posStr);
				continue;
			}

			// Update positions and key mappings
			kbm.actionPositions[action] = ImVec2(posX, posY);
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
				else if (action == Action::ToggleScoreboard) *ScoreboardKey = normalizedKey;

				LOG("[KBMOverlay] Mapped Action '{}' to Key '{}' at Position ({}, {}).", action, normalizedKey, posX, posY);
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
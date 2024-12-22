#pragma once

#include <string>
#include <map>
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/wrappers/ImageWrapper.h"
#include "Utils.h"

// Forward declaration of Rect
struct Rect;

struct KeyState {
	int index;      // Virtual key index/code
	bool pressed;   // Is the key pressed
};

// Functions for initializing key maps
namespace Init {
	void ActionPositions(std::map<std::string, ImVec2>& actionPositions);
	void ActionKeyMap(std::map<std::string, std::string>& actionKeyMap);
	void KeyRegions(std::map<std::string, Rect>& keyRegions);
	void KeyStates(std::map<std::string, KeyState>& keyStates, GameWrapper* gameWrapper);
}

namespace Assign {
	// Function to dynamically assign key regions to actions 
	void ActionRegions(
		const std::map<std::string, std::string>& actionKeyMap,		// Action-to-key map
		const std::map<std::string, Rect>& keyRegions,				// Key-to-region map
		std::map<std::string, std::shared_ptr<Rect>>& actionRegions // Output: Action-to-region map
	);
}
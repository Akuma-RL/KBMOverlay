#pragma once

#include <string>
#include <map>
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/wrappers/ImageWrapper.h"
#include "Utils.h"

// Forward declaration of Rect
struct Rect;


extern std::map<std::string, ImVec2> keyPositions;

struct KeyState {
	int index;      // Virtual key index/code
	bool pressed;   // Is the key pressed
};

// Functions for initializing key maps
namespace Init {
	void ActionKeyMap(std::map<std::string, std::string>& actionKeyMap, std::vector<std::string>& mouseBinds);
	void KeyRegions(std::map<std::string, Rect>& keyRegions);
	void KeyStates(std::map<std::string, KeyState>& keyStates, GameWrapper* gameWrapper);
    void KeyPositions(std::map<std::string, ImVec2>& keyPositions);
	void ActionTitles(std::map<std::string, Rect>& actionTitles);
}

namespace Assign {
    void KeyboardActionRegions(
        const std::map<std::string, std::string>& actionKeyMap,
        const std::map<std::string, Rect>& keyRegions,
        std::map<std::string, std::shared_ptr<Rect>>& actionRegions
    );
	ImVec2 KeyboardKeyOffset(int selectedIndex);

	ImVec2 MouseKeyOffset(const std::string& key, int selectedIndex);

}

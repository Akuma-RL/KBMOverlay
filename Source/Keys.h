#pragma once

#include <string>
#include <map>
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/wrappers/ImageWrapper.h"
#include "Utils.h"

// Forward declaration of Rect
struct Rect;

enum class ProfileType {
    FullKeyboard,
    Recommended
};

struct Profile {
    ProfileType type;
    std::map<std::string, ImVec2> actionPositions; // Positions for actions (layout-specific)
};

extern std::map<std::string, ImVec2> keyPositions;

struct KeyState {
	int index;      // Virtual key index/code
	bool pressed;   // Is the key pressed
};

// Functions for initializing key maps
namespace Init {
	void MouseActionPositions(std::map<std::string, ImVec2>& mouseActionPositions);
	void ActionPositions(std::map<std::string, ImVec2>& actionPositions);
	void ActionKeyMap(std::map<std::string, std::string>& actionKeyMap);
	void MouseKeyRegions(std::map<std::string, Rect>& mouseKeyRegions);
	void KeyRegions(std::map<std::string, Rect>& keyRegions);
	void KeyStates(std::map<std::string, KeyState>& keyStates, GameWrapper* gameWrapper);
    void Profiles();
    void KeyPositions(std::map<std::string, ImVec2>& keyPositions);
}

namespace Assign {
    void KeyboardActionRegions(
        const std::map<std::string, std::string>& actionKeyMap,
        const std::map<std::string, Rect>& keyRegions,
        std::map<std::string, std::shared_ptr<Rect>>& actionRegions
    );

    void MouseActionRegions(
        const std::map<std::string, std::string>& actionKeyMap,
        const std::map<std::string, Rect>& mouseKeyRegions,
        std::map<std::string, std::shared_ptr<Rect>>& mouseActionRegions
    );
}

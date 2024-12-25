#include "pch.h"
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include <chrono>
#include "Utils.h"
#include <algorithm>

// Define conflicting action priorities
const std::map<std::string, std::string> Utils::conflictingActions = {
    { Action::YawLeft, Action::SteerLeft },
    { Action::YawRight, Action::SteerRight },
    { Action::PitchUp, Action::ThrottleReverse },
    { Action::PitchDown, Action::ThrottleForward }
};

std::string Utils::Trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}
std::string Utils::NormalizeKey(const std::string& key) {
    std::string normalizedKey = key;
    normalizedKey = Trim(normalizedKey); // Remove leading/trailing whitespace
    std::transform(normalizedKey.begin(), normalizedKey.end(), normalizedKey.begin(), ::tolower); // Convert to lowercase
    return normalizedKey;
}

// Filter actionKeyMap to handle unbound and conflicting keys
void Utils::FilterActionKeyMap(std::map<std::string, std::string>& actionKeyMap) {
    std::set<std::string> usedKeys;
    std::vector<std::string> toRemove;

    for (auto& [action, key] : actionKeyMap) {
        if (key == "None") {
            // Disregard unbound actions
            toRemove.push_back(action);
            continue;
        }

        if (usedKeys.find(key) != usedKeys.end()) {
            // Key conflict detected; prioritize higher-priority action
            auto conflict = conflictingActions.find(action);
            if (conflict != conflictingActions.end() && actionKeyMap[conflict->second] == key) {
                // This action loses priority; mark it for removal
                toRemove.push_back(action);
            }
            else {
                // This action wins; remove conflicting lower-priority action
                auto it = std::find_if(toRemove.begin(), toRemove.end(), [&key, &actionKeyMap](const std::string& act) {
                    return actionKeyMap[act] == key;
                    });
                if (it != toRemove.end()) {
                    toRemove.erase(it);
                }
                auto conflictingAction = conflictingActions.find(action);
                if (conflictingAction != conflictingActions.end()) {
                    toRemove.push_back(conflictingAction->second);
                }
            }
        }
        else {
            // No conflict; mark key as used
            usedKeys.insert(key);
        }
    }

    // Remove unbound and conflicting actions from actionKeyMap
    for (const auto& action : toRemove) {
        actionKeyMap.erase(action);
    }
}

// Define the relevant actions
const std::unordered_set<std::string> relevantActions = {
   Action::ThrottleForward,
    Action::ThrottleReverse,

    Action::SteerRight,
    Action::SteerLeft,

    Action::LookUp,
    Action::LookDown,
    Action::LookRight,
    Action::LookLeft,

    Action::YawRight,
    Action::YawLeft,

    Action::PitchUp,
    Action::PitchDown,

    Action::RollRight,
    Action::RollLeft,

    Action::Boost,

    Action::Jump,

    Action::Handbreak,

    Action::SecondaryCamera,

    Action::ToggleRoll,

    Action::RearCamera,

    Action::ToggleScoreboard,

    Action::UsePickup,

    Action::NextPickup,

    Action::Grab,

    Action::ToggleMidGameMenu,

    Action::ToggleScoreboard,

    Action::Chat,

    Action::TeamChat,

    Action::PartyChat,

    Action::ChatPreset1,
    Action::ChatPreset2,
    Action::ChatPreset3,
    Action::ChatPreset4,

    Action::PushToTalk,

    Action::ResetTraining
};
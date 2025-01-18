#pragma once
#include <unordered_set>
#include <set>
#include "Keys.h"
#include "Globals.h"
#include <fstream>
#include <filesystem>


// Forward declaration of KeyState
struct KeyState;

// Define a Rect struct to store pixel regions for keys
struct Rect {
	float x, y, width, height;
};

namespace Utils
{
	std::string Trim(const std::string& str);
	std::string Normalize(const std::string& key);

	extern const std::map<std::string, std::string> conflictingActions;
	void FilterActionKeyMap(std::map<std::string, std::string>& actionKeyMap);
	bool IsPlayerAirborne(GameWrapper* gameWrapper);
};

// Make relevant actions globally accessible
extern const std::unordered_set<std::string> relevantActions;

namespace Action {
	constexpr auto ThrottleForward = "ThrottleForward";
	constexpr auto ThrottleReverse = "ThrottleReverse";

	constexpr auto SteerRight = "SteerRight";
	constexpr auto SteerLeft = "SteerLeft";

	constexpr auto LookUp = "SwivelUp";
	constexpr auto LookDown = "SwivelDown";
	constexpr auto LookRight = "SwivelRight";
	constexpr auto LookLeft = "SwivelLeft";

	constexpr auto YawRight = "YawRight";
	constexpr auto YawLeft = "YawLeft";

	constexpr auto PitchUp = "PitchUp";
	constexpr auto PitchDown = "PitchDown";

	constexpr auto RollRight = "RollRight";
	constexpr auto RollLeft = "RollLeft";

	constexpr auto Boost = "Boost";

	constexpr auto Jump = "Jump";

	constexpr auto Handbreak = "Handbrake";

	constexpr auto SecondaryCamera = "SecondaryCamera";

	constexpr auto ToggleRoll = "ToggleRoll";

	constexpr auto RearCamera = "RearCamera";

	constexpr auto UsePickup = "UsePickup";

	constexpr auto NextPickup = "NextPickup";

	//constexpr auto Grab = "Grab";

	constexpr auto ToggleMidGameMenu = "ToggleMidGameMenu";

	constexpr auto ToggleScoreboard = "ToggleScoreboard";

	constexpr auto Chat = "Chat";

	constexpr auto TeamChat = "TeamChat";

	constexpr auto PartyChat = "PartyChat";

	constexpr auto ChatPreset1 = "ChatPreset1";
	constexpr auto ChatPreset2 = "ChatPreset2";
	constexpr auto ChatPreset3 = "ChatPreset3";
	constexpr auto ChatPreset4 = "ChatPreset4";

	constexpr auto PushToTalk = "PushToTalk";

	constexpr auto ResetTraining = "ResetTraining";
}

namespace Mouse {

	// Aesthetic maps

	constexpr auto Body = "body";

	// Mouse binds
	constexpr auto MouseX = "mousex";
	constexpr auto MouseY = "mousey";

	constexpr auto ThumbMouseButton2 = "thumbmousebutton2"; // front button
	constexpr auto ThumbMouseButton = "thumbmousebutton"; // back button

	constexpr auto LeftMouseButton = "leftmousebutton";
	constexpr auto RightMouseButton = "rightmousebutton";

	constexpr auto MouseScrollUp = "mousescrollup";
	constexpr auto MouseScrollDown = "mousescrolldown";

	constexpr auto MiddleMouseButton = "middlemousebutton";

}

namespace Key {
	// Escape row
	constexpr auto Escape = "escape";
	constexpr auto F1 = "f1";
	constexpr auto F2 = "f2";
	constexpr auto F3 = "f3";
	constexpr auto F4 = "f4";
	constexpr auto F5 = "f5";
	constexpr auto F6 = "f6";
	constexpr auto F7 = "f7";
	constexpr auto F8 = "f8";
	constexpr auto F9 = "f9";
	constexpr auto F10 = "f10";
	constexpr auto F11 = "f11";
	constexpr auto F12 = "f12";
	constexpr auto PrintScreen = "printscreen";
	constexpr auto Pause = "pause";
	constexpr auto Delete = "delete";

	// ~ row
	constexpr auto Tilde = "tilde";
	constexpr auto One = "one";
	constexpr auto Two = "two";
	constexpr auto Three = "three";
	constexpr auto Four = "four";
	constexpr auto Five = "five";
	constexpr auto Six = "six";
	constexpr auto Seven = "seven";
	constexpr auto Eight = "eight";
	constexpr auto Nine = "nine";
	constexpr auto Zero = "zero";
	constexpr auto Minus = "underscore";
	constexpr auto Equals = "equals";
	constexpr auto Backspace = "backspace";
	constexpr auto Home = "home";

	// Tab row
	constexpr auto Tab = "tab";
	constexpr auto Q = "q";
	constexpr auto W = "w";
	constexpr auto E = "e";
	constexpr auto R = "r";
	constexpr auto T = "t";
	constexpr auto Y = "y";
	constexpr auto U = "u";
	constexpr auto I = "i";
	constexpr auto O = "o";
	constexpr auto P = "p";
	constexpr auto LBracket = "leftbracket";
	constexpr auto RBracket = "rightbracket";
	constexpr auto Backslash = "backslash";
	constexpr auto PageUp = "pageup";

	// Caps Lock row
	constexpr auto CapsLock = "capslock";
	constexpr auto A = "a";
	constexpr auto S = "s";
	constexpr auto D = "d";
	constexpr auto F = "f";
	constexpr auto G = "g";
	constexpr auto H = "h";
	constexpr auto J = "j";
	constexpr auto K = "k";
	constexpr auto L = "l";
	constexpr auto Semicolon = "semicolon";
	constexpr auto Quote = "quote";
	constexpr auto Enter = "enter";
	constexpr auto PageDown = "pagedown";

	// Shift row
	constexpr auto LShift = "leftshift";
	constexpr auto Z = "z";
	constexpr auto X = "x";
	constexpr auto C = "c";
	constexpr auto V = "v";
	constexpr auto B = "b";
	constexpr auto N = "n";
	constexpr auto M = "m";
	constexpr auto Comma = "comma";
	constexpr auto Period = "period";
	constexpr auto Forwardslash = "slash";
	constexpr auto RShift = "rightshift";
	constexpr auto Up = "up";
	constexpr auto End = "end";

	// Control row
	constexpr auto LControl = "leftcontrol";
	constexpr auto Windows = "win";
	constexpr auto LAlt = "leftalt";
	constexpr auto Spacebar = "spacebar";
	constexpr auto RAlt = "rightalt";
	constexpr auto Function = "function";
	constexpr auto RControl = "rightcontrol";
	constexpr auto Left = "left";
	constexpr auto Down = "down";
	constexpr auto Right = "right";
}

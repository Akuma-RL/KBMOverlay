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
	std::string NormalizeKey(const std::string& key);

	extern const std::map<std::string, std::string> conflictingActions;
	void FilterActionKeyMap(std::map<std::string, std::string>& actionKeyMap);


	void CleanupKeyStates(std::map<std::string, KeyState>& keyStates);
	static void LogKeyStates(const std::map<std::string, KeyState>& keyStates);
};

// Make relevant actions globally accessible
extern const std::unordered_set<std::string> relevantActions;

namespace Action {
	constexpr auto ThrottleForward = "ThrottleForward";
	constexpr auto ThrottleReverse = "ThrottleReverse";
	constexpr auto SteerRight = "SteerRight";
	constexpr auto SteerLeft = "SteerLeft";
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
	constexpr auto ToggleScoreboard = "ToggleScoreboard";
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
	constexpr auto Tilde = "";
	constexpr auto One = "1";
	constexpr auto Two = "2";
	constexpr auto Three = "3";
	constexpr auto Four = "4";
	constexpr auto Five = "5";
	constexpr auto Six = "6";
	constexpr auto Seven = "7";
	constexpr auto Eight = "8";
	constexpr auto Nine = "9";
	constexpr auto Zero = "0";
	constexpr auto Minus = "minus";
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
	constexpr auto LBracket = "[";
	constexpr auto RBracket = "]";
	constexpr auto Backslash = "";
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
	constexpr auto Quote = "'";
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
	constexpr auto Comma = "";
	constexpr auto Period = "";
	constexpr auto Forwardslash = "/";
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
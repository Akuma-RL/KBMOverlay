#include "pch.h"
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "KBMOverlay.h"
#include "Keys.h"
#include "Globals.h"

KBMOverlay kbmo;

std::map<std::string, ImVec2> keyPositions;

void Init::ActionPositions(std::map<std::string, ImVec2>& actionPositions) {
	//actionPositions[Action::ThrottleForward] = ImVec2(925, 260);
	//actionPositions[Action::ThrottleReverse] = ImVec2(925, 325);

	//actionPositions[Action::SteerRight] = ImVec2(275, 195);
	//actionPositions[Action::SteerLeft] = ImVec2(145, 195);

	//actionPositions[Action::LookUp] = ImVec2(535, 260);
	//actionPositions[Action::LookDown] = ImVec2(535, 325);
	//actionPositions[Action::LookRight] = ImVec2(600, 325);
	//actionPositions[Action::LookLeft] = ImVec2(470, 325);

	//actionPositions[Action::YawRight] = ImVec2(275, 195);
	//actionPositions[Action::YawLeft] = ImVec2(145, 195);

	//actionPositions[Action::PitchDown] = ImVec2(210, 130);
	//actionPositions[Action::PitchUp] = ImVec2(210, 195);

	//actionPositions[Action::RollRight] = ImVec2(275, 130);
	//actionPositions[Action::RollLeft] = ImVec2(145, 130);

	//actionPositions[Action::Boost] = ImVec2(990, 325);

	//actionPositions[Action::Jump] = ImVec2(860, 325);

	//actionPositions[Action::Handbreak] = ImVec2(795, 325);

	//actionPositions[Action::SecondaryCamera] = ImVec2(210, 325);

	//actionPositions[Action::ToggleRoll] = ImVec2(0, 260);

	//actionPositions[Action::RearCamera] = ImVec2(0, 325);

	//actionPositions[Action::UsePickup] = ImVec2(340, 130);
	//actionPositions[Action::NextPickup] = ImVec2(275, 260);
	//actionPositions[Action::Grab] = ImVec2(0, 260);

	//actionPositions[Action::ToggleMidGameMenu] = ImVec2(0, 0);
	//actionPositions[Action::ToggleScoreboard] = ImVec2(0, 130);

	//actionPositions[Action::Chat] = ImVec2(405, 130);
	//actionPositions[Action::TeamChat] = ImVec2(470, 130);
	//actionPositions[Action::PartyChat] = ImVec2(535, 130);


	//actionPositions[Action::ChatPreset1] = ImVec2(145, 65);
	//actionPositions[Action::ChatPreset2] = ImVec2(210, 65);
	//actionPositions[Action::ChatPreset3] = ImVec2(275, 65);
	//actionPositions[Action::ChatPreset4] = ImVec2(340, 65);

	//actionPositions[Action::PushToTalk] = ImVec2(340, 195);

	//actionPositions[Action::ResetTraining] = ImVec2(795, 65);

	actionPositions[Action::ThrottleForward] = ImVec2(480, 65);
	actionPositions[Action::ThrottleReverse] = ImVec2(470, 130);
	actionPositions[Action::SteerRight] = ImVec2(275, 65);
	actionPositions[Action::SteerLeft] = ImVec2(145, 65);
	actionPositions[Action::YawRight] = ImVec2(275, 65);
	actionPositions[Action::YawLeft] = ImVec2(145, 65);
	actionPositions[Action::PitchDown] = ImVec2(210, 0);
	actionPositions[Action::PitchUp] = ImVec2(210, 65);
	actionPositions[Action::RollRight] = ImVec2(275, 0);
	actionPositions[Action::RollLeft] = ImVec2(145, 0);
	actionPositions[Action::Boost] = ImVec2(535, 130);
	actionPositions[Action::Jump] = ImVec2(405, 130);
	actionPositions[Action::Handbreak] = ImVec2(265, 130);
	actionPositions[Action::SecondaryCamera] = ImVec2(65, 130);
	actionPositions[Action::ToggleRoll] = ImVec2(0, 130);
	actionPositions[Action::RearCamera] = ImVec2(0, 130);
	actionPositions[Action::ToggleScoreboard] = ImVec2(0, 0);
}

void Init::KeyPositions(std::map<std::string, ImVec2>& keyPositions) {
	if (*gLayoutIndex == 0) {
		Init::ActionPositions(kbmo.actionPositions);
	}
	if (*gLayoutIndex == 1) {
		// Escape row
		keyPositions[Key::Escape] = ImVec2(0, 0);
		keyPositions[Key::F1] = ImVec2(65, 0);
		keyPositions[Key::F2] = ImVec2(130, 0);
		keyPositions[Key::F3] = ImVec2(195, 0);
		keyPositions[Key::F4] = ImVec2(260, 0);
		keyPositions[Key::F5] = ImVec2(320, 0);
		keyPositions[Key::F6] = ImVec2(385, 0);
		keyPositions[Key::F7] = ImVec2(450, 0);
		keyPositions[Key::F8] = ImVec2(515, 0);
		keyPositions[Key::F9] = ImVec2(580, 0);
		keyPositions[Key::F10] = ImVec2(645, 0);
		keyPositions[Key::F11] = ImVec2(710, 0);
		keyPositions[Key::F12] = ImVec2(775, 0);
		keyPositions[Key::PrintScreen] = ImVec2(840, 0);
		keyPositions[Key::Pause] = ImVec2(905, 0);
		keyPositions[Key::Delete] = ImVec2(970, 0);

		// ~ row
		keyPositions[Key::Tilde] = ImVec2(0, 65);
		keyPositions[Key::One] = ImVec2(65, 65);
		keyPositions[Key::Two] = ImVec2(130, 65);
		keyPositions[Key::Three] = ImVec2(195, 65);
		keyPositions[Key::Four] = ImVec2(260, 65);
		keyPositions[Key::Five] = ImVec2(325, 65);
		keyPositions[Key::Six] = ImVec2(390, 65);
		keyPositions[Key::Seven] = ImVec2(455, 65);
		keyPositions[Key::Eight] = ImVec2(520, 65);
		keyPositions[Key::Nine] = ImVec2(585, 65);
		keyPositions[Key::Zero] = ImVec2(650, 65);
		keyPositions[Key::Minus] = ImVec2(715, 65);
		keyPositions[Key::Equals] = ImVec2(780, 65);
		keyPositions[Key::Backspace] = ImVec2(845, 65);;
		keyPositions[Key::Home] = ImVec2(990, 65);

		// Tab row
		keyPositions[Key::Tab] = ImVec2(0, 130);
		keyPositions[Key::Q] = ImVec2(145, 130);
		keyPositions[Key::W] = ImVec2(210, 130);
		keyPositions[Key::E] = ImVec2(275, 130);
		keyPositions[Key::R] = ImVec2(340, 130);
		keyPositions[Key::T] = ImVec2(405, 130);
		keyPositions[Key::Y] = ImVec2(470, 130);
		keyPositions[Key::U] = ImVec2(535, 130);
		keyPositions[Key::I] = ImVec2(600, 130);
		keyPositions[Key::O] = ImVec2(665, 130);
		keyPositions[Key::P] = ImVec2(730, 130);
		keyPositions[Key::LBracket] = ImVec2(795, 130);
		keyPositions[Key::RBracket] = ImVec2(860, 130);
		keyPositions[Key::Backslash] = ImVec2(925, 130);
		keyPositions[Key::PageUp] = ImVec2(990, 130);

		//Caps Lock row
		keyPositions[Key::CapsLock] = ImVec2(0, 195);
		keyPositions[Key::A] = ImVec2(145, 195);
		keyPositions[Key::S] = ImVec2(210, 195);
		keyPositions[Key::D] = ImVec2(275, 195);
		keyPositions[Key::F] = ImVec2(340, 195);
		keyPositions[Key::G] = ImVec2(405, 195);
		keyPositions[Key::H] = ImVec2(470, 195);
		keyPositions[Key::J] = ImVec2(535, 195);
		keyPositions[Key::K] = ImVec2(600, 195);
		keyPositions[Key::L] = ImVec2(665, 195);
		keyPositions[Key::Semicolon] = ImVec2(730, 195);
		keyPositions[Key::Quote] = ImVec2(795, 195);
		keyPositions[Key::Enter] = ImVec2(860, 195);
		keyPositions[Key::PageDown] = ImVec2(1005, 195);

		// Shift row
		keyPositions[Key::LShift] = ImVec2(0, 260);
		keyPositions[Key::Z] = ImVec2(145, 260);
		keyPositions[Key::X] = ImVec2(210, 260);
		keyPositions[Key::C] = ImVec2(275, 260);
		keyPositions[Key::V] = ImVec2(340, 260);
		keyPositions[Key::B] = ImVec2(405, 260);
		keyPositions[Key::N] = ImVec2(470, 260);
		keyPositions[Key::M] = ImVec2(535, 260);
		keyPositions[Key::Comma] = ImVec2(600, 260);
		keyPositions[Key::Period] = ImVec2(665, 260);
		keyPositions[Key::Forwardslash] = ImVec2(730, 260);
		keyPositions[Key::RShift] = ImVec2(795, 260);
		keyPositions[Key::Up] = ImVec2(940, 260);
		keyPositions[Key::End] = ImVec2(1005, 260);

		// Control row
		keyPositions[Key::LControl] = ImVec2(0, 325);
		keyPositions[Key::Windows] = ImVec2(65, 325);
		keyPositions[Key::LAlt] = ImVec2(145, 325);
		keyPositions[Key::Spacebar] = ImVec2(210, 325);
		keyPositions[Key::RAlt] = ImVec2(405, 325);
		keyPositions[Key::Function] = ImVec2(470, 325);
		keyPositions[Key::RControl] = ImVec2(535, 325);
		keyPositions[Key::Left] = ImVec2(860, 325);
		keyPositions[Key::Down] = ImVec2(925, 325);
		keyPositions[Key::Right] = ImVec2(990, 325);
	}

	if (*gLayoutIndex == 2) {
		// Escape row
		keyPositions[Key::Escape] = ImVec2(0, 0);
		keyPositions[Key::F1] = ImVec2(65, 0);
		keyPositions[Key::F2] = ImVec2(130, 0);
		keyPositions[Key::F3] = ImVec2(195, 0);
		keyPositions[Key::F4] = ImVec2(260, 0);
		keyPositions[Key::F5] = ImVec2(320, 0);
		keyPositions[Key::F6] = ImVec2(385, 0);
		keyPositions[Key::F7] = ImVec2(450, 0);
		keyPositions[Key::F8] = ImVec2(515, 0);
		keyPositions[Key::F9] = ImVec2(580, 0);
		keyPositions[Key::F10] = ImVec2(645, 0);
		keyPositions[Key::F11] = ImVec2(710, 0);
		keyPositions[Key::F12] = ImVec2(775, 0);
		keyPositions[Key::PrintScreen] = ImVec2(840, 0);
		keyPositions[Key::Pause] = ImVec2(905, 0);
		keyPositions[Key::Delete] = ImVec2(970, 0);

		// ~ row
		keyPositions[Key::Tilde] = ImVec2(0, 65);
		keyPositions[Key::One] = ImVec2(65, 65);
		keyPositions[Key::Two] = ImVec2(130, 65);
		keyPositions[Key::Three] = ImVec2(195, 65);
		keyPositions[Key::Four] = ImVec2(260, 65);
		keyPositions[Key::Five] = ImVec2(325, 65);
		keyPositions[Key::Six] = ImVec2(390, 65);
		keyPositions[Key::Seven] = ImVec2(455, 65);
		keyPositions[Key::Eight] = ImVec2(520, 65);
		keyPositions[Key::Nine] = ImVec2(585, 65);
		keyPositions[Key::Zero] = ImVec2(650, 65);
		keyPositions[Key::Minus] = ImVec2(715, 65);
		keyPositions[Key::Equals] = ImVec2(780, 65);
		keyPositions[Key::Backspace] = ImVec2(845, 65);;
		keyPositions[Key::Home] = ImVec2(990, 65);

		// Tab row
		keyPositions[Key::Tab] = ImVec2(0, 130);
		keyPositions[Key::Q] = ImVec2(145, 130);
		keyPositions[Key::W] = ImVec2(210, 130);
		keyPositions[Key::E] = ImVec2(275, 130);
		keyPositions[Key::R] = ImVec2(340, 130);
		keyPositions[Key::T] = ImVec2(405, 130);
		keyPositions[Key::Y] = ImVec2(470, 130);
		keyPositions[Key::U] = ImVec2(535, 130);
		keyPositions[Key::I] = ImVec2(600, 130);
		keyPositions[Key::O] = ImVec2(665, 130);
		keyPositions[Key::P] = ImVec2(730, 130);
		keyPositions[Key::LBracket] = ImVec2(795, 130);
		keyPositions[Key::RBracket] = ImVec2(860, 130);
		keyPositions[Key::Backslash] = ImVec2(925, 130);
		keyPositions[Key::PageUp] = ImVec2(990, 130);

		//Caps Lock row
		keyPositions[Key::CapsLock] = ImVec2(0, 195);
		keyPositions[Key::A] = ImVec2(145, 195);
		keyPositions[Key::S] = ImVec2(210, 195);
		keyPositions[Key::D] = ImVec2(275, 195);
		keyPositions[Key::F] = ImVec2(340, 195);
		keyPositions[Key::G] = ImVec2(405, 195);
		keyPositions[Key::H] = ImVec2(470, 195);
		keyPositions[Key::J] = ImVec2(535, 195);
		keyPositions[Key::K] = ImVec2(600, 195);
		keyPositions[Key::L] = ImVec2(665, 195);
		keyPositions[Key::Semicolon] = ImVec2(730, 195);
		keyPositions[Key::Quote] = ImVec2(795, 195);
		keyPositions[Key::Enter] = ImVec2(860, 195);
		keyPositions[Key::PageDown] = ImVec2(1005, 195);

		// Shift row
		keyPositions[Key::LShift] = ImVec2(0, 260);
		keyPositions[Key::Z] = ImVec2(145, 260);
		keyPositions[Key::X] = ImVec2(210, 260);
		keyPositions[Key::C] = ImVec2(275, 260);
		keyPositions[Key::V] = ImVec2(340, 260);
		keyPositions[Key::B] = ImVec2(405, 260);
		keyPositions[Key::N] = ImVec2(470, 260);
		keyPositions[Key::M] = ImVec2(535, 260);
		keyPositions[Key::Comma] = ImVec2(600, 260);
		keyPositions[Key::Period] = ImVec2(665, 260);
		keyPositions[Key::Forwardslash] = ImVec2(730, 260);
		keyPositions[Key::RShift] = ImVec2(795, 260);
		keyPositions[Key::Up] = ImVec2(940, 260);
		keyPositions[Key::End] = ImVec2(1005, 260);

		// Control row
		keyPositions[Key::LControl] = ImVec2(0, 325);
		keyPositions[Key::Windows] = ImVec2(65, 325);
		keyPositions[Key::LAlt] = ImVec2(145, 325);
		keyPositions[Key::Spacebar] = ImVec2(210, 325);
		keyPositions[Key::RAlt] = ImVec2(405, 325);
		keyPositions[Key::Function] = ImVec2(470, 325);
		keyPositions[Key::RControl] = ImVec2(535, 325);
		keyPositions[Key::Left] = ImVec2(860, 325);
		keyPositions[Key::Down] = ImVec2(925, 325);
		keyPositions[Key::Right] = ImVec2(990, 325);
	}
}

void Init::Profiles() {
	// Full Keyboard Profile: Use all key regions
	for (const auto& [key, _] : kbmo.keyRegions) {
		kbmo.fullKeyboardPositions[key] = ImVec2(0, 0); // Default all keys to (0,0)
	}

	// Recommended Profile: Use selected keys
	kbmo.recommendedPositions = {
		// top row
		{"tab", ImVec2(0, 0)},
		{"q", ImVec2(145, 0)},
		{"w", ImVec2(210, 0)},
		{"e", ImVec2(275, 0)},

		// second row
		{"leftshift", ImVec2(0, 65)},
		{"a", ImVec2(145, 65)},
		{"s", ImVec2(210, 200)},
		{"d", ImVec2(275, 200)},

		// third row
		{"leftcontrol", ImVec2(0, 130)},
		{"spacebar", ImVec2(65, 130)},
		{"rightcontrol", ImVec2(265, 130)},

		{"up", ImVec2(480, 65)},
		{"down", ImVec2(470, 130)},
		{"left", ImVec2(405, 130)},
		{"right", ImVec2(535, 130)},
	};

	LOG("[KBMOverlay] Profiles initialized.");
}

void Init::MouseActionPositions(std::map<std::string, ImVec2>& mouseActionPositions) {
	mouseActionPositions[MB::Body] = ImVec2(326, 0);

	mouseActionPositions[MB::MouseX] = ImVec2(326, 0);
	mouseActionPositions[MB::MouseY] = ImVec2(326, 0);

	mouseActionPositions[MB::ThumbMouse] = ImVec2(326, 0);
	mouseActionPositions[MB::ThumbMouse2] = ImVec2(326, 0);

	mouseActionPositions[MB::LeftMouseButton] = ImVec2(1040, 300);
	mouseActionPositions[MB::RightMouseButton] = ImVec2(1216, 0);

	mouseActionPositions[MB::MouseScrollDown] = ImVec2(326, 0);
	mouseActionPositions[MB::MouseScrollUp] = ImVec2(326, 0);

	mouseActionPositions[MB::MiddleMouseButton] = ImVec2(326, 0);
}

void Init::ActionKeyMap(std::map<std::string, std::string>& actionKeyMap) {

	actionKeyMap[Action::ThrottleForward] = *ForwardKey;
	actionKeyMap[Action::ThrottleReverse] = *ReverseKey;

	actionKeyMap[Action::SteerRight] = *SteerRKey;
	actionKeyMap[Action::SteerLeft] = *SteerLKey;

	actionKeyMap[Action::LookUp] = *LookUpKey;
	actionKeyMap[Action::LookDown] = *LookDownKey;
	actionKeyMap[Action::LookRight] = *LookRightKey;
	actionKeyMap[Action::LookLeft] = *LookLeftKey;

	actionKeyMap[Action::YawRight] = *YawRKey;
	actionKeyMap[Action::YawLeft] = *YawLKey;

	actionKeyMap[Action::PitchDown] = *PitchDownKey;
	actionKeyMap[Action::PitchUp] = *PitchUpKey;

	actionKeyMap[Action::RollRight] = *ARRKey;
	actionKeyMap[Action::RollLeft] = *ARLKey;

	actionKeyMap[Action::Boost] = *BoostKey;

	actionKeyMap[Action::Jump] = *JumpKey;

	actionKeyMap[Action::Handbreak] = *HandbreakKey;

	actionKeyMap[Action::SecondaryCamera] = *BallCamKey;

	actionKeyMap[Action::ToggleRoll] = *FreeRollKey;

	actionKeyMap[Action::RearCamera] = *RearCamKey;

	actionKeyMap[Action::UsePickup] = *UsePickupKey;
	actionKeyMap[Action::NextPickup] = *NextPickupKey;
	actionKeyMap[Action::Grab] = *GrabKey;

	actionKeyMap[Action::ToggleMidGameMenu] = *MenuKey;
	actionKeyMap[Action::ToggleScoreboard] = *ScoreboardKey;

	actionKeyMap[Action::Chat] = *ChatKey;
	actionKeyMap[Action::TeamChat] = *TeamChatKey;
	actionKeyMap[Action::PartyChat] = *PartyChatKey;

	actionKeyMap[Action::ChatPreset1] = *ChatPreset1Key;
	actionKeyMap[Action::ChatPreset2] = *ChatPreset2Key;
	actionKeyMap[Action::ChatPreset3] = *ChatPreset3Key;
	actionKeyMap[Action::ChatPreset4] = *ChatPreset4Key;

	actionKeyMap[Action::PushToTalk] = *PushToTalkKey;

	actionKeyMap[Action::ResetTraining] = *ResetTrainingKey;
}

// Initialize mouse key regions
void Init::MouseKeyRegions(std::map<std::string, Rect>& mouseKeyRegions) {
	mouseKeyRegions[MB::Body] = { 2204, 8515, 285, 244 };

	mouseKeyRegions[MB::MouseX] = { 2450, 8736, 22, 22 };
	mouseKeyRegions[MB::MouseY] = { 2450, 8736, 22, 22 };

	mouseKeyRegions[MB::ThumbMouse] = { 2408, 8760, 42, 64 };
	mouseKeyRegions[MB::ThumbMouse2] = { 2408, 8760, 42, 64 };

	mouseKeyRegions[MB::LeftMouseButton] = { 1920, 8515, 141, 176 };
	mouseKeyRegions[MB::RightMouseButton] = { 2062, 8515, 141, 176 };

	mouseKeyRegions[MB::MouseScrollDown] = { 2356, 8760, 50, 97 };
	mouseKeyRegions[MB::MouseScrollUp] = { 2306, 8760, 50, 97 };

	mouseKeyRegions[MB::MiddleMouseButton] = { 2250, 8760, 50, 97 };

	mouseKeyRegions[MB::ScrollWheel] = { 2204, 8760, 50, 97 };
}

void Init::KeyRegions(std::map<std::string, Rect>& keyRegions) {

	// Escape row
	keyRegions[Key::Escape] = { 0, 0, 159, 130 };
	keyRegions[Key::F1] = { 160, 0, 159, 130 };
	keyRegions[Key::F2] = { 320, 0, 159, 130 };
	keyRegions[Key::F3] = { 480, 0, 159, 130 };
	keyRegions[Key::F4] = { 650, 0, 159, 130 };
	keyRegions[Key::F5] = { 800, 0, 159, 130 };
	keyRegions[Key::F6] = { 960, 0, 159, 130 };
	keyRegions[Key::F7] = { 1120, 0, 159, 130 };
	keyRegions[Key::F8] = { 1280, 0, 159, 130 };
	keyRegions[Key::F9] = { 1440, 0, 159, 130 };
	keyRegions[Key::F10] = { 1600, 0, 159, 130 };
	keyRegions[Key::F11] = { 1760, 0, 159, 130 };
	keyRegions[Key::F12] = { 1920, 0, 159, 130 };
	keyRegions[Key::PrintScreen] = { 2080, 0, 159, 130 };
	keyRegions[Key::Pause] = { 2240, 0, 159, 130 };
	keyRegions[Key::Delete] = { 2400, 0, 159, 130 };

	// ~ row
	keyRegions[Key::Tilde] = { 0, 1703, 159, 130 };
	keyRegions[Key::One] = { 160, 1703, 159, 130 };
	keyRegions[Key::Two] = { 320, 1703, 159, 130 };
	keyRegions[Key::Three] = { 480, 1703, 159, 130 };
	keyRegions[Key::Four] = { 640, 1703, 159, 130 };
	keyRegions[Key::Five] = { 800, 1703, 159, 130 };
	keyRegions[Key::Six] = { 960, 1703, 159, 130 };
	keyRegions[Key::Seven] = { 1120, 1703, 159, 130 };
	keyRegions[Key::Eight] = { 1280, 1703, 159, 130 };
	keyRegions[Key::Nine] = { 1440, 1703, 159, 130 };
	keyRegions[Key::Zero] = { 1600, 1703, 159, 130 };
	keyRegions[Key::Minus] = { 1760, 1703, 159, 130 };
	keyRegions[Key::Equals] = { 1920, 1703, 159, 130 };
	keyRegions[Key::Backspace] = { 2080, 1703, 322, 130 };
	keyRegions[Key::Home] = { 2400, 1703, 159, 130 };

	// Tab row
	keyRegions[Key::Tab] = { 0, 3406, 320, 130 };
	keyRegions[Key::Q] = { 320, 3406, 159, 130 };
	keyRegions[Key::W] = { 480, 3406, 159, 130 };
	keyRegions[Key::E] = { 640, 3406, 159, 130 };
	keyRegions[Key::R] = { 800, 3406, 159, 130 };
	keyRegions[Key::T] = { 960, 3406, 159, 130 };
	keyRegions[Key::Y] = { 1120, 3406, 159, 130 };
	keyRegions[Key::U] = { 1280, 3406, 159, 130 };
	keyRegions[Key::I] = { 1440, 3406, 159, 130 };
	keyRegions[Key::O] = { 1600, 3406, 159, 130 };
	keyRegions[Key::P] = { 1760, 3406, 159, 130 };
	keyRegions[Key::LBracket] = { 1920, 3406, 159, 130 };
	keyRegions[Key::RBracket] = { 2080, 3406, 159, 130 };
	keyRegions[Key::Backslash] = { 2240, 3406, 159, 130 };
	keyRegions[Key::PageUp] = { 2400, 3406, 159, 130 };

	//Caps Lock row
	keyRegions[Key::CapsLock] = { 0, 5109, 320, 130 };
	keyRegions[Key::A] = { 320, 5109, 159, 130 };
	keyRegions[Key::S] = { 480, 5109, 159, 130 };
	keyRegions[Key::D] = { 640, 5109, 159, 130 };
	keyRegions[Key::F] = { 800, 5109, 159, 130 };
	keyRegions[Key::G] = { 960, 5109, 159, 130 };
	keyRegions[Key::H] = { 1120, 5109, 159, 130 };
	keyRegions[Key::J] = { 1280, 5109, 159, 130 };
	keyRegions[Key::K] = { 1440, 5109, 159, 130 };
	keyRegions[Key::L] = { 1600, 5109, 159, 130 };
	keyRegions[Key::Semicolon] = { 1760, 5109, 159, 130 };
	keyRegions[Key::Quote] = { 1920, 5109, 159, 130 };
	keyRegions[Key::Enter] = { 2080, 5109, 159, 130 };
	keyRegions[Key::PageDown] = { 2400, 5109, 159, 130 };

	// Shift row
	keyRegions[Key::LShift] = { 0, 6812, 320, 130 };
	keyRegions[Key::Z] = { 320, 6812, 159, 130 };
	keyRegions[Key::X] = { 480, 6812, 159, 130 };
	keyRegions[Key::C] = { 640, 6812, 159, 130 };
	keyRegions[Key::V] = { 800, 6812, 159, 130 };
	keyRegions[Key::B] = { 960, 6812, 159, 130 };
	keyRegions[Key::N] = { 1120, 6812, 159, 130 };
	keyRegions[Key::M] = { 1280, 6812, 159, 130 };
	keyRegions[Key::Comma] = { 1440, 6812, 159, 130 };
	keyRegions[Key::Period] = { 1600, 6812, 159, 130 };
	keyRegions[Key::Forwardslash] = { 1760, 6812, 159, 130 };
	keyRegions[Key::RShift] = { 1920, 6812, 321, 130 };
	keyRegions[Key::Up] = { 2240, 6812, 159, 132 };
	keyRegions[Key::End] = { 2400, 6812, 159, 130 };

	// Control row
	keyRegions[Key::LControl] = { 0, 8515, 159, 130 };
	keyRegions[Key::Windows] = { 160, 8515, 159, 130 };
	keyRegions[Key::LAlt] = { 320, 8515, 159, 130 };
	keyRegions[Key::Spacebar] = { 480, 8515, 481, 130 };
	keyRegions[Key::RAlt] = { 960, 8515, 159, 130 };
	keyRegions[Key::Function] = { 1120, 8515, 159, 130 };
	keyRegions[Key::RControl] = { 1280, 8515, 159, 130 };
	keyRegions[Key::Left] = { 1440, 8515, 159, 130 };
	keyRegions[Key::Down] = { 1600, 8515, 159, 130 };
	keyRegions[Key::Right] = { 1760, 8515, 159, 130 };
}

void Init::KeyStates(std::map<std::string, KeyState>& keyStates, GameWrapper* gameWrapper)
{
	for (const auto& action : relevantActions) { // Iterate through relevantActions
		int keyIndex = gameWrapper->GetFNameIndexByString(action); // Use action name directly
		keyStates[action] = { keyIndex, false }; // Initialize with key index and not pressed

		// Mouse
		keyStates[MB::MouseX] = { gameWrapper->GetFNameIndexByString("MouseX"), false };
		keyStates[MB::MouseY] = { gameWrapper->GetFNameIndexByString("MouseY"), false };

		keyStates[MB::ThumbMouse] = { gameWrapper->GetFNameIndexByString("ThumbMouse"), false };
		keyStates[MB::ThumbMouse2] = { gameWrapper->GetFNameIndexByString("ThumbMouse2"), false };

		keyStates[MB::LeftMouseButton] = { gameWrapper->GetFNameIndexByString("LeftMouseButton"), false };
		keyStates[MB::RightMouseButton] = { gameWrapper->GetFNameIndexByString("RightMousebutton"), false };

		keyStates[MB::MouseScrollDown] = { gameWrapper->GetFNameIndexByString("MouseScrollDown"), false };
		keyStates[MB::MouseScrollUp] = { gameWrapper->GetFNameIndexByString("MouseScrollUp"), false };

		keyStates[MB::MiddleMouseButton] = { gameWrapper->GetFNameIndexByString("MiddleMouseButton"), false };

		// Escape row
		keyStates[Key::Escape] = { gameWrapper->GetFNameIndexByString("Escape"), false };
		keyStates[Key::F1] = { gameWrapper->GetFNameIndexByString("F1"), false };
		keyStates[Key::F2] = { gameWrapper->GetFNameIndexByString("F2"), false };
		keyStates[Key::F3] = { gameWrapper->GetFNameIndexByString("F3"), false };
		keyStates[Key::F4] = { gameWrapper->GetFNameIndexByString("F4"), false };
		keyStates[Key::F5] = { gameWrapper->GetFNameIndexByString("F5"), false };
		keyStates[Key::F6] = { gameWrapper->GetFNameIndexByString("F6"), false };
		keyStates[Key::F7] = { gameWrapper->GetFNameIndexByString("F7"), false };
		keyStates[Key::F8] = { gameWrapper->GetFNameIndexByString("F8"), false };
		keyStates[Key::F9] = { gameWrapper->GetFNameIndexByString("F9"), false };
		keyStates[Key::F10] = { gameWrapper->GetFNameIndexByString("F10"), false };
		keyStates[Key::F11] = { gameWrapper->GetFNameIndexByString("F11"), false };
		keyStates[Key::F12] = { gameWrapper->GetFNameIndexByString("F12"), false };
		keyStates[Key::PrintScreen] = { gameWrapper->GetFNameIndexByString("PrintScreen"), false };
		keyStates[Key::Pause] = { gameWrapper->GetFNameIndexByString("Pause"), false };
		keyStates[Key::Delete] = { gameWrapper->GetFNameIndexByString("Delete"), false };

		// ~ row
		keyStates[Key::Tilde] = { gameWrapper->GetFNameIndexByString(""), false };
		keyStates[Key::One] = { gameWrapper->GetFNameIndexByString("1"), false };
		keyStates[Key::Two] = { gameWrapper->GetFNameIndexByString("2"), false };
		keyStates[Key::Three] = { gameWrapper->GetFNameIndexByString("3"), false };
		keyStates[Key::Four] = { gameWrapper->GetFNameIndexByString("4"), false };
		keyStates[Key::Five] = { gameWrapper->GetFNameIndexByString("5"), false };
		keyStates[Key::Six] = { gameWrapper->GetFNameIndexByString("6"), false };
		keyStates[Key::Seven] = { gameWrapper->GetFNameIndexByString("7"), false };
		keyStates[Key::Eight] = { gameWrapper->GetFNameIndexByString("8"), false };
		keyStates[Key::Nine] = { gameWrapper->GetFNameIndexByString("9"), false };
		keyStates[Key::Zero] = { gameWrapper->GetFNameIndexByString("0"), false };
		keyStates[Key::Minus] = { gameWrapper->GetFNameIndexByString("-"), false };
		keyStates[Key::Equals] = { gameWrapper->GetFNameIndexByString("="), false };
		keyStates[Key::Backspace] = { gameWrapper->GetFNameIndexByString("BackSpace"), false };
		keyStates[Key::Home] = { gameWrapper->GetFNameIndexByString("Home"), false };

		// Tab row
		keyStates[Key::Tab] = { gameWrapper->GetFNameIndexByString("Tab"), false };
		keyStates[Key::Q] = { gameWrapper->GetFNameIndexByString("Q"), false };
		keyStates[Key::W] = { gameWrapper->GetFNameIndexByString("W"), false };
		keyStates[Key::E] = { gameWrapper->GetFNameIndexByString("E"), false };
		keyStates[Key::R] = { gameWrapper->GetFNameIndexByString("R"), false };
		keyStates[Key::T] = { gameWrapper->GetFNameIndexByString("T"), false };
		keyStates[Key::Y] = { gameWrapper->GetFNameIndexByString("Y"), false };
		keyStates[Key::U] = { gameWrapper->GetFNameIndexByString("U"), false };
		keyStates[Key::I] = { gameWrapper->GetFNameIndexByString("I"), false };
		keyStates[Key::O] = { gameWrapper->GetFNameIndexByString("O"), false };
		keyStates[Key::P] = { gameWrapper->GetFNameIndexByString("P"), false };
		keyStates[Key::LBracket] = { gameWrapper->GetFNameIndexByString("["), false };
		keyStates[Key::RBracket] = { gameWrapper->GetFNameIndexByString("]"), false };
		keyStates[Key::Backslash] = { gameWrapper->GetFNameIndexByString(""), false };
		keyStates[Key::PageUp] = { gameWrapper->GetFNameIndexByString("PageUp"), false };

		//Caps Lock row
		keyStates[Key::CapsLock] = { gameWrapper->GetFNameIndexByString("CapsLock"), false };
		keyStates[Key::A] = { gameWrapper->GetFNameIndexByString("A"), false };
		keyStates[Key::S] = { gameWrapper->GetFNameIndexByString("S"), false };
		keyStates[Key::D] = { gameWrapper->GetFNameIndexByString("D"), false };
		keyStates[Key::F] = { gameWrapper->GetFNameIndexByString("F"), false };
		keyStates[Key::G] = { gameWrapper->GetFNameIndexByString("G"), false };
		keyStates[Key::H] = { gameWrapper->GetFNameIndexByString("H"), false };
		keyStates[Key::J] = { gameWrapper->GetFNameIndexByString("J"), false };
		keyStates[Key::K] = { gameWrapper->GetFNameIndexByString("K"), false };
		keyStates[Key::L] = { gameWrapper->GetFNameIndexByString("L"), false };
		keyStates[Key::Semicolon] = { gameWrapper->GetFNameIndexByString(";"), false };
		keyStates[Key::Quote] = { gameWrapper->GetFNameIndexByString("'"), false };
		keyStates[Key::Enter] = { gameWrapper->GetFNameIndexByString("Enter"), false };
		keyStates[Key::PageDown] = { gameWrapper->GetFNameIndexByString("PageDown"), false };

		// Shift row
		keyStates[Key::LShift] = { gameWrapper->GetFNameIndexByString("LeftShift"), false };
		keyStates[Key::Z] = { gameWrapper->GetFNameIndexByString("Z"), false };
		keyStates[Key::X] = { gameWrapper->GetFNameIndexByString("X"), false };
		keyStates[Key::C] = { gameWrapper->GetFNameIndexByString("C"), false };
		keyStates[Key::V] = { gameWrapper->GetFNameIndexByString("V"), false };
		keyStates[Key::B] = { gameWrapper->GetFNameIndexByString("B"), false };
		keyStates[Key::N] = { gameWrapper->GetFNameIndexByString("N"), false };
		keyStates[Key::M] = { gameWrapper->GetFNameIndexByString("M"), false };
		keyStates[Key::Comma] = { gameWrapper->GetFNameIndexByString(","), false };
		keyStates[Key::Period] = { gameWrapper->GetFNameIndexByString("."), false };
		keyStates[Key::Forwardslash] = { gameWrapper->GetFNameIndexByString("/"), false };
		keyStates[Key::RShift] = { gameWrapper->GetFNameIndexByString("RightShift"), false };
		keyStates[Key::Up] = { gameWrapper->GetFNameIndexByString("Up"), false };
		keyStates[Key::End] = { gameWrapper->GetFNameIndexByString("End"), false };

		// Control row
		keyStates[Key::LControl] = { gameWrapper->GetFNameIndexByString("LeftControl"), false };
		keyStates[Key::Windows] = { gameWrapper->GetFNameIndexByString("Win"), false };
		keyStates[Key::LAlt] = { gameWrapper->GetFNameIndexByString("LeftAlt"), false };
		keyStates[Key::Spacebar] = { gameWrapper->GetFNameIndexByString("SpaceBar"), false };
		keyStates[Key::RAlt] = { gameWrapper->GetFNameIndexByString("RightAlt"), false };
		keyStates[Key::Function] = { gameWrapper->GetFNameIndexByString("Function"), false };
		keyStates[Key::RControl] = { gameWrapper->GetFNameIndexByString("RightControl"), false };
		keyStates[Key::Down] = { gameWrapper->GetFNameIndexByString("Down"), false };
		keyStates[Key::Left] = { gameWrapper->GetFNameIndexByString("Left"), false };
		keyStates[Key::Right] = { gameWrapper->GetFNameIndexByString("Right"), false };
	}
}


void Assign::KeyboardActionRegions(
	const std::map<std::string, std::string>& actionKeyMap,
	const std::map<std::string, Rect>& keyRegions,
	std::map<std::string, std::shared_ptr<Rect>>& actionRegions
) {
	for (const auto& [action, key] : actionKeyMap) {
		if (key.empty()) {
			actionRegions[action] = nullptr;
			continue;
		}

		auto it = keyRegions.find(key);
		if (it != keyRegions.end()) {
			actionRegions[action] = std::make_shared<Rect>(it->second);
		}
		else {
			actionRegions[action] = nullptr;
		}
	}
}

void Assign::MouseActionRegions(
	const std::map<std::string, std::string>& actionKeyMap,
	const std::map<std::string, Rect>& mouseKeyRegions,
	std::map<std::string, std::shared_ptr<Rect>>& mouseActionRegions
) {
	for (const auto& [action, key] : actionKeyMap) {
		if (key.empty()) {
			LOG("[KBMOverlay] Skipping mouse action '{}': Key is empty.", action);
			mouseActionRegions[action] = nullptr;
			continue;
		}

		auto it = mouseKeyRegions.find(key);
		if (it != mouseKeyRegions.end()) {
			mouseActionRegions[action] = std::make_shared<Rect>(it->second);
			LOG("[KBMOverlay] Assigned mouse region for action '{}': (x: {}, y: {}, width: {}, height: {})",
				action, it->second.x, it->second.y, it->second.width, it->second.height);
		}
		else {
			LOG("[KBMOverlay] No mouse region found for action '{}' with key '{}'", action, key);
			mouseActionRegions[action] = nullptr;
		}
	}
}


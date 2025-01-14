#include "pch.h"
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "KBMOverlay.h"
#include "Keys.h"
#include "Globals.h"

KBMOverlay kbmo;


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
}

void Init::KeyPositions(std::map<std::string, ImVec2>& keyPositions) {
	keyPositions.clear();

	if (*gLayoutIndex == 0) { // Recommended
		keyPositions.clear();

		if (*gLayoutIndex == 0 && *gUseMouseOverlay == true) {
			keyPositions[Mouse::Body] = ImVec2(0.5, 147.5);

			// Mouse
			keyPositions[Mouse::MiddleMouseButton] = ImVec2(95.5, 63.5);
			keyPositions[Mouse::MouseScrollUp] = ImVec2(95.5, 63.5);
			keyPositions[Mouse::MouseScrollDown] = ImVec2(95.5, 63.5);

			keyPositions[Mouse::ThumbMouseButton2] = ImVec2(0, 171.5); // Front Mouse Button
			keyPositions[Mouse::ThumbMouseButton] = ImVec2(10, 223); // Back Mouse Button

			keyPositions[Mouse::LeftMouseButton] = ImVec2(0.5, 0);
			keyPositions[Mouse::RightMouseButton] = ImVec2(117, 0);
		}
		else if (*gLayoutIndex == 0 && *gUseMouseOverlay == false) {
			// Arrow Keys
			keyPositions[Key::Up] = ImVec2(465, 64);
			keyPositions[Key::Left] = ImVec2(390, 128);
			keyPositions[Key::Down] = ImVec2(455, 128);
			keyPositions[Key::Right] = ImVec2(520, 128);
		}
		// Keyboard
		keyPositions[Key::Tab] = ImVec2(0, 0);
		keyPositions[Key::Q] = ImVec2(130, 0);
		keyPositions[Key::W] = ImVec2(195, 0);
		keyPositions[Key::E] = ImVec2(260, 0);

		keyPositions[Key::LShift] = ImVec2(0, 64);
		keyPositions[Key::A] = ImVec2(130, 64);
		keyPositions[Key::S] = ImVec2(195, 64);
		keyPositions[Key::D] = ImVec2(260, 64);

		keyPositions[Key::LControl] = ImVec2(0, 128);
		keyPositions[Key::Spacebar] = ImVec2(65, 128);
		keyPositions[Key::RControl] = ImVec2(260, 128);
	}

	else if (*gLayoutIndex == 1)
	{
		keyPositions.clear();

		if (*gLayoutIndex == 2 && *gUseMouseOverlay == true) {
			keyPositions[Mouse::Body] = ImVec2(0.5, 147.5);

			// Mouse
			keyPositions[Mouse::MiddleMouseButton] = ImVec2(95.5, 63.5);
			keyPositions[Mouse::MouseScrollUp] = ImVec2(95.5, 63.5);
			keyPositions[Mouse::MouseScrollDown] = ImVec2(95.5, 63.5);

			keyPositions[Mouse::ThumbMouseButton2] = ImVec2(0, 171.5); // Front Mouse Button
			keyPositions[Mouse::ThumbMouseButton] = ImVec2(10, 223); // Back Mouse Button

			keyPositions[Mouse::LeftMouseButton] = ImVec2(0.5, 0);
			keyPositions[Mouse::RightMouseButton] = ImVec2(117, 0);
		}


		keyPositions[Action::ThrottleForward] = ImVec2(910, 257);
		keyPositions[Action::ThrottleReverse] = ImVec2(910, 321);

		keyPositions[Action::SteerRight] = ImVec2(275, 192);
		keyPositions[Action::SteerLeft] = ImVec2(145, 192);

		keyPositions[Action::LookUp] = ImVec2(535, 257);
		keyPositions[Action::LookDown] = ImVec2(535, 321);
		keyPositions[Action::LookRight] = ImVec2(600, 321);
		keyPositions[Action::LookLeft] = ImVec2(470, 321);

		keyPositions[Action::YawRight] = ImVec2(275, 192);
		keyPositions[Action::YawLeft] = ImVec2(145, 192);

		keyPositions[Action::PitchDown] = ImVec2(210, 128);
		keyPositions[Action::PitchUp] = ImVec2(210, 192);

		keyPositions[Action::RollRight] = ImVec2(275, 128);
		keyPositions[Action::RollLeft] = ImVec2(145, 128);

		keyPositions[Action::Boost] = ImVec2(990, 321);

		keyPositions[Action::Jump] = ImVec2(860, 321);

		keyPositions[Action::Handbreak] = ImVec2(795, 321);

		keyPositions[Action::SecondaryCamera] = ImVec2(210, 321);

		keyPositions[Action::ToggleRoll] = ImVec2(0, 257);

		keyPositions[Action::RearCamera] = ImVec2(0, 321);

		keyPositions[Action::UsePickup] = ImVec2(340, 128);
		keyPositions[Action::NextPickup] = ImVec2(275, 257);
		keyPositions[Action::Grab] = ImVec2(0, 260);

		keyPositions[Action::ToggleMidGameMenu] = ImVec2(0, 0);
		keyPositions[Action::ToggleScoreboard] = ImVec2(0, 128);

		keyPositions[Action::Chat] = ImVec2(405, 128);
		keyPositions[Action::TeamChat] = ImVec2(470, 128);
		keyPositions[Action::PartyChat] = ImVec2(535, 128);


		keyPositions[Action::ChatPreset1] = ImVec2(145, 64);
		keyPositions[Action::ChatPreset2] = ImVec2(210, 64);
		keyPositions[Action::ChatPreset3] = ImVec2(275, 64);
		keyPositions[Action::ChatPreset4] = ImVec2(340, 64);

		keyPositions[Action::PushToTalk] = ImVec2(340, 193);

		keyPositions[Action::ResetTraining] = ImVec2(795, 63);
	}

	else if (*gLayoutIndex == 2) { // Full Keyboard
		keyPositions.clear(); // Clear existing positions

		if (*gLayoutIndex == 2 && *gUseMouseOverlay == true) {
			keyPositions[Mouse::Body] = ImVec2(0.5, 147.5);

			// Mouse
			keyPositions[Mouse::MiddleMouseButton] = ImVec2(95.5, 63.5);
			keyPositions[Mouse::MouseScrollUp] = ImVec2(95.5, 63.5);
			keyPositions[Mouse::MouseScrollDown] = ImVec2(95.5, 63.5);

			keyPositions[Mouse::ThumbMouseButton2] = ImVec2(0, 171.5); // Front Mouse Button
			keyPositions[Mouse::ThumbMouseButton] = ImVec2(10, 223); // Back Mouse Button

			keyPositions[Mouse::LeftMouseButton] = ImVec2(0.5, 0);
			keyPositions[Mouse::RightMouseButton] = ImVec2(117, 0);
		}

		// Escape row
		keyPositions[Key::Escape] = ImVec2(0, 0);
		keyPositions[Key::F1] = ImVec2(65, 0);
		keyPositions[Key::F2] = ImVec2(130, 0);
		keyPositions[Key::F3] = ImVec2(195, 0);
		keyPositions[Key::F4] = ImVec2(260, 0);
		keyPositions[Key::F5] = ImVec2(325, 0);
		keyPositions[Key::F6] = ImVec2(390, 0);
		keyPositions[Key::F7] = ImVec2(455, 0);
		keyPositions[Key::F8] = ImVec2(520, 0);
		keyPositions[Key::F9] = ImVec2(585, 0);
		keyPositions[Key::F10] = ImVec2(650, 0);
		keyPositions[Key::F11] = ImVec2(715, 0);
		keyPositions[Key::F12] = ImVec2(780, 0);
		keyPositions[Key::PrintScreen] = ImVec2(845, 0);
		keyPositions[Key::Pause] = ImVec2(910, 0);
		keyPositions[Key::Delete] = ImVec2(975, 0);

		// ~ row
		keyPositions[Key::Tilde] = ImVec2(0, 64);
		keyPositions[Key::One] = ImVec2(65, 64);
		keyPositions[Key::Two] = ImVec2(130, 64);
		keyPositions[Key::Three] = ImVec2(195, 64);
		keyPositions[Key::Four] = ImVec2(260, 64);
		keyPositions[Key::Five] = ImVec2(325, 64);
		keyPositions[Key::Six] = ImVec2(390, 64);
		keyPositions[Key::Seven] = ImVec2(455, 64);
		keyPositions[Key::Eight] = ImVec2(520, 64);
		keyPositions[Key::Nine] = ImVec2(585, 64);
		keyPositions[Key::Zero] = ImVec2(650, 64);
		keyPositions[Key::Minus] = ImVec2(715, 64);
		keyPositions[Key::Equals] = ImVec2(780, 64);
		keyPositions[Key::Backspace] = ImVec2(845, 64);;
		keyPositions[Key::Home] = ImVec2(975, 64);

		// Tab row
		keyPositions[Key::Tab] = ImVec2(0, 128);
		keyPositions[Key::Q] = ImVec2(130, 128);
		keyPositions[Key::W] = ImVec2(195, 128);
		keyPositions[Key::E] = ImVec2(260, 128);
		keyPositions[Key::R] = ImVec2(325, 128);
		keyPositions[Key::T] = ImVec2(390, 128);
		keyPositions[Key::Y] = ImVec2(455, 128);
		keyPositions[Key::U] = ImVec2(520, 128);
		keyPositions[Key::I] = ImVec2(585, 128);
		keyPositions[Key::O] = ImVec2(650, 128);
		keyPositions[Key::P] = ImVec2(715, 128);
		keyPositions[Key::LBracket] = ImVec2(780, 128);
		keyPositions[Key::RBracket] = ImVec2(845, 128);
		keyPositions[Key::Backslash] = ImVec2(910, 128);
		keyPositions[Key::PageUp] = ImVec2(975, 128);

		//Caps Lock row
		keyPositions[Key::CapsLock] = ImVec2(0, 192);
		keyPositions[Key::A] = ImVec2(130, 192);
		keyPositions[Key::S] = ImVec2(195, 192);
		keyPositions[Key::D] = ImVec2(260, 192);
		keyPositions[Key::F] = ImVec2(325, 192);
		keyPositions[Key::G] = ImVec2(390, 192);
		keyPositions[Key::H] = ImVec2(455, 192);
		keyPositions[Key::J] = ImVec2(520, 192);
		keyPositions[Key::K] = ImVec2(585, 192);
		keyPositions[Key::L] = ImVec2(650, 192);
		keyPositions[Key::Semicolon] = ImVec2(715, 192);
		keyPositions[Key::Quote] = ImVec2(780, 192);
		keyPositions[Key::Enter] = ImVec2(845, 192);
		keyPositions[Key::PageDown] = ImVec2(975, 192);

		// Shift row
		keyPositions[Key::LShift] = ImVec2(0, 257);
		keyPositions[Key::Z] = ImVec2(130, 257);
		keyPositions[Key::X] = ImVec2(195, 257);
		keyPositions[Key::C] = ImVec2(260, 257);
		keyPositions[Key::V] = ImVec2(325, 257);
		keyPositions[Key::B] = ImVec2(390, 257);
		keyPositions[Key::N] = ImVec2(455, 257);
		keyPositions[Key::M] = ImVec2(520, 257);
		keyPositions[Key::Comma] = ImVec2(585, 257);
		keyPositions[Key::Period] = ImVec2(650, 257);
		keyPositions[Key::Forwardslash] = ImVec2(715, 257);
		keyPositions[Key::RShift] = ImVec2(780, 257);
		keyPositions[Key::Up] = ImVec2(910, 257);
		keyPositions[Key::End] = ImVec2(975, 257);

		// Control row
		keyPositions[Key::LControl] = ImVec2(0, 321);
		keyPositions[Key::Windows] = ImVec2(65, 321);
		keyPositions[Key::LAlt] = ImVec2(130, 321);
		keyPositions[Key::Spacebar] = ImVec2(195, 321);
		keyPositions[Key::RAlt] = ImVec2(650, 321);
		keyPositions[Key::Function] = ImVec2(715, 321);
		keyPositions[Key::RControl] = ImVec2(780, 321);
		keyPositions[Key::Left] = ImVec2(845, 321);
		keyPositions[Key::Down] = ImVec2(910, 321);
		keyPositions[Key::Right] = ImVec2(975, 321);
	}
}

void Init::ActionKeyMap(std::map<std::string, std::string>& actionKeyMap, std::vector<std::string>& mouseBinds) {
	actionKeyMap.clear();
	mouseBinds.clear();
	*gUseMouseOverlay = false;

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

	// Explicitly check for mouse keys
	for (const auto& [action, key] : actionKeyMap) {
		if (key == Mouse::MouseX || key == Mouse::MouseY) {
			continue; // Ignore default bindings
		}
		if (key == Mouse::ThumbMouseButton || key == Mouse::ThumbMouseButton2 ||
			key == Mouse::LeftMouseButton || key == Mouse::RightMouseButton ||
			key == Mouse::MouseScrollUp || key == Mouse::MouseScrollDown ||
			key == Mouse::MiddleMouseButton) {
			mouseBinds.push_back(key); // Track mouse-specific bindings
		}
	}
	if (!mouseBinds.empty()) {
		*gUseMouseOverlay = true;
	}
}


void Init::KeyRegions(std::map<std::string, Rect>& keyRegions) {

	keyRegions[Mouse::Body] = { 3017, 1703, 459, 393 };

	// Mouse
	keyRegions[Mouse::LeftMouseButton] = { 2560, 1703, 227, 283 };
	keyRegions[Mouse::RightMouseButton] = { 2788, 1703, 227, 283 };

	keyRegions[Mouse::MiddleMouseButton] = { 3017, 2097, 80, 156 };
	keyRegions[Mouse::MouseScrollUp] = { 3017, 2097, 80, 156 };
	keyRegions[Mouse::MouseScrollDown] = { 3017, 2097, 80, 156 };


	keyRegions[Mouse::ThumbMouseButton2] = { 3345, 2097, 69, 103 };
	keyRegions[Mouse::ThumbMouseButton] = { 3345, 2097, 69, 103 };

	keyRegions[Mouse::MouseX] = { 3414, 2097, 37, 36 };
	keyRegions[Mouse::MouseY] = { 3414, 2097, 37, 36 };

	// Escape row
	keyRegions[Key::Escape] = { 0, 0, 159, 130 };
	keyRegions[Key::F1] = { 160, 0, 159, 130 };
	keyRegions[Key::F2] = { 320, 0, 159, 130 };
	keyRegions[Key::F3] = { 480, 0, 159, 130 };
	keyRegions[Key::F4] = { 640, 0, 159, 130 };
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
	keyRegions[Key::Enter] = { 2080, 5109, 320, 130 };
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

	keyRegions[Key::Spacebar] = { 2560, 0, 940, 130 };

	if (*gLayoutIndex == 0) {
		keyRegions[Key::Spacebar] = { 480, 8515, 419, 130 };
	}
	else {
		keyRegions[Key::Spacebar] = { 2560, 0, 940, 130 };
	}
	keyRegions[Key::RAlt] = { 960, 8515, 159, 130 };
	keyRegions[Key::Function] = { 1120, 8515, 159, 130 };
	keyRegions[Key::RControl] = { 1280, 8515, 159, 130 };
	keyRegions[Key::Left] = { 1440, 8515, 159, 130 };
	keyRegions[Key::Down] = { 1600, 8515, 159, 130 };
	keyRegions[Key::Right] = { 1760, 8515, 159, 130 };
}

void Init::ActionTitles(std::map<std::string, Rect>& actionTitles)
{

	actionTitles[Action::ThrottleForward] = { 0,10218,159,27 };

	actionTitles[Action::ThrottleReverse] = { 160,10218,159,27 };

	actionTitles[Action::SteerRight] = { 320,10218,159,27 };
	actionTitles[Action::SteerLeft] = { 480,10218,159,27 };

	actionTitles[Action::LookUp] = { 640,10218,159,27 };

	actionTitles[Action::LookDown] = { 0,10246,159,27 };
	actionTitles[Action::LookRight] = { 160,10246,159,27 };
	actionTitles[Action::LookLeft] = { 320,10246,159,27 };

	actionTitles[Action::YawRight] = { 480,10246,159,27 };
	actionTitles[Action::YawLeft] = { 640,10246,159,27 };

	actionTitles[Action::PitchUp] = { 0,10274,159,27 };
	actionTitles[Action::PitchDown] = { 160,10274,159,27 };

	actionTitles[Action::RollRight] = { 320,10274,159,27 };
	actionTitles[Action::RollLeft] = { 480,10274,159,27 };

	actionTitles[Action::Boost] = { 640,10274,159,27 };

	actionTitles[Action::Jump] = { 0,10302,159,27 };

	actionTitles[Action::Handbreak] = { 160,10302,159,27 };

	actionTitles[Action::SecondaryCamera] = { 320,10302,159,27 };

	actionTitles[Action::ToggleRoll] = { 480,10302,159,27 };

	actionTitles[Action::RearCamera] = { 640,10302,159,27 };

	actionTitles[Action::UsePickup] = { 0,10330,159,27 };
	actionTitles[Action::NextPickup] = { 160,10330,159,27 };
	actionTitles[Action::Grab] = { 320,10330,159,27 };

	actionTitles[Action::ToggleMidGameMenu] = { 480,10330,159,27 };
	actionTitles[Action::ToggleScoreboard] = { 640,10330,159,27 };

	actionTitles[Action::Chat] = { 0,10358,159,27 };
	actionTitles[Action::TeamChat] = { 160,10358,159,27 };
	actionTitles[Action::PartyChat] = { 320,10358,159,27 };


	actionTitles[Action::ChatPreset1] = { 480,10358,159,27 };
	actionTitles[Action::ChatPreset2] = { 640,10358,159,27 };
	actionTitles[Action::ChatPreset3] = { 0,10387,159,27 };
	actionTitles[Action::ChatPreset4] = { 160,10387,159,27 };

	actionTitles[Action::PushToTalk] = { 320,10387,159,27 };

	actionTitles[Action::ResetTraining] = { 480,10387,159,27 };
}

void Init::KeyStates(std::map<std::string, KeyState>& keyStates, GameWrapper* gameWrapper)
{
	for (const auto& action : relevantActions) { // Iterate through relevantActions
		int keyIndex = gameWrapper->GetFNameIndexByString(action); // Use action name directly
		keyStates[action] = { keyIndex, false }; // Initialize with key index and not pressed

		// Mouse
		keyStates[Mouse::MouseX] = { gameWrapper->GetFNameIndexByString("MouseX"), false };
		keyStates[Mouse::MouseY] = { gameWrapper->GetFNameIndexByString("MouseY"), false };

		keyStates[Mouse::ThumbMouseButton] = { gameWrapper->GetFNameIndexByString("ThumbMouseButton"), false };
		keyStates[Mouse::ThumbMouseButton2] = { gameWrapper->GetFNameIndexByString("ThumbMouseButton2"), false };

		keyStates[Mouse::LeftMouseButton] = { gameWrapper->GetFNameIndexByString("LeftMouseButton"), false };
		keyStates[Mouse::RightMouseButton] = { gameWrapper->GetFNameIndexByString("RightMouseButton"), false };

		keyStates[Mouse::MouseScrollDown] = { gameWrapper->GetFNameIndexByString("MouseScrollDown"), false };
		keyStates[Mouse::MouseScrollUp] = { gameWrapper->GetFNameIndexByString("MouseScrollUp"), false };

		keyStates[Mouse::MiddleMouseButton] = { gameWrapper->GetFNameIndexByString("MiddleMouseButton"), false };

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


ImVec2 Assign::MouseKeyOffset(const std::string& key, int selectedIndex) {
	if (key == Mouse::ThumbMouseButton) {
		if (selectedIndex == 0) return ImVec2(0.0f, 105.0f);
		if (selectedIndex == 1) return ImVec2(0.0f, 210.0f);
		if (selectedIndex == 2) return ImVec2(0.0f, 315.0f);
		if (selectedIndex == 3) return ImVec2(0.0f, 420.0f);
		if (selectedIndex == 4) return ImVec2(0.0f, 525.0f);
		if (selectedIndex == 5) return ImVec2(0.0f, 630.0f);
		if (selectedIndex == 6) return ImVec2(0.0f, 735.0f);
		if (selectedIndex == 7) return ImVec2(0.0f, 840.0f);
		if (selectedIndex == 8) return ImVec2(0.0f, 945.0f);
		if (selectedIndex == 9) return ImVec2(0.0f, 1050.0f);
		if (selectedIndex == 10) return ImVec2(0.0f, 1155.0f);
		if (selectedIndex == 11) return ImVec2(0.0f, 1260.0f);
	}
	else if (key == Mouse::ThumbMouseButton2) {
		if (selectedIndex == 0) return ImVec2(0.0f, 105.0f);
		if (selectedIndex == 1) return ImVec2(0.0f, 210.0f);
		if (selectedIndex == 2) return ImVec2(0.0f, 315.0f);
		if (selectedIndex == 3) return ImVec2(0.0f, 420.0f);
		if (selectedIndex == 4) return ImVec2(0.0f, 525.0f);
		if (selectedIndex == 5) return ImVec2(0.0f, 630.0f);
		if (selectedIndex == 6) return ImVec2(0.0f, 735.0f);
		if (selectedIndex == 7) return ImVec2(0.0f, 840.0f);
		if (selectedIndex == 8) return ImVec2(0.0f, 945.0f);
		if (selectedIndex == 9) return ImVec2(0.0f, 1050.0f);
		if (selectedIndex == 10) return ImVec2(0.0f, 1155.0f);
		if (selectedIndex == 11) return ImVec2(0.0f, 1260.0f);
	}
	else if (key == Mouse::LeftMouseButton) {
		if (selectedIndex == 0) return ImVec2(0.0f, 286.0f);
		if (selectedIndex == 1) return ImVec2(0.0f, 572.0f);
		if (selectedIndex == 2) return ImVec2(0.0f, 858.0f);
		if (selectedIndex == 3) return ImVec2(0.0f, 1144.0f);
		if (selectedIndex == 4) return ImVec2(0.0f, 1430.0f);
		if (selectedIndex == 5) return ImVec2(0.0f, 1716.0f);
		if (selectedIndex == 6) return ImVec2(0.0f, 2002.0f);
		if (selectedIndex == 7) return ImVec2(0.0f, 2288.0f);
		if (selectedIndex == 8) return ImVec2(0.0f, 2574.0f);
		if (selectedIndex == 9) return ImVec2(0.0f, 2860.0f);
		if (selectedIndex == 10) return ImVec2(0.0f, 3146.0f);
		if (selectedIndex == 11) return ImVec2(0.0f, 3432.0f);
	}
	else if (key == Mouse::RightMouseButton) {
		if (selectedIndex == 0) return ImVec2(0.0f, 286.0f);
		if (selectedIndex == 1) return ImVec2(0.0f, 572.0f);
		if (selectedIndex == 2) return ImVec2(0.0f, 858.0f);
		if (selectedIndex == 3) return ImVec2(0.0f, 1144.0f);
		if (selectedIndex == 4) return ImVec2(0.0f, 1430.0f);
		if (selectedIndex == 5) return ImVec2(0.0f, 1716.0f);
		if (selectedIndex == 6) return ImVec2(0.0f, 2002.0f);
		if (selectedIndex == 7) return ImVec2(0.0f, 2288.0f);
		if (selectedIndex == 8) return ImVec2(0.0f, 2574.0f);
		if (selectedIndex == 9) return ImVec2(0.0f, 2860.0f);
		if (selectedIndex == 10) return ImVec2(0.0f, 3146.0f);
		if (selectedIndex == 11) return ImVec2(0.0f, 3432.0f);
	}
	else if (key == Mouse::MiddleMouseButton) {
		if (selectedIndex == 0) return ImVec2(82.0f, 0.0f);
		if (selectedIndex == 1) return ImVec2(82.0f, 158.0f);
		if (selectedIndex == 2) return ImVec2(82.0f, 316.0f);
		if (selectedIndex == 3) return ImVec2(82.0f, 474.0f);
		if (selectedIndex == 4) return ImVec2(82.0f, 632.0f);
		if (selectedIndex == 5) return ImVec2(82.0f, 790.0f);
		if (selectedIndex == 6) return ImVec2(82.0f, 948.0f);
		if (selectedIndex == 7) return ImVec2(82.0f, 1106.0f);
		if (selectedIndex == 8) return ImVec2(82.0f, 1264.0f);
		if (selectedIndex == 9) return ImVec2(82.0f, 1422.0f);
		if (selectedIndex == 10) return ImVec2(82.0f, 1580.0f);
		if (selectedIndex == 11) return ImVec2(82.0f, 1738.0f);
	}
	else if (key == Mouse::MouseScrollUp) {
		if (selectedIndex == 0) return ImVec2(164.0f, 0.0f);
		if (selectedIndex == 1) return ImVec2(164.0f, 158.0f);
		if (selectedIndex == 2) return ImVec2(164.0f, 316.0f);
		if (selectedIndex == 3) return ImVec2(164.0f, 474.0f);
		if (selectedIndex == 4) return ImVec2(164.0f, 632.0f);
		if (selectedIndex == 5) return ImVec2(164.0f, 790.0f);
		if (selectedIndex == 6) return ImVec2(164.0f, 948.0f);
		if (selectedIndex == 7) return ImVec2(164.0f, 1106.0f);
		if (selectedIndex == 8) return ImVec2(164.0f, 1264.0f);
		if (selectedIndex == 9) return ImVec2(164.0f, 1422.0f);
		if (selectedIndex == 10) return ImVec2(164.0f, 1580.0f);
		if (selectedIndex == 11) return ImVec2(164.0f, 1738.0f);
	}
	else if (key == Mouse::MouseScrollDown) {
		if (selectedIndex == 0) return ImVec2(246.0f, 0.0f);
		if (selectedIndex == 1) return ImVec2(246.0f, 158.0f);
		if (selectedIndex == 2) return ImVec2(246.0f, 316.0f);
		if (selectedIndex == 3) return ImVec2(246.0f, 474.0f);
		if (selectedIndex == 4) return ImVec2(246.0f, 632.0f);
		if (selectedIndex == 5) return ImVec2(246.0f, 790.0f);
		if (selectedIndex == 6) return ImVec2(246.0f, 948.0f);
		if (selectedIndex == 7) return ImVec2(246.0f, 1106.0f);
		if (selectedIndex == 8) return ImVec2(246.0f, 1264.0f);
		if (selectedIndex == 9) return ImVec2(246.0f, 1422.0f);
		if (selectedIndex == 10) return ImVec2(246.0f, 1580.0f);
		if (selectedIndex == 11) return ImVec2(246.0f, 1738.0f);
	}
	else if (key == Mouse::MouseX) {
		if (selectedIndex == 0) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 1) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 2) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 3) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 4) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 5) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 6) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 7) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 8) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 9) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 10) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 11) return ImVec2(0.0f, 0.0f);
	}
	else if (key == Mouse::MouseY) {
		if (selectedIndex == 0) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 1) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 2) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 3) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 4) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 5) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 6) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 7) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 8) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 9) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 10) return ImVec2(0.0f, 0.0f);
		if (selectedIndex == 11) return ImVec2(0.0f, 0.0f);
	}
	else if (key == Mouse::Body) {
		return ImVec2(0.0f, 0.0f);
	}

	// Default case if key or index is not specifically handled
	return ImVec2(0.0f, 0.0f);
}


void Assign::KeyboardActionRegions(
	const std::map<std::string, std::string>& actionKeyMap,
	const std::map<std::string, Rect>& keyRegions,
	std::map<std::string, std::shared_ptr<Rect>>& actionRegions
) {
	// Clear existing regions
	actionRegions.clear();

	// Handle Full Keyboard Layout
	if (*gLayoutIndex == 2) { // Full Keyboard
		for (const auto& [key, region] : keyRegions) {
			// Include only keys present in actionKeyMap
			if (actionKeyMap.find(key) != actionKeyMap.end()) {
				actionRegions[key] = std::make_shared<Rect>(region);
			}
		}
		return; // Full Keyboard layout does not use action-specific logic
	}

	// Handle Recommended or Custom Layouts
	for (const auto& [action, key] : actionKeyMap) {
		if (key.empty()) {
			actionRegions[action] = std::make_shared<Rect>(Rect{ 0, 0, 0, 0 }); // Assign empty Rect
			LOG("[Assign::KeyboardActionRegions] Action '{}' has no assigned key.", action);
			continue;
		}

		// Find the key region in keyRegions
		auto it = keyRegions.find(key);
		if (it != keyRegions.end()) {
			actionRegions[action] = std::make_shared<Rect>(it->second);
		}
		else {
			actionRegions[action] = std::make_shared<Rect>(Rect{ 0, 0, 0, 0 }); // Assign empty Rect
			LOG("[Assign::KeyboardActionRegions] Key '{}' for action '{}' not found in keyRegions.", key, action);
		}
	}
}


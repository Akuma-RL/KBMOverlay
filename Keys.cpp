#include "pch.h"
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "Keys.h"
#include "Globals.h"

void Init::ActionPositions(std::map<std::string, ImVec2>& actionPositions) {
	actionPositions[Action::ThrottleForward] = ImVec2(510, 835);
	actionPositions[Action::ThrottleReverse] = ImVec2(500, 900);

	actionPositions[Action::SteerRight] = ImVec2(310, 835);
	actionPositions[Action::SteerLeft] = ImVec2(180, 835);

	actionPositions[Action::YawRight] = ImVec2(310, 835);
	actionPositions[Action::YawLeft] = ImVec2(180, 830);

	actionPositions[Action::PitchDown] = ImVec2(245, 770);
	actionPositions[Action::PitchUp] = ImVec2(245, 835);

	actionPositions[Action::RollRight] = ImVec2(310, 770);
	actionPositions[Action::RollLeft] = ImVec2(180, 770);

	actionPositions[Action::Boost] = ImVec2(565, 900);

	actionPositions[Action::Jump] = ImVec2(435, 900);

	actionPositions[Action::Handbreak] = ImVec2(300, 900);

	actionPositions[Action::SecondaryCamera] = ImVec2(100, 900);

	actionPositions[Action::ToggleRoll] = ImVec2(35, 835);

	actionPositions[Action::RearCamera] = ImVec2(35, 900);

	actionPositions[Action::ToggleScoreboard] = ImVec2(35, 770);
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

void Init::KeyRegions(std::map<std::string, Rect>& keyRegions) {

	// Escape row
	keyRegions[Key::Escape] = { 0, 0, 160, 130 };
	keyRegions[Key::F1] = { 159, 0, 161, 130 };
	keyRegions[Key::F2] = { 319, 0, 161, 130 };
	keyRegions[Key::F3] = { 479, 0, 161, 130 };
	keyRegions[Key::F4] = { 649, 0, 161, 130 };
	keyRegions[Key::F5] = { 799, 0, 161, 130 };
	keyRegions[Key::F6] = { 959, 0, 161, 130 };
	keyRegions[Key::F7] = { 1119, 0, 161, 130 };
	keyRegions[Key::F8] = { 1279, 0, 161, 130 };
	keyRegions[Key::F9] = { 1439, 0, 161, 130 };
	keyRegions[Key::F10] = { 1559, 0, 161, 130 };
	keyRegions[Key::F11] = { 1759, 0, 161, 130 };
	keyRegions[Key::F12] = { 1919, 0, 161, 130 };
	keyRegions[Key::PrintScreen] = { 2079, 0, 161, 130 };
	keyRegions[Key::Pause] = { 2239, 0, 161, 130 };
	keyRegions[Key::Delete] = { 2399, 0, 160, 130 };

	// ~ row
	keyRegions[Key::Tilde] = { 0, 261, 160, 130 };
	keyRegions[Key::One] = { 159, 261, 161, 130 };
	keyRegions[Key::Two] = { 319, 261, 161, 130 };
	keyRegions[Key::Three] = { 479, 261, 161, 130 };
	keyRegions[Key::Four] = { 639, 261, 161, 130 };
	keyRegions[Key::Five] = { 799, 261, 161, 130 };
	keyRegions[Key::Six] = { 959, 0, 161, 130 };
	keyRegions[Key::Seven] = { 1119, 261, 161, 130 };
	keyRegions[Key::Eight] = { 1279, 261, 161, 130 };
	keyRegions[Key::Nine] = { 1439, 261, 161, 130 };
	keyRegions[Key::Zero] = { 1599, 261, 161, 130 };
	keyRegions[Key::Minus] = { 1759, 261, 161, 130 };
	keyRegions[Key::Equals] = { 1919, 261, 161, 130 };
	keyRegions[Key::Backspace] = { 2079, 261, 161, 130 };
	keyRegions[Key::Home] = { 2399, 261, 160, 130 };

	// Tab row
	keyRegions[Key::Tab] = { 0, 522, 320, 130 };
	keyRegions[Key::Q] = { 319, 522, 161, 130 };
	keyRegions[Key::W] = { 479, 522, 161, 130 };
	keyRegions[Key::E] = { 639, 522, 161, 130 };
	keyRegions[Key::R] = { 799, 522, 161, 130 };
	keyRegions[Key::T] = { 959, 522, 161, 130 };
	keyRegions[Key::Y] = { 1119, 522, 161, 130 };
	keyRegions[Key::U] = { 1279, 522, 161, 130 };
	keyRegions[Key::I] = { 1439, 522, 161, 130 };
	keyRegions[Key::O] = { 1599, 522, 161, 130 };
	keyRegions[Key::P] = { 1759, 522, 161, 130 };
	keyRegions[Key::LBracket] = { 1919, 522, 161, 130 };
	keyRegions[Key::RBracket] = { 2079, 522, 161, 130 };
	keyRegions[Key::Backslash] = { 2239, 522, 161, 130 };
	keyRegions[Key::PageUp] = { 2399, 522, 160, 130 };

	//Caps Lock row
	keyRegions[Key::CapsLock] = { 0, 783, 320, 130 };
	keyRegions[Key::A] = { 319, 783, 161, 130 };
	keyRegions[Key::S] = { 479, 783, 161, 130 };
	keyRegions[Key::D] = { 639, 783, 161, 130 };
	keyRegions[Key::F] = { 799, 783, 161, 130 };
	keyRegions[Key::G] = { 959, 783, 161, 130 };
	keyRegions[Key::H] = { 1119, 783, 161, 130 };
	keyRegions[Key::J] = { 1279, 783, 161, 130 };
	keyRegions[Key::K] = { 1439, 783, 161, 130 };
	keyRegions[Key::L] = { 1599, 783, 161, 130 };
	keyRegions[Key::Semicolon] = { 1759, 783, 161, 130 };
	keyRegions[Key::Quote] = { 1919, 783, 161, 130 };
	keyRegions[Key::Enter] = { 2079, 783, 161, 130 };
	keyRegions[Key::PageDown] = { 2399, 783, 160, 130 };

	// Shift row
	keyRegions[Key::LShift] = { 0, 1044, 320, 130 };
	keyRegions[Key::Z] = { 319, 1044, 161, 130 };
	keyRegions[Key::X] = { 479, 1044, 161, 130 };
	keyRegions[Key::C] = { 639, 1044, 161, 130 };
	keyRegions[Key::V] = { 799, 1044, 161, 130 };
	keyRegions[Key::B] = { 959, 1044, 161, 130 };
	keyRegions[Key::N] = { 1119, 1044, 161, 130 };
	keyRegions[Key::M] = { 1279, 1044, 161, 130 };
	keyRegions[Key::Comma] = { 1439, 1044, 161, 130 };
	keyRegions[Key::Period] = { 1599, 1044, 161, 130 };
	keyRegions[Key::Forwardslash] = { 1759, 1044, 161, 130 };
	keyRegions[Key::RShift] = { 1919, 1044, 321, 130 };
	keyRegions[Key::Up] = { 2239, 1044, 161, 132 };
	keyRegions[Key::End] = { 1399, 1044, 160, 130 };

	// Control row
	keyRegions[Key::LControl] = { 0, 1306, 161, 130 };
	keyRegions[Key::Windows] = { 159, 1306, 161, 130 };
	keyRegions[Key::LAlt] = { 319, 1306, 161, 130 };
	keyRegions[Key::Spacebar] = { 479, 1306, 481, 130 };
	keyRegions[Key::RAlt] = { 959, 1306, 161, 130 };
	keyRegions[Key::Function] = { 1119, 1306, 161, 130 };
	keyRegions[Key::RControl] = { 1279, 1306, 161, 130 };
	keyRegions[Key::Left] = { 1439, 1306, 161, 130 };
	keyRegions[Key::Down] = { 1599, 1306, 161, 130 };
	keyRegions[Key::Right] = { 1759, 1306, 161, 130 };
}

void Init::KeyStates(std::map<std::string, KeyState>& keyStates, GameWrapper* gameWrapper)
{
	for (const auto& action : relevantActions) { // Iterate through relevantActions
		int keyIndex = gameWrapper->GetFNameIndexByString(action); // Use action name directly
		keyStates[action] = { keyIndex, false }; // Initialize with key index and not pressed
		//LOG("[KBMOverlay] Initialized Key '{}' with index {}", action, keyIndex);

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


// Function to dynamically assign key regions to actions 
void Assign::ActionRegions(
	const std::map<std::string, std::string>& actionKeyMap,
	const std::map<std::string, Rect>& keyRegions,
	std::map<std::string, std::shared_ptr<Rect>>& actionRegions
) {
	LOG("[KBMOverlay] AssignActionRegions called.");

	for (const auto& [action, key] : actionKeyMap) {
		if (key.empty()) {
			LOG("[KBMOverlay] Skipping action '{}': Key is empty.", action);
			actionRegions[action] = nullptr;
			continue;
		}

		auto it = keyRegions.find(key);
		if (it != keyRegions.end()) {
			actionRegions[action] = std::make_shared<Rect>(it->second);
			//LOG("[KBMOverlay] Mapped action '{}' to key '{}' with Region: x={}, y={}, width={}, height={}",
			//	action, key, it->second.x, it->second.y, it->second.width, it->second.height);
		}
		else {
			LOG("[KBMOverlay] No region found for action '{}' with key '{}'", action, key);
			actionRegions[action] = nullptr;
		}
	}
}
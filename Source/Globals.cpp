#include "pch.h"
#include "Globals.h"
#include "Keys.h"

std::shared_ptr<int> offsetBy = std::make_shared<int>(131);

std::shared_ptr<int> gColorIndex = std::make_shared<int>(0);

std::shared_ptr<int> gLayoutIndex = std::make_shared<int>(0);

std::shared_ptr<bool> enableActionTitles = std::make_shared<bool>(false);

std::shared_ptr<bool> enableOverlay = std::make_shared<bool>(true);

std::shared_ptr<bool> gUseMouseOverlay = std::make_shared<bool>(false);

std::shared_ptr<Vector2> ScreenSize = std::make_shared<Vector2>();

std::shared_ptr<float>keyboardScaleFactor = std::make_shared<float>(1.0f);
std::shared_ptr<Vector2>keyboardCanvasPosition = std::make_shared<Vector2>(0, 0);

std::shared_ptr<float>mouseScaleFactor = std::make_shared<float>(.56f);
std::shared_ptr<Vector2>mouseCanvasPosition = std::make_shared<Vector2>(390, 0);

std::shared_ptr<float> parentScaleFactor = std::make_shared<float>(0.5f);
std::shared_ptr<Vector2> parentCanvasPosition = std::make_shared<Vector2>(40, 840);

std::shared_ptr<std::string> ForwardKey = std::make_shared<std::string>();
std::shared_ptr<std::string> ReverseKey = std::make_shared<std::string>();

std::shared_ptr<std::string> LookUpKey = std::make_shared<std::string>();
std::shared_ptr<std::string> LookDownKey = std::make_shared<std::string>();
std::shared_ptr<std::string> LookRightKey = std::make_shared<std::string>();
std::shared_ptr<std::string> LookLeftKey = std::make_shared<std::string>();


std::shared_ptr<std::string> SteerRKey = std::make_shared<std::string>();
std::shared_ptr<std::string> SteerLKey = std::make_shared<std::string>();

std::shared_ptr<std::string> YawRKey = std::make_shared<std::string>();
std::shared_ptr<std::string> YawLKey = std::make_shared<std::string>();

std::shared_ptr<std::string> PitchDownKey = std::make_shared<std::string>();
std::shared_ptr<std::string> PitchUpKey = std::make_shared<std::string>();

std::shared_ptr<std::string> ARRKey = std::make_shared<std::string>();
std::shared_ptr<std::string> ARLKey = std::make_shared<std::string>();

std::shared_ptr<std::string> BoostKey = std::make_shared<std::string>();

std::shared_ptr<std::string> JumpKey = std::make_shared<std::string>();

std::shared_ptr<std::string> HandbreakKey = std::make_shared<std::string>();

std::shared_ptr<std::string> BallCamKey = std::make_shared<std::string>();

std::shared_ptr<std::string> FreeRollKey = std::make_shared<std::string>();

std::shared_ptr<std::string> RearCamKey = std::make_shared<std::string>();

std::shared_ptr<std::string> UsePickupKey = std::make_shared<std::string>();

std::shared_ptr<std::string> NextPickupKey = std::make_shared<std::string>();

std::shared_ptr<std::string> GrabKey = std::make_shared<std::string>();

std::shared_ptr<std::string> MenuKey = std::make_shared<std::string>();

std::shared_ptr<std::string> ScoreboardKey = std::make_shared<std::string>();

std::shared_ptr<std::string> ChatKey = std::make_shared<std::string>();

std::shared_ptr<std::string> TeamChatKey = std::make_shared<std::string>();

std::shared_ptr<std::string> PartyChatKey = std::make_shared<std::string>();

std::shared_ptr<std::string> ChatPreset1Key = std::make_shared<std::string>();
std::shared_ptr<std::string> ChatPreset2Key = std::make_shared<std::string>();
std::shared_ptr<std::string> ChatPreset3Key = std::make_shared<std::string>();
std::shared_ptr<std::string> ChatPreset4Key = std::make_shared<std::string>();

std::shared_ptr<std::string> PushToTalkKey = std::make_shared<std::string>();

std::shared_ptr<std::string> ResetTrainingKey = std::make_shared<std::string>();

ImVec2 GetCustomOffset(const std::string& key) {
	if (key == Key::Spacebar) {
		return (*gLayoutIndex == 0) ? ImVec2(65.0f, 45.0f) : ImVec2(195.0f, 45.0f);
	}
	else if (
		key == Key::Backspace ||
		key == Key::Tab ||
		key == Key::CapsLock ||
		key == Key::Enter ||
		key == Key::LShift ||
		key == Key::RShift
		) {
		return ImVec2(32.5f, 45.0f);
	}
	if (*gLayoutIndex == 0)
	{
		if (key == Mouse::LeftMouseButton)
		{
			return ImVec2(-690.0f, 30.0f);
		}
		else if (key == Mouse::RightMouseButton)
		{
			return ImVec2(-640.0f, 30.0f);
		}
		else if (key == Mouse::ThumbMouseButton2)
		{
			return ImVec2(-900.0f, 160.0f);
		}
		else if (key == Mouse::ThumbMouseButton)
		{
			return ImVec2(-900.0f, 200.0f);
		}
		else if (key == Mouse::MiddleMouseButton)
		{
			return ImVec2(-700.0f, 90.0f);
		}
		else if (key == Mouse::MouseScrollUp)
		{
			return ImVec2(10000, 10000);
		}
		else if (key == Mouse::MouseScrollDown)
		{
			return ImVec2(10000, 10000);
		}

		return ImVec2(0.0f, 45.0f); // Default offset
	}
	else {
		if (key == Mouse::LeftMouseButton)
		{
			return ImVec2(-1535.0f, -140.0f);
		}
		else if (key == Mouse::RightMouseButton)
		{
			return ImVec2(-1525.0f, -140.0f);
		}
		else if (key == Mouse::ThumbMouseButton2)
		{
			return ImVec2(-1680.0f, -90.0f);
		}
		else if (key == Mouse::ThumbMouseButton)
		{
			return ImVec2(-1680.0f, -70.0f);
		}
		else if (key == Mouse::MiddleMouseButton)
		{
			return ImVec2(-1565.0f, -110.0f);
		}
		else if (key == Mouse::MouseScrollUp)
		{
			return ImVec2(10000, 10000);
		}
		else if (key == Mouse::MouseScrollDown)
		{
			return ImVec2(10000, 10000);
		}
		return ImVec2(0.0f, 45.0f); // Default offset
	}
}


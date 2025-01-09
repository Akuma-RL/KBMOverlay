#include "pch.h"
#include "Globals.h"

std::shared_ptr<int> offsetBy = std::make_shared<int>(131);

std::shared_ptr<int> gSelectedIndex = std::make_shared<int>(0);

std::shared_ptr<int> gLayoutIndex = std::make_shared<int>(0);

std::shared_ptr<bool> enableOverlay = std::make_shared<bool>(false);

std::shared_ptr<bool> gUseMouseOverlay = std::make_shared<bool>(false);

std::shared_ptr<Vector2> ScreenSize = std::make_shared<Vector2>();

std::shared_ptr<float>overallScaleFactor = std::make_shared<float>(.5f);

std::shared_ptr<Vector2>canvasPosition = std::make_shared<Vector2>(50, 860);

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

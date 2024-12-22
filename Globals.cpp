#include "pch.h"
#include "Globals.h"


std::shared_ptr<bool> enableOverlay = std::make_shared<bool>(false);

std::shared_ptr<Vector2> ScreenSize = std::make_shared<Vector2>();

std::shared_ptr<std::string> ForwardKey = std::make_shared<std::string>();
std::shared_ptr<std::string> ReverseKey = std::make_shared<std::string>();
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
std::shared_ptr<std::string> ScoreboardKey = std::make_shared<std::string>();
#pragma once
#include "bakkesmod/plugin/bakkesmodplugin.h"

namespace fs = std::filesystem;

extern std::shared_ptr<bool> enableOverlay;

extern std::shared_ptr<Vector2> ScreenSize;

extern std::shared_ptr <std::string>ForwardKey;
extern std::shared_ptr <std::string>ReverseKey;
extern std::shared_ptr <std::string>SteerRKey;
extern std::shared_ptr <std::string>SteerLKey;
extern std::shared_ptr <std::string>YawRKey;
extern std::shared_ptr <std::string>YawLKey;
extern std::shared_ptr <std::string>PitchDownKey;
extern std::shared_ptr <std::string>PitchUpKey;
extern std::shared_ptr <std::string>ARRKey;
extern std::shared_ptr <std::string>ARRKey;
extern std::shared_ptr <std::string>ARLKey;
extern std::shared_ptr <std::string>BoostKey;
extern std::shared_ptr <std::string>JumpKey;
extern std::shared_ptr <std::string>HandbreakKey;
extern std::shared_ptr <std::string>BallCamKey;
extern std::shared_ptr <std::string>FreeRollKey;
extern std::shared_ptr <std::string>RearCamKey;
extern std::shared_ptr <std::string>ScoreboardKey;
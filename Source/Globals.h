#pragma once
#include "bakkesmod/plugin/bakkesmodplugin.h"

namespace fs = std::filesystem;



extern std::shared_ptr<int> offsetBy;

extern std::shared_ptr<int> gLayoutIndex;

extern std::shared_ptr<int> gColorIndex;


extern std::shared_ptr<bool> enableOverlay;

extern std::shared_ptr<bool> enableActionTitles;

extern std::shared_ptr<bool> gUseMouseOverlay;

extern std::shared_ptr<Vector2> ScreenSize;



extern std::shared_ptr<float>keyboardScaleFactor;
extern std::shared_ptr<Vector2>keyboardCanvasPosition;

extern std::shared_ptr<float>mouseScaleFactor;
extern std::shared_ptr<Vector2>mouseCanvasPosition;

extern std::shared_ptr<float> parentScaleFactor;
extern std::shared_ptr<Vector2> parentCanvasPosition;


extern std::shared_ptr <std::string>ForwardKey;
extern std::shared_ptr <std::string>ReverseKey;

extern std::shared_ptr <std::string>LookUpKey;
extern std::shared_ptr <std::string>LookDownKey;
extern std::shared_ptr <std::string>LookRightKey;
extern std::shared_ptr <std::string>LookLeftKey;

extern std::shared_ptr <std::string>SteerRKey;
extern std::shared_ptr <std::string>SteerLKey;

extern std::shared_ptr <std::string>YawRKey;
extern std::shared_ptr <std::string>YawLKey;

extern std::shared_ptr <std::string>PitchDownKey;
extern std::shared_ptr <std::string>PitchUpKey;

extern std::shared_ptr <std::string>ARRKey;
extern std::shared_ptr <std::string>ARLKey;

extern std::shared_ptr <std::string>BoostKey;

extern std::shared_ptr <std::string>JumpKey;

extern std::shared_ptr <std::string>HandbreakKey;

extern std::shared_ptr <std::string>BallCamKey;

extern std::shared_ptr <std::string>FreeRollKey;

extern std::shared_ptr <std::string>RearCamKey;

extern std::shared_ptr <std::string>ScoreboardKey;

extern std::shared_ptr <std::string>UsePickupKey;

extern std::shared_ptr <std::string>NextPickupKey;

extern std::shared_ptr <std::string>GrabKey;

extern std::shared_ptr <std::string>MenuKey;

extern std::shared_ptr <std::string>ScoreboardKey;

extern std::shared_ptr <std::string>ChatKey;

extern std::shared_ptr <std::string>TeamChatKey;

extern std::shared_ptr <std::string>PartyChatKey;

extern std::shared_ptr <std::string>ChatPreset1Key;
extern std::shared_ptr <std::string>ChatPreset2Key;
extern std::shared_ptr <std::string>ChatPreset3Key;
extern std::shared_ptr <std::string>ChatPreset4Key;

extern std::shared_ptr <std::string>PushToTalkKey;

extern std::shared_ptr <std::string>ResetTrainingKey;

extern std::map<std::string, ImVec2> keyPositions;
extern ImVec2 GetCustomOffset(const std::string& key);
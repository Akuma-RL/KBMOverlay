#pragma once

#include "GuiBase.h"
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

#include "Keys.h"

#include "version.h"

constexpr auto plugin_version = stringify(VERSION_MAJOR) "." stringify(VERSION_MINOR) "." stringify(VERSION_PATCH) "." stringify(VERSION_BUILD);

class Render;

class KBMOverlay : public BakkesMod::Plugin::BakkesModPlugin
	, public SettingsWindowBase // Uncomment if you wanna render your own tab in the settings menu
	//,public PluginWindowBase // Uncomment if you want to render your own plugin window
{
public:

	std::mutex imageMutex; // Mutex to synchronize image loading

	float scaleFactor = 2.0f; // Scale down the image by half

	std::set<std::string> pressedKeys;              // Keys currently pressed

	std::map<std::string, KeyState> keyStates;
	std::chrono::steady_clock::time_point lastLogTime;
	std::shared_ptr<ImageWrapper> keyboardImage;

	std::map<std::string, ImVec2> actionPositions;

	std::map<std::string, std::string> actionKeyMap;
	std::vector<std::string> mouseBinds;

	std::map<std::string, Rect> actionTitles;


	std::map<std::string, Rect> keyRegions;
	std::map<std::string, ImVec2> keyPositions;

	std::map<std::string, std::shared_ptr<Rect>> actionRegions;


	std::string cfgFile = (gameWrapper->GetDataFolder() / "KBMOverlay" / "kbmbinds.cfg").string();

	std::string settingsFile = (gameWrapper->GetDataFolder() / "KBMOverlay" / "settings.cfg").string();

	void onLoad() override;
	void onUnload() override;
	void RenderSettings() override;

	void SetImage();

	void UpdateLayout();

	void onTick(std::string eventName);

	void UpdatePressedKeys();
	void RegisterCVAR();

	std::map<std::string, std::shared_ptr<ImageWrapper>> preloadedImages;

private:
};
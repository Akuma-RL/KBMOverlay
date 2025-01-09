#pragma once

class Config
{
public:
	void SetupConfigFile();
	void ExportBindsToFile();
	void ReloadBindsFromFile();
	bool isConfigCorrupted(const std::filesystem::path& filePath);
	void SaveSettingsToFile();
	void LoadSettingsFromFile();
};
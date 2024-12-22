#pragma once

class Config
{
public:
	void SetupConfigFile();
	void exportBindsToFile();
	void reloadBindsFromFile();
	bool isConfigCorrupted(const std::filesystem::path& filePath);
};
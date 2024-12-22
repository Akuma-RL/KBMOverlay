#pragma once
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "Utils.h"
#include"Globals.h"

class KBMOverlay;

class Render {
public:
	void OnKeyPressed(KBMOverlay* plugin, const std::string& key);
	void OnKeyReleased(KBMOverlay* plugin, const std::string& key);
	bool IsPlaceholderRegion(const Rect& region, float scaleFactor);
	Rect GetKeyRegion(KBMOverlay* plugin, const std::string& actionKey);
	void RenderCanvas(KBMOverlay* plugin, CanvasWrapper& canvas);
};
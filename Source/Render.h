#pragma once
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "Utils.h"
#include"Globals.h"

class KBMOverlay;

class Render {
public:
	bool IsPlaceholderRegion(const Rect& region, float scaleFactor);
	Rect GetKeyRegion(KBMOverlay* plugin, const std::string& actionKey);
	void RenderCanvas(KBMOverlay* plugin, CanvasWrapper& canvas);
	void RenderKeyboardCanvas(KBMOverlay* plugin, CanvasWrapper& canvas);
	void RenderMouseCanvas(KBMOverlay* plugin, CanvasWrapper& canvas);
};
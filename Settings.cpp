#include "pch.h"
#include "Settings.h"
#include "Globals.h"

Settings settings;

void Settings::RenderSettings() {
	ImGui::TextUnformatted("Overlay for full KBM players, or keyboard only players!");

	static bool overlayEnabled = *enableOverlay;

	if (ImGui::Checkbox("Enable the Overlay", &overlayEnabled)) {
		*enableOverlay = overlayEnabled;
	}
	if (ImGui::IsItemHovered())
	{
		ImGui::SetTooltip("On/Off to Enable or Disable the Overlay");
	}
}
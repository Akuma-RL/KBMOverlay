#include "pch.h"
#include "Settings.h"
#include "Globals.h"
#include "KBMOverlay.h"

Settings settings;
KBMOverlay kbml;

void Settings::RenderSettings() {

	ImGui::TextUnformatted("Overlay for KBM players, or Keyboard only players!");

	static bool overlayEnabled = *enableOverlay;

	if (ImGui::Checkbox("Enable the Overlay", &overlayEnabled)) {
		*enableOverlay = overlayEnabled;
	}
	if (ImGui::IsItemHovered())
	{
		ImGui::SetTooltip("On/Off to Enable or Disable the Overlay");
	}


	// Size Slider for image
	ImGui::TextUnformatted("Overall Size Slider");

	static float staticScale = *overallScaleFactor;
	float scale = *overallScaleFactor;
	if (ImGui::SliderFloat("Text Size", &scale, .501f, 2.0f)) {
		*overallScaleFactor = scale;
	}
	if (ImGui::IsItemHovered()) {
		std::string hoverTextSize = "Overlay scale is " + std::to_string(scale);
		ImGui::SetTooltip(hoverTextSize.c_str());
	}

	// image X position
	ImGui::TextUnformatted("Overlay Position");

	Vector2F screen = *ScreenSize;

	static Vector2F staticCanvas = *canvasPosition;
	Vector2F canvas = *canvasPosition;
	if (ImGui::SliderFloat("Horizontal Position", &canvas.X, 0.0f, screen.X)) {
		*canvasPosition = Vector2F(canvas.X, canvas.Y);
	}
	if (ImGui::IsItemHovered()) {
		std::string hoverXText = "Overlay X position is " + std::to_string(canvas.X);
		ImGui::SetTooltip(hoverXText.c_str());
	}
	// image Y position
	if (ImGui::SliderFloat("Vertical Position", &canvas.Y, 0.0f, screen.Y)) {
		*canvasPosition = Vector2F(canvas.X, canvas.Y);
	}
	if (ImGui::IsItemHovered()) {
		std::string hoverYText = "Overlay Y position is " + std::to_string(canvas.Y);
		ImGui::SetTooltip(hoverYText.c_str());
	}

	// reset sliders to default
	if (ImGui::Button("Reset Defaults")) {
		canvas = staticCanvas;
		scale = staticScale;
	}

	ImGui::TextUnformatted("Overlay Color Settings");

	// Dropdown for selecting color
	static int selectedIndex = 0; // Track the selected index
	std::vector<std::string> colorOptions = { "Red", "Orange", "Yellow", "Green", "Teal", "Cyan", "Blue", "Purple", "Pink", "Bubblegum", "Custom" };

	if (ImGui::BeginCombo("Select Color", colorOptions[selectedIndex].c_str())) {
		for (int i = 0; i < colorOptions.size(); ++i) {
			bool isSelected = (selectedIndex == i);
			if (ImGui::Selectable(colorOptions[i].c_str(), isSelected)) {
				selectedIndex = i;

				// Update keyboard and mouse images
				kbml.SetKeyboardAndMouseImage(colorOptions[selectedIndex]);
			}

			if (isSelected) {
				ImGui::SetItemDefaultFocus();
			}
		}
		ImGui::EndCombo();
	}
}
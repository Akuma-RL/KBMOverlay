#include "pch.h"
#include "Settings.h"
#include "Globals.h"
#include "KBMOverlay.h"

Settings settings;
KBMOverlay kbml;

void Settings::RenderSettings() {
	ImGui::TextUnformatted("Overlay for KBM players, or Keyboard only players!");

	ImGui::Text("Select Overlay Profile:");

	const char* profileOptions[] = { "Full Keyboard", "Recommended" };
	static int selectedProfile = static_cast<int>(kbml.activeProfileType);

	if (ImGui::Combo("Select Profile", &selectedProfile, profileOptions, IM_ARRAYSIZE(profileOptions))) {
		kbml.SetProfile(static_cast<ProfileType>(selectedProfile));
	}

	// Enable/Disable overlay
	static bool overlayEnabled = *enableOverlay;
	if (ImGui::Checkbox("Enable the Overlay", &overlayEnabled)) {
		*enableOverlay = overlayEnabled;
	}
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("On/Off to Enable or Disable the Overlay");
	}

	// Size slider for image scaling
	ImGui::TextUnformatted("Overall Size Slider");

	if (ImGui::SliderFloat("Text Size", overallScaleFactor.get(), .501f, 2.0f)) {
		std::string hoverTextSize = "Overlay scale is " + std::to_string(*overallScaleFactor);
		if (ImGui::IsItemHovered()) {
			ImGui::SetTooltip(hoverTextSize.c_str());
		}
	}

	// Canvas position sliders
	ImGui::TextUnformatted("Overlay Position");

	Vector2F screen = *ScreenSize;

	if (ImGui::SliderFloat("Horizontal Position", &(*canvasPosition).X, 0.0f, screen.X)) {
		// No need to assign back to canvasPosition, changes are directly applied
	}
	if (ImGui::IsItemHovered()) {
		std::string hoverXText = "Overlay X position is " + std::to_string((*canvasPosition).X);
		ImGui::SetTooltip(hoverXText.c_str());
	}

	if (ImGui::SliderFloat("Vertical Position", &(*canvasPosition).Y, 0.0f, screen.Y)) {
		// No need to assign back to canvasPosition, changes are directly applied
	}
	if (ImGui::IsItemHovered()) {
		std::string hoverYText = "Overlay Y position is " + std::to_string((*canvasPosition).Y);
		ImGui::SetTooltip(hoverYText.c_str());
	}

	// Reset sliders to defaults
	if (ImGui::Button("Reset Defaults")) {
		*canvasPosition = Vector2F(1.f, 1.f);  // Replace with actual default values
		*overallScaleFactor = .6f;          // Replace with actual default scale
	}
	//// Dropdown for selecting color
	//static int selectedIndex = 0; // Track the selected index
	//std::vector<std::string> colorOptions = { "Black", "Red", "Orange", "Yellow", "Green", "Teal", "Cyan", "Blue", "Purple", "Pink", "Bubblegum", "Custom" };

	//if (ImGui::BeginCombo("Select Color", colorOptions[selectedIndex].c_str())) {
	//	for (int i = 0; i < colorOptions.size(); ++i) {
	//		bool isSelected = (selectedIndex == i);
	//		if (ImGui::Selectable(colorOptions[i].c_str(), isSelected)) {
	//			selectedIndex = i;

	//			// Update image
	//			kbml.SetImage(colorOptions[selectedIndex]);
	//		}

	//		if (isSelected) {
	//			ImGui::SetItemDefaultFocus();
	//		}
	//	}
	//	ImGui::EndCombo();
	//}
}
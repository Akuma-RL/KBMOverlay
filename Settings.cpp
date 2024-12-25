#include "pch.h"
#include "Settings.h"
#include "Globals.h"
#include "KBMOverlay.h"

Settings settings;
KBMOverlay kbml;

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
	ImGui::TextUnformatted("Speed Text Position");

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

	//ImGui::TextUnformatted("Keyboard Overlay Settings");

	//// Dropdown to select keyboard image
	//static int selectedIndex = 0; // Track the currently selected index
	//std::vector<std::string> imageNames = {
	//	"keyboard_red.png",
	//	"keyboard_orange.png",
	//	"keyboard_yellow.png",
	//	"keyboard_green.png",
	//	"keyboard_teal.png",
	//	"keyboard_cyan.png",
	//	"keyboard_blue.png",
	//	"keyboard_purple.png",
	//	"keyboard_pink.png",
	//	"keyboard_bubblegum.png",
	//	"keyboard_custom.png"
	//};

	//// Show the dropdown
	//if (ImGui::BeginCombo("Select Keyboard Image", imageNames[selectedIndex].c_str())) {
	//	for (int i = 0; i < imageNames.size(); ++i) {
	//		bool isSelected = (selectedIndex == i);
	//		if (ImGui::Selectable(imageNames[i].c_str(), isSelected)) {
	//			selectedIndex = i;

	//			// Load the selected image when picked
	//			kbml.SetKeyboardImage(imageNames[selectedIndex]);
	//		}

	//		if (isSelected) {
	//			ImGui::SetItemDefaultFocus();
	//		}
	//	}
	//	ImGui::EndCombo();
	//}
}
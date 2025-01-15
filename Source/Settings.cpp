#include "pch.h"
#include "Settings.h"
#include "Globals.h"
#include "KBMOverlay.h"
#include "Config.h"

Settings settings;
KBMOverlay kbml;
Config cfgl;

void Settings::RenderSettings() {

	// Display the current image scale as a percentage
	static int parentScale = static_cast<int>(*parentScaleFactor * 100.0f); // Convert float to int for display
	static int keyboardScale = static_cast<int>(*keyboardScaleFactor * 100.0f); // Convert float to int for display
	static int mouseScale = static_cast<int>(*mouseScaleFactor * 100.0f); // Convert float to int for display

	ImGui::TextUnformatted("Overlay for KBM players, or Keyboard only players!");

	ImGui::TextUnformatted("");

	// Enable/Disable overlay
	static bool overlayEnabled = *enableOverlay;
	if (ImGui::Checkbox("Enable the Overlay", &overlayEnabled)) {
		*enableOverlay = overlayEnabled;
		cfgl.SaveSettingsToFile(); // Save on change
	}
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("On/Off to Enable or Disable the Overlay");
	}
	ImGui::SameLine();

	// Toggle Action Titles
	static bool showTitles = *enableActionTitles;
	if (ImGui::Checkbox("Show Action Titles", &showTitles)) {
		*enableActionTitles = showTitles;
		kbml.UpdateLayout();
		cfgl.SaveSettingsToFile(); // Save the setting
	}
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("Toggle to show or hide action titles on the overlay.");
	}

	// Dropdown for selecting color
	ImGui::PushItemWidth(110);
	std::vector<std::string> layoutOptions = { "Recommended", "Actions", "Full Keyboard" };
	static int layoutIndex = *gLayoutIndex; // Track the selected index

	if (ImGui::BeginCombo("Select Layout", layoutOptions[layoutIndex].c_str())) {
		for (int i = 0; i < layoutOptions.size(); ++i) {
			bool isSelected = (layoutIndex == i);
			if (ImGui::Selectable(layoutOptions[i].c_str(), isSelected)) {
				layoutIndex = i;
				*gLayoutIndex = layoutIndex;

				Init::KeyPositions(kbml.keyPositions);  // Reinitialize KeyPositions for the new layout

				kbml.UpdateLayout();                    // Recalculate positions for the new layout

				if (*enableActionTitles) {
					parentScale = 75;
					*parentScaleFactor = 0.75f;

					if (*gLayoutIndex == 0) {
						*keyboardScaleFactor = 1.0f;
						keyboardScale = 100;
						*mouseScaleFactor = 0.56f;
						mouseScale = 56;
						*parentCanvasPosition = Vector2(40, 810);
						*keyboardCanvasPosition = Vector2(0, 0);
						*mouseCanvasPosition = Vector2(390, 0);
					}
					else if (*gLayoutIndex == 1) {
						*keyboardScaleFactor = 1.0f;
						keyboardScale = 100;
						*mouseScaleFactor = 0.75f;
						mouseScale = 75;
						*parentCanvasPosition = Vector2(20, 665);
						*keyboardCanvasPosition = Vector2(0, 0);
						*mouseCanvasPosition = Vector2(1170, 128);
					}
					else if (*gLayoutIndex == 2) {
						*keyboardScaleFactor = 1.0f;
						keyboardScale = 100;
						*mouseScaleFactor = 0.75f;
						mouseScale = 75;
						*parentCanvasPosition = Vector2(20, 665);
						*keyboardCanvasPosition = Vector2(0, 0);
						*mouseCanvasPosition = Vector2(1170, 128);
					}
				}
				else {
					parentScale = 50;
					*parentScaleFactor = 0.6f;

					if (*gLayoutIndex == 0) {
						*keyboardScaleFactor = 1.0f;
						keyboardScale = 100;
						*mouseScaleFactor = 0.56f;
						mouseScale = 56;
						*parentCanvasPosition = Vector2(40, 840);
						*keyboardCanvasPosition = Vector2(0, 0);
						*mouseCanvasPosition = Vector2(390, 0);
					}
					else if (*gLayoutIndex == 1) {
						*keyboardScaleFactor = 1.0f;
						keyboardScale = 100;
						*mouseScaleFactor = 0.75f;
						mouseScale = 75;
						*parentCanvasPosition = Vector2(20, 720);
						*keyboardCanvasPosition = Vector2(0, 0);
						*mouseCanvasPosition = Vector2(1170, 128);
					}
					else if (*gLayoutIndex == 2) {
						*keyboardScaleFactor = 1.0f;
						keyboardScale = 100;
						*mouseScaleFactor = 0.75f;
						mouseScale = 75;
						*parentCanvasPosition = Vector2(20, 720);
						*keyboardCanvasPosition = Vector2(0, 0);
						*mouseCanvasPosition = Vector2(1170, 128);
					}
				}

				cfgl.SaveSettingsToFile();              // Save the updated settings
			}

			if (isSelected) {
				ImGui::SetItemDefaultFocus();
			}
		}
		ImGui::EndCombo();
	}
	ImGui::SameLine();

	// Dropdown for selecting color
	std::vector<std::string> colorOptions = { "Red", "Orange", "Yellow", "Green", "Teal", "Cyan", "Blue", "Purple", "Pink", "Bubblegum", "Black", "Custom" };

	static int selectedIndex = *gColorIndex; // Track the selected index

	if (ImGui::BeginCombo("Select Color", colorOptions[selectedIndex].c_str())) {
		for (int i = 0; i < colorOptions.size(); ++i) {
			bool isSelected = (selectedIndex == i);
			if (ImGui::Selectable(colorOptions[i].c_str(), isSelected)) {
				selectedIndex = i;
				*gColorIndex = selectedIndex;

				// Apply the new selection
				switch (selectedIndex) {
				case 0: *offsetBy = 131; break; // Red
				case 1: *offsetBy = 262; break; // Orange
				case 2: *offsetBy = 393; break; // Yellow
				case 3: *offsetBy = 524; break; // Green
				case 4: *offsetBy = 655; break; // Teal
				case 5: *offsetBy = 786; break; // Cyan
				case 6: *offsetBy = 917; break; // Blue
				case 7: *offsetBy = 1048; break; // Purple
				case 8: *offsetBy = 1179; break; // Pink
				case 9: *offsetBy = 1310; break; // Bubblegum
				case 10: *offsetBy = 1441; break; // Black
				case 11: *offsetBy = 1572; break; // Custom
				default: *offsetBy = 131; break; // Default
				}

				cfgl.SaveSettingsToFile(); // Save the updated settings
			}

			if (isSelected) {
				ImGui::SetItemDefaultFocus();
			}
		}
		ImGui::EndCombo();
	}

	ImGui::PopItemWidth();

	ImGui::TextUnformatted("");

	// Size slider for image scaling
	ImGui::TextUnformatted("Overlay Settings");

	// Dynamically calculate minimum size based on enableActionTitles
	int parentMinSize = (*enableActionTitles) ? 75 : 50;
	Vector2 screen = *ScreenSize;

	ImGui::PushItemWidth(250);

	ImGui::TextUnformatted("Size:"); ImGui::SameLine();
	if (ImGui::SliderInt(" ##1", &parentScale, parentMinSize, 200)) { // Slider range: parentMinSize to 200%
		// Clamp parentScale to the minimum size
		if (parentScale < parentMinSize) {
			parentScale = parentMinSize;
			*parentScaleFactor = static_cast<float>(parentScale) / 100.0f;
		}
		// Update the overallScaleFactor
		*parentScaleFactor = static_cast<float>(parentScale) / 100.0f;

		// Save the new value to the config
		cfgl.SaveSettingsToFile();
	}
	// Display tooltip for the slider
	if (ImGui::IsItemHovered()) {
		std::string hoverTextSize = "Overlay scale is " + std::to_string(parentScale) + "%";
		ImGui::SetTooltip(hoverTextSize.c_str());
	}
	ImGui::SameLine();
	if (ImGui::SliderInt(" ##2", &(*parentCanvasPosition).X, 0, screen.X)) {
		// No need to assign back to canvasPosition, changes are directly applied
		cfgl.SaveSettingsToFile(); // Save on change
	}
	if (ImGui::IsItemHovered()) {
		std::string hoverXText = "Overlay X position is " + std::to_string((*parentCanvasPosition).X);
		ImGui::SetTooltip(hoverXText.c_str());
	}
	ImGui::SameLine();
	ImGui::TextUnformatted("Y:"); ImGui::SameLine();

	if (ImGui::SliderInt(" ##3", &(*parentCanvasPosition).Y, 0, screen.Y)) {
		// No need to assign back to canvasPosition, changes are directly applied
		cfgl.SaveSettingsToFile(); // Save on change
	}
	if (ImGui::IsItemHovered()) {
		std::string hoverYText = "Overlay Y position is " + std::to_string((*parentCanvasPosition).Y);
		ImGui::SetTooltip(hoverYText.c_str());
	}
	ImGui::PopItemWidth();
	if (*enableActionTitles == true && parentScale < parentMinSize) { parentScale = parentMinSize; *parentScaleFactor = static_cast<float>(parentScale) / 100.0f; }

	ImGui::TextUnformatted("");

	ImGui::TextUnformatted("Keyboard Settings");

	ImGui::PushItemWidth(250);

	int keyboardMinSize = (*enableActionTitles) ? 100 : 75;
	// Size slider for keyboard scaling

	ImGui::TextUnformatted("Size:"); ImGui::SameLine();
	if (ImGui::SliderInt(" ##4", &keyboardScale, keyboardMinSize, 200)) { // Slider range: keyboardMinSize to 200%
		// Clamp keyboardScale to the minimum size
		if (keyboardScale < keyboardMinSize) {
			keyboardScale = keyboardMinSize;
			*keyboardScaleFactor = static_cast<float>(keyboardScale) / 100.0f;
		}
		// Update the overallScaleFactor
		*keyboardScaleFactor = static_cast<float>(keyboardScale) / 100.0f;

		// Save the new value to the config
		cfgl.SaveSettingsToFile();
	}
	// Display tooltip for the slider
	if (ImGui::IsItemHovered()) {
		std::string hoverTextSize = "Keyboard scale is " + std::to_string(keyboardScale) + "%";
		ImGui::SetTooltip(hoverTextSize.c_str());
	}
	ImGui::SameLine();
	if (ImGui::SliderInt(" ##5", &(*keyboardCanvasPosition).X, 0, screen.X)) {
		// No need to assign back to canvasPosition, changes are directly applied
		cfgl.SaveSettingsToFile(); // Save on change
	}
	if (ImGui::IsItemHovered()) {
		std::string hoverXText = "Keyboard X position is " + std::to_string((*keyboardCanvasPosition).X);
		ImGui::SetTooltip(hoverXText.c_str());
	}
	ImGui::SameLine();
	ImGui::TextUnformatted("Y:"); ImGui::SameLine();

	if (ImGui::SliderInt(" ##6", &(*keyboardCanvasPosition).Y, 0, screen.Y)) {
		// No need to assign back to canvasPosition, changes are directly applied
		cfgl.SaveSettingsToFile(); // Save on change
	}
	if (ImGui::IsItemHovered()) {
		std::string hoverYText = "Keyboard Y position is " + std::to_string((*keyboardCanvasPosition).Y);
		ImGui::SetTooltip(hoverYText.c_str());
	}
	ImGui::PopItemWidth();

	if (*enableActionTitles == true && keyboardScale < keyboardMinSize) { keyboardScale = keyboardMinSize; *keyboardScaleFactor = static_cast<float>(keyboardScale) / 100.0f; }

	ImGui::TextUnformatted("");

	int mouseMinSize = (*gLayoutIndex == 0) ? 50 : 75;
	//if (*gLayoutIndex == 0) {
	//	mouseMinSize = 50;
	//}
	if (*gUseMouseOverlay == true) {
		ImGui::TextUnformatted("Mouse Settings");

		ImGui::PushItemWidth(250);

		// Size slider for mouse scaling

		ImGui::TextUnformatted("Size:"); ImGui::SameLine();
		if (ImGui::SliderInt(" ##7", &mouseScale, mouseMinSize, 200)) { // Slider range: keyboardMinSize to 200%
			// Clamp keyboardScale to the minimum size
			if (mouseScale < mouseMinSize) {
				mouseScale = mouseMinSize;
				*mouseScaleFactor = static_cast<float>(mouseScale) / 100.0f;
			}
			// Update the overallScaleFactor
			*mouseScaleFactor = static_cast<float>(mouseScale) / 100.0f;

			// Save the new value to the config
			cfgl.SaveSettingsToFile();
		}
		// Display tooltip for the slider
		if (ImGui::IsItemHovered()) {
			std::string hoverTextSize = "Mouse scale is " + std::to_string(mouseScale) + "%";
			ImGui::SetTooltip(hoverTextSize.c_str());
		}
		ImGui::SameLine();
		if (ImGui::SliderInt(" ##8", &(*mouseCanvasPosition).X, 0, screen.X)) {
			// No need to assign back to canvasPosition, changes are directly applied
			cfgl.SaveSettingsToFile(); // Save on change
		}
		if (ImGui::IsItemHovered()) {
			std::string hoverXText = "Mouse X position is " + std::to_string((*mouseCanvasPosition).X);
			ImGui::SetTooltip(hoverXText.c_str());
		}
		ImGui::SameLine();
		ImGui::TextUnformatted("Y:"); ImGui::SameLine();

		if (ImGui::SliderInt(" ##9", &(*mouseCanvasPosition).Y, 0, screen.Y)) {
			// No need to assign back to canvasPosition, changes are directly applied
			cfgl.SaveSettingsToFile(); // Save on change
		}
		if (ImGui::IsItemHovered()) {
			std::string hoverYText = "Mouse Y position is " + std::to_string((*mouseCanvasPosition).Y);
			ImGui::SetTooltip(hoverYText.c_str());
		}
		ImGui::PopItemWidth();
	}
	if (*enableActionTitles == true && mouseScale < mouseMinSize) { mouseScale = mouseMinSize; *mouseScaleFactor = static_cast<float>(mouseScale) / 100.0f; }

	ImGui::TextUnformatted("");

	// Reset sliders to defaults
	if (ImGui::Button("Reset Defaults")) {

		if (*enableActionTitles) {
			parentScale = 75;
			*parentScaleFactor = 0.75f;

			if (*gLayoutIndex == 0) {
				*keyboardScaleFactor = 1.0f;
				keyboardScale = 100;
				*mouseScaleFactor = 0.56f;
				mouseScale = 56;
				*parentCanvasPosition = Vector2(40, 810);
				*keyboardCanvasPosition = Vector2(0, 0);
				*mouseCanvasPosition = Vector2(390, 0);
			}
			else if (*gLayoutIndex == 1) {
				*keyboardScaleFactor = 1.0f;
				keyboardScale = 100;
				*mouseScaleFactor = 0.75f;
				mouseScale = 75;
				*parentCanvasPosition = Vector2(20, 665);
				*keyboardCanvasPosition = Vector2(0, 0);
				*mouseCanvasPosition = Vector2(1170, 128);
			}
			else if (*gLayoutIndex == 2) {
				*keyboardScaleFactor = 1.0f;
				keyboardScale = 100;
				*mouseScaleFactor = 0.75f;
				mouseScale = 75;
				*parentCanvasPosition = Vector2(20, 665);
				*keyboardCanvasPosition = Vector2(0, 0);
				*mouseCanvasPosition = Vector2(1170, 128);
			}
		}
		else {
			parentScale = 50;
			*parentScaleFactor = 0.6f;

			if (*gLayoutIndex == 0) {
				*keyboardScaleFactor = 1.0f;
				keyboardScale = 100;
				*mouseScaleFactor = 0.56f;
				mouseScale = 56;
				*parentCanvasPosition = Vector2(40, 840);
				*keyboardCanvasPosition = Vector2(0, 0);
				*mouseCanvasPosition = Vector2(390, 0);
			}
			else if (*gLayoutIndex == 1) {
				*keyboardScaleFactor = 1.0f;
				keyboardScale = 100;
				*mouseScaleFactor = 0.75f;
				mouseScale = 75;
				*parentCanvasPosition = Vector2(20, 720);
				*keyboardCanvasPosition = Vector2(0, 0);
				*mouseCanvasPosition = Vector2(1170, 128);
			}
			else if (*gLayoutIndex == 2) {
				*keyboardScaleFactor = 1.0f;
				keyboardScale = 100;
				*mouseScaleFactor = 0.75f;
				mouseScale = 75;
				*parentCanvasPosition = Vector2(20, 720);
				*keyboardCanvasPosition = Vector2(0, 0);
				*mouseCanvasPosition = Vector2(1170, 128);
			}
		}

		// Save the updated settings
		cfgl.SaveSettingsToFile();
	}
}
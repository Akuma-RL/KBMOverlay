#include "pch.h"
#include "Settings.h"
#include "Globals.h"
#include "KBMOverlay.h"
#include "Config.h"

Settings settings;
KBMOverlay kbml;
Config cfgl;

void Settings::RenderSettings() {
    ImGui::TextUnformatted("Overlay for KBM players, or Keyboard only players!");

    // Enable/Disable overlay
    static bool overlayEnabled = *enableOverlay;
    if (ImGui::Checkbox("Enable the Overlay", &overlayEnabled)) {
        *enableOverlay = overlayEnabled;
        cfgl.SaveSettingsToFile(); // Save on change
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("On/Off to Enable or Disable the Overlay");
    }

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
    std::vector<std::string> layoutOptions = { "Recommended", "Actions", "Full Keyboard"};
    static int layoutIndex = *gLayoutIndex; // Track the selected index

    if (ImGui::BeginCombo("Select Layout", layoutOptions[layoutIndex].c_str())) {
        for (int i = 0; i < layoutOptions.size(); ++i) {
            bool isSelected = (layoutIndex == i);
            if (ImGui::Selectable(layoutOptions[i].c_str(), isSelected)) {
                layoutIndex = i;
                *gLayoutIndex = layoutIndex;

                Init::KeyPositions(kbml.keyPositions);  // Reinitialize KeyPositions for the new layout

                kbml.UpdateLayout();                    // Recalculate positions for the new layout

                cfgl.SaveSettingsToFile();              // Save the updated settings
            }

            if (isSelected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }

    // Size slider for image scaling
    ImGui::TextUnformatted("Image Size Slider");

    static int imageScale = static_cast<int>(*overallScaleFactor * 100.0f); // Convert float to int for display
    if (ImGui::SliderInt("Image Size", &imageScale, 50, 200)) { // Slider range: 50% to 200%
        *overallScaleFactor = static_cast<float>(imageScale) / 100.0f; // Convert back to float
        cfgl.SaveSettingsToFile(); // Save the new value to the config
    }
    if (ImGui::IsItemHovered()) {
        std::string hoverTextSize = "Image scale is " + std::to_string(imageScale) + "%";
        ImGui::SetTooltip(hoverTextSize.c_str());
    }

    // Canvas position sliders
    ImGui::TextUnformatted("Overlay Position");

    Vector2 screen = *ScreenSize;

    if (ImGui::SliderInt("Horizontal Position", &(*canvasPosition).X, 0, screen.X)) {
        // No need to assign back to canvasPosition, changes are directly applied
        cfgl.SaveSettingsToFile(); // Save on change
    }
    if (ImGui::IsItemHovered()) {
        std::string hoverXText = "Overlay X position is " + std::to_string((*canvasPosition).X);
        ImGui::SetTooltip(hoverXText.c_str());
    }

    if (ImGui::SliderInt("Vertical Position", &(*canvasPosition).Y, 0, screen.Y)) {
        // No need to assign back to canvasPosition, changes are directly applied
        cfgl.SaveSettingsToFile(); // Save on change
    }
    if (ImGui::IsItemHovered()) {
        std::string hoverYText = "Overlay Y position is " + std::to_string((*canvasPosition).Y);
        ImGui::SetTooltip(hoverYText.c_str());
    }

    // Reset sliders to defaults
    if (ImGui::Button("Reset Defaults")) {
        imageScale = 50;
        *overallScaleFactor = .5f;

        if (*gLayoutIndex == 0) {
            *canvasPosition = Vector2(40, 770);
        }
        else if (*gLayoutIndex == 1) {
            *canvasPosition = Vector2(20, 770);
        }
        else if (*gLayoutIndex == 2) {
            *canvasPosition = Vector2(20, 770);
        }
        cfgl.SaveSettingsToFile(); // Save on change
    }

    ImGui::TextUnformatted("Overlay Color Settings");

    // Dropdown for selecting color
    std::vector<std::string> colorOptions = { "Red", "Orange", "Yellow", "Green", "Teal", "Cyan", "Blue", "Purple", "Pink", "Bubblegum", "Black", "Custom" };

    static int selectedIndex = *gSelectedIndex; // Track the selected index

    if (ImGui::BeginCombo("Select Color", colorOptions[selectedIndex].c_str())) {
        for (int i = 0; i < colorOptions.size(); ++i) {
            bool isSelected = (selectedIndex == i);
            if (ImGui::Selectable(colorOptions[i].c_str(), isSelected)) {
                selectedIndex = i;
                *gSelectedIndex = selectedIndex;

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
}
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

    //if (ImGui::TreeNode("Basic"))
    //{
    //    if (ImGui::Begin("table1", 3))
    //    {
    //        for (int row = 0; row < 4; row++)
    //        {
    //            ImGui::TableNextRow();
    //            for (int column = 0; column < 3; column++)
    //            {
    //                ImGui::TableSetColumnIndex(column);
    //                ImGui::Text("Row %d Column %d", row, column);
    //            }
    //        }
    //        ImGui::EndTable();
    //    }
}
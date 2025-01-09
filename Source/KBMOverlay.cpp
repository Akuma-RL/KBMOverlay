#include "pch.h"
#include "KBMOverlay.h"
#include "Globals.h"
#include "Settings.h"
#include "Render.h"
#include "Config.h"
#include "Utils.h"

Render render;
Config cfg;

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;



// Plugin setup
BAKKESMOD_PLUGIN(KBMOverlay, "Keyboard & Mouse Overlay", plugin_version, PLUGINTYPE_FREEPLAY)

void KBMOverlay::onLoad() {
    _globalCvarManager = cvarManager;

    // Initialize screen size
    Vector2 screenSize = gameWrapper->GetScreenSize();
    *ScreenSize = Vector2(screenSize.X, screenSize.Y);
    
    RegisterCVAR();

    cfg.SetupConfigFile();
    cfg.LoadSettingsFromFile();
    cfg.ReloadBindsFromFile();

    Init::Profiles();
    activeProfileType = ProfileType::Recommended; // Set default profile

    // Initialize positions and regions
    Init::ActionPositions(actionPositions);
    Init::MouseActionPositions(mouseActionPositions);

    Init::KeyStates(keyStates, gameWrapper.get());
    gameWrapper->HookEvent("Function Engine.GameViewportClient.Tick",
        std::bind(&KBMOverlay::onTick, this, std::placeholders::_1));

    bool useMouseOverlay = false;

    Init::KeyRegions(keyRegions);
    Init::ActionKeyMap(actionKeyMap);

    // Detect bindings for mouse overlay
    if (actionKeyMap[Action::Jump] == MB::LeftMouseButton ||
        actionKeyMap[Action::Boost] == MB::RightMouseButton ||
        actionKeyMap[Action::Boost] == MB::LeftMouseButton ||
        actionKeyMap[Action::Jump] == MB::RightMouseButton)
    {
        Init::MouseKeyRegions(mouseKeyRegions);
        useMouseOverlay = true;
        *gUseMouseOverlay = useMouseOverlay;
    }

    if (useMouseOverlay) {
        LOG("[KBMOverlay] Mouse overlay enabled.");
        Assign::MouseActionRegions(actionKeyMap, mouseKeyRegions, mouseActionRegions);
    }
    else {
        LOG("[KBMOverlay] Mouse overlay disabled.");
    }

    // Always assign keyboard regions
    Assign::KeyboardActionRegions(actionKeyMap, keyRegions, actionRegions);
    SetImage("");
    // Register canvas rendering
    gameWrapper->RegisterDrawable([this](CanvasWrapper canvas) {
        render.RenderCanvas(this, canvas);
        });

    LOG("[KBMOverlay] Plugin loaded.");
}

void KBMOverlay::SetImage(const std::string& color) {
    // Construct the image path
    std::string imagePath = (gameWrapper->GetDataFolder() / "KBMOverlay" / "kbm.png").string();
    LOG("[KBMOverlay] Constructed image path: {}", imagePath);

    // Check if the image file exists
    if (!std::filesystem::exists(imagePath)) {
        LOG("[KBMOverlay] Image path does not exist: {}", imagePath);
        return;
    }

    // Schedule the image loading and updating on the game thread
    gameWrapper->Execute([this, imagePath, color](GameWrapper* gw) {
        try {
            // Create and load the image
            auto newImage = std::make_shared<ImageWrapper>(imagePath, true, false);
            LOG("[KBMOverlay] Created new ImageWrapper instance on game thread");

            newImage->LoadForCanvas();
            LOG("[KBMOverlay] Called LoadForCanvas on game thread");

            if (newImage->IsLoadedForCanvas()) {
                std::lock_guard<std::mutex> guard(imageMutex); // Lock mutex for thread safety
                keyboardImage = newImage;
                LOG("[KBMOverlay] Successfully switched to new image: kbm_{}.png", color);
            }
            else {
                LOG("[KBMOverlay] Failed to load new image for canvas: kbm_{}.png", color);
            }
        }
        catch (const std::exception& e) {
            LOG("[KBMOverlay] Exception during SetImage on game thread: {}", e.what());
        }
        catch (...) {
            LOG("[KBMOverlay] Unknown exception during SetImage on game thread");
        }
        });
}

void KBMOverlay::UpdatePressedKeys() {
    pressedKeys.clear();

    for (auto& [key, keyState] : keyStates) {
        int keyIndex = keyState.index; // Use stored index to avoid redundant lookups
        bool isCurrentlyPressed = gameWrapper->IsKeyPressed(keyIndex);

        if (isCurrentlyPressed) {
            pressedKeys.insert(key); // Add key to pressed keys
        }

        // Update key state
        keyState.pressed = isCurrentlyPressed;
    }
}

void KBMOverlay::onTick(std::string eventName) {
    if (!gameWrapper->IsInCustomTraining() &&
        (gameWrapper->IsInGame() || gameWrapper->IsInOnlineGame())) {
        for (auto& [key, keyState] : keyStates) {
            // Check if the key is pressed
            bool isCurrentlyPressed = gameWrapper->IsKeyPressed(keyState.index);

            // Update and log state changes
            if (keyState.pressed != isCurrentlyPressed) {
                keyState.pressed = isCurrentlyPressed;
            }
        }
    }
}

void KBMOverlay::RegisterCVAR()
{
    cvarManager->registerCvar("kbm_enable_overlay", "1", "Enable the KBM overlay", true, true, 0, true, 1, true).bindTo(enableOverlay);
}

void KBMOverlay::RenderSettings() {
	settings.RenderSettings();
}

void KBMOverlay::onUnload()
{

}
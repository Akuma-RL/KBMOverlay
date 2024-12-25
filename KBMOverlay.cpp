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
    *ScreenSize = Vector2F(screenSize.X, screenSize.Y);

    // Initialize positions and regions
    Init::ActionPositions(actionPositions);
    Init::MouseActionPositions(mouseActionPositions);

    cfg.SetupConfigFile();

    Init::KeyStates(keyStates, gameWrapper.get());
    gameWrapper->HookEvent("Function Engine.GameViewportClient.Tick",
        std::bind(&KBMOverlay::onTick, this, std::placeholders::_1));

    bool useMouseOverlay = false;

    Init::KeyRegions(keyRegions);
    Init::ActionKeyMap(actionKeyMap);
    Init::KeyStates(keyStates, gameWrapper.get());

    // Detect bindings for mouse overlay
    if (actionKeyMap[Action::Jump] == MB::LeftMouseButton &&
        actionKeyMap[Action::Boost] == MB::RightMouseButton ||
        actionKeyMap[Action::Boost] == MB::LeftMouseButton &&
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

    // Load default keyboard and mouse images
    std::string keyboardPath = (gameWrapper->GetDataFolder() / "KBMOverlay" / "Keyboard" / "keyboard_custom.png").string();
    std::string mousePath = (gameWrapper->GetDataFolder() / "KBMOverlay" / "Mouse" / "mouse_custom.png").string();

    keyboardImage = std::make_shared<ImageWrapper>(keyboardPath, true, false);
    keyboardImage->LoadForCanvas();

    if (useMouseOverlay) {
        mouseImage = std::make_shared<ImageWrapper>(mousePath, true, false);
        mouseImage->LoadForCanvas();
    }

    // Register canvas rendering
    gameWrapper->RegisterDrawable([this](CanvasWrapper canvas) {
        render.RenderCanvas(this, canvas);
        });

    LOG("[KBMOverlay] Plugin loaded.");
}


void KBMOverlay::SetKeyboardAndMouseImage(const std::string& color) {
    // Load keyboard image
    std::string keyboardImagePath = (gameWrapper->GetDataFolder() / "KBMOverlay" / "Keyboard" / ("keyboard_" + color + ".png")).string();
    auto newKeyboardImage = std::make_shared<ImageWrapper>(keyboardImagePath, true, false);
    newKeyboardImage->LoadForCanvas();

    if (newKeyboardImage->IsLoadedForCanvas()) {
        keyboardImage = newKeyboardImage;
        LOG("[KBMOverlay] Switched to keyboard image: keyboard_{}.png", color);
    }
    else {
        LOG("[KBMOverlay] Failed to load keyboard image: keyboard_{}.png", color);
    }

    // Load mouse image if overlay is enabled
    if (*gUseMouseOverlay) {
        std::string mouseImagePath = (gameWrapper->GetDataFolder() / "KBMOverlay" / "Mouse" / ("mouse_" + color + ".png")).string();
        auto newMouseImage = std::make_shared<ImageWrapper>(mouseImagePath, true, false);
        newMouseImage->LoadForCanvas();

        if (newMouseImage->IsLoadedForCanvas()) {
            mouseImage = newMouseImage;
            LOG("[KBMOverlay] Switched to mouse image: mouse_{}.png", color);
        }
        else {
            LOG("[KBMOverlay] Failed to load mouse image: mouse_{}.png", color);
        }
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
                LOG("[KBMOverlay] Key '{}' pressed state changed to {}.", key, isCurrentlyPressed);
            }
        }
    }
}


void KBMOverlay::RenderSettings() {
	settings.RenderSettings();
}

void KBMOverlay::onUnload()
{

}
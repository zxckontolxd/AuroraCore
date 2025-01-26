#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <SFML/Graphics.hpp>

#include "state/manager/stateManager.h"
#include "state/states/mainWindowState.h"
#include "resourceManagers/fontManager.h"

/*
 * core.h - Central component of the AuroraCore Editor
 *
 * This file defines the EditorCore class, which serves as the backbone of the AuroraCore Editor.
 * It is responsible for:
 *  - Managing the state of the editor (idle, loading, ready, or error).
 *  - Loading and unloading project resources, such as textures, scripts, and configuration files.
 *  - Providing an interface for other components (e.g., GUI) to interact with the project's data.
 *
 * The EditorCore class encapsulates all core functionalities required for initializing,
 * loading, and managing the editor's data. It ensures a clean separation of logic from the UI.
 *
 * Usage:
 *  - Initialize the core using the `initialize()` method, passing the configuration file path.
 *  - Load a project using `loadProject()`.
 *  - Use `getState()` to monitor the current state of the editor.
 *
 * This file is a critical part of the AuroraCore Editor and is designed to be extensible
 * for future features and improvements.
 */

class Core
{
private:
    //STATES//
    MainWindowState *mainWindowState;
    //STATES//
    StateManager *stateManager;
    FontManager *fontManager;
public:
    Core();
    ~Core();

    void start();

    //void initialize(std::string path);
    //void loadProject(std::string path);

    //IState *getState();
};

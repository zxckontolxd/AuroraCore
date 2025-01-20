#pragma once

#include <map>
#include "utils/logger/mainLogger.h"
#include "state/istate.h"

/*
 * state_manager.h - Core component for state management
 *
 * This file defines the StateManager class, which acts as the central mechanism
 * for managing application or game states. It provides a system for registering,
 * transitioning, and updating states based on predefined events.
 *
 * Key Concepts:
 * - States:
 *   States must implement the `IState` interface. Each state is responsible for
 *   defining its own behavior and registering possible transitions to other states
 *   using the `registerState` method.
 *
 * - State Transitions:
 *   States register transition events with a string identifier (e.g., "exit").
 *   When a transition is triggered, the `changeState` method is called to handle
 *   the switch to the next state. Transitions are initiated by calling
 *   `IState::changeState` with the event name.
 *
 * - StateManager Responsibilities:
 *   - Maintaining a registry of all possible states.
 *   - Handling transitions between states using `changeState`.
 *   - Continuously updating the current state through its `update` method.
 *
 * How it Works:
 * 1. States register possible transitions:
 *    - Example: `state->registerState("exit", ExitState);`
 *    - Here, "exit" is the string identifier for the transition event.
 * 2. Transitions are triggered from within a state by calling:
 *    - `IState::changeState("exit");`
 * 3. The `StateManager` checks if the current state requests a change by monitoring
 *    the `bool IState::changed` variable during its `update` method.
 * 4. If a change is requested:
 *    - The next state is retrieved via `IState::getState(std::string stateName)`.
 *    - Shared data is passed to the new state using `std::shared_ptr<void**>`.
 *    - The transition is handled by `StateManager::changeState(IState*, std::shared_ptr<void**>)`.
 *
 * Usage:
 * - States should inherit from `IState` and implement required functionality.
 * - Register states with the `StateManager` before initiating the main loop.
 * - Call the `update` method of `StateManager` in the main loop to process state logic
 *   and handle transitions.
 *
 * Example:
 * ```
 * auto manager = std::make_unique<StateManager>();
 * auto menuState = std::make_shared<MenuState>();
 * auto gameState = std::make_shared<GameState>();
 *
 * manager->registerState("menu", menuState);
 * manager->registerState("game", gameState);
 *
 * while (running) {
 *     manager->update();
 * }
 * ```
 *
 * This file is essential for maintaining a clear and organized flow of state-dependent
 * logic in applications or games. It decouples the state logic from the main application
 * loop and provides a flexible system for transitions and shared data.
 */

class StateManager
{
private:
    MainLogger *logger;
    IState *currentState;
    std::map<std::string, IState*> stateMap;
public:
    StateManager(std::string stateName, IState *baseState);
    ~StateManager();

    void registerState(std::string name, IState *state);
    void changeState(std::string name);

    void update();
};

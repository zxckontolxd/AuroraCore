#include "state/manager/stateManager.h"

StateManager::StateManager(std::string stateName, IState *baseState) : currentState(baseState)
{
    logger = MainLogger::get();
    registerState(stateName, baseState);
}

StateManager::~StateManager()
{

}

void StateManager::changeState(std::string name)
{
    char buf[256];
    if(stateMap.find(name) != stateMap.end())
    {
        std::sprintf(buf, "Change to state: %s", name.c_str());
        logger->info(buf);

        currentState->resetChanged();
        currentState = stateMap[name];
    } else {
        std::sprintf(buf, "Cannot find state: %s", name.c_str());
        logger->error(buf);
    }
}

void StateManager::registerState(std::string stateName, IState *state)
{
    if(stateMap.find(stateName) != stateMap.end())
    {
        char buf[256];
        std::sprintf(buf, "Cannot register \"%s\" state", stateName.c_str());
        logger->error(buf);
        return;
    }

    state->setName(stateName);
    stateMap[stateName] = state;
}

void StateManager::update()
{
    if(currentState->getChangedFlag())
    {
        currentState->resetChanged();
        IState* next = currentState->getNextState();
        changeState(next->getName());

    } else {
        currentState->update();
    }
}

sf::RenderWindow* StateManager::getWindow()
{
    return currentState->getWindow();
}

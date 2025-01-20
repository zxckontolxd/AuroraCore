#include "state/istate.h"

IState::IState()
{
    logger = MainLogger::get();
}

void IState::registerState(std::string eventName, IState *state)
{
    if(stateMap.find(eventName) != stateMap.end())
    {
        char buf[256];
        std::sprintf(buf, "Cannot register \"%s\" event", eventName.c_str());
        logger->error(buf);
        return;
    }

    stateMap[eventName] = state;
}

IState* IState::changeState(std::string eventName)
{
    char buf[256];
    std::sprintf(buf, "Call \"%s\" event, change state", eventName.c_str());
    logger->info(buf);

    nextState = stateMap[eventName];
    changed = true;
    return nextState;
}

IState* IState::getNextState()
{
    return nextState;
}

#pragma once

#include <iostream>
#include <map>
#include <cstdio>
#include "utils/logger/mainLogger.h"

/*
 * Its not interface. Its default abstract class.
 * But i like this naming :) I work alone and what will you do to me:? ^^
 * (I planned this class how interface, but i changed my mind)
 */

class IState
{
private:
    MainLogger *logger;
    bool changed = false;
    IState *nextState;
    std::map<std::string, IState*> stateMap;
public:
    IState();

    virtual void update() = 0;

    void registerState(std::string eventName, IState *state);

    IState* changeState(std::string eventName);

    IState* getNextState();
};

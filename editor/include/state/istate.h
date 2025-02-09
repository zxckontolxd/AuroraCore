#pragma once

#include <iostream>
#include <map>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include "utils/logger/mainLogger.h"

/*
 * Its not interface. Its default abstract class.
 * But i like this naming :) I work alone and what will you do to me:? ^^
 * (I planned this class how interface, but i changed my mind)
 */

class IState
{
protected:
    sf::RenderWindow *window;

    MainLogger *logger;
    bool changed = false;
    IState *nextState;
    std::map<std::string, IState*> stateMap;
    std::string name;
public:
    IState();

    virtual void update() = 0;

    void registerState(std::string eventName, IState *state);
    void resetChanged();
    void setName(std::string name);

    bool getChangedFlag();

    IState* changeState(std::string eventName);
    IState* getNextState();

    std::string getName();

    sf::RenderWindow* getWindow();
};

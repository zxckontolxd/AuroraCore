#include "../include/core.h"
#include "utils/logger/mainLogger.h"
#include "state/istate.h"
#include "state/manager/stateManager.h"
#include "core.h"
int main()
{

    MainLogger *logger = MainLogger::get();
    logger->setLevel(logger::Debug);

    // IState *test = new IState();

    // StateManager *stateManager = new StateManager("test", test);
    // stateManager->registerState("test", test);
    // stateManager->changeState("test");
    // stateManager->changeState("sss");

    Core core;
    core.start();

    return 0;
}

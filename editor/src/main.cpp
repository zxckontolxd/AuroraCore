#include "../include/core.h"
#include "utils/logger/mainLogger.h"
#include "state/istate.h"
int main()
{
    MainLogger *logger = MainLogger::get();

    IState *test = new IState();
    test->registerState("test", test);
    test->changeState("test");

    return 0;
}

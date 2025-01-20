#include "utils/logger/mainLogger.h"

MainLogger* MainLogger::instance = nullptr;

MainLogger::MainLogger(){}

MainLogger* MainLogger::get()
{
    if(instance == nullptr)
        instance = new MainLogger();
    return instance;
}

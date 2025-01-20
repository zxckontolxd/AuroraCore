#include "../include/core.h"
#include "utils/logger/mainLogger.h"
int main()
{
    MainLogger *logger = MainLogger::get();
    logger->setLevel(logger::Debug);
    (*logger) << "test" <<std::endl;
    logger->info("test");
    logger->warning("test");
    logger->error("test");
    logger->debug("test");
    return 0;
}

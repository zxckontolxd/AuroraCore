#include "../include/core.h"
#include "utils/logger/logger.h"
int main()
{
    Logger logger;
    logger.setLevel(logger::Debug);
    logger << "test" <<std::endl;
    logger.info("test");
    logger.warning("test");
    logger.error("test");
    logger.debug("test");
    return 0;
}

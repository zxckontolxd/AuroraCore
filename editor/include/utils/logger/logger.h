#pragma once

#include <iostream>
#include "utils/logger/loggerStreamBuff.h"
#include "utils/logger/nullBuff.h"
#include "utils/utils.h"
#include <map>
#include <memory>
#include <utility>

/*
 * Partial documentation about logger in mainLogger.h
*/

namespace logger
{
    enum level {Info, Warning, Error, Debug};
}

class Logger : public std::ostream
{
private:
    LoggerStreamBuff globalBuff;
    std::map<logger::level, std::pair<std::ostream *, std::unique_ptr<LoggerStreamBuff>>> streams;
    logger::level currentLevel = logger::Info;
public:
    Logger(std::ostream &info = std::cout,
           std::ostream &warning = std::cerr,
           std::ostream &error = std::cerr,
           std::ostream &debug = std::cout);

    void setLevel(logger::level);

    void log(logger::level, const std::string&);

    void info(const std::string&);
    void warning(const std::string&);
    void error(const std::string&);
    void debug(const std::string&);
};

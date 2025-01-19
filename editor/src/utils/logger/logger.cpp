#include "utils/logger/logger.h"

//
//{&info, LoggerStreamBuff(info)};

Logger::Logger(std::ostream &info,
       std::ostream &warning,
       std::ostream &error,
       std::ostream &debug)
    : std::ostream(&globalBuff),
    globalBuff(std::cout)
{
    std::pair<int, int> test;
    streams[logger::Info] = std::pair<std::ostream *, std::unique_ptr<LoggerStreamBuff>>(&info, new LoggerStreamBuff(info));
    streams[logger::Warning] = std::pair<std::ostream *, std::unique_ptr<LoggerStreamBuff>>(&warning, new LoggerStreamBuff(warning));
    streams[logger::Error] = std::pair<std::ostream *, std::unique_ptr<LoggerStreamBuff>>(&error, new LoggerStreamBuff(error));
    streams[logger::Debug] = std::pair<std::ostream *, std::unique_ptr<LoggerStreamBuff>>(&debug, new LoggerStreamBuff(debug));
}

void Logger::setLevel(logger::level lvl)
{
    currentLevel = lvl;
}

void Logger::log(logger::level lvl, const std::string &message)
{
    if(streams.find(lvl) != streams.end())
    {
        *streams[lvl].first << getCurrentTime() << " " << message << std::endl;
    }
}

void Logger::info(const std::string &message)
{
    if(currentLevel >= logger::Info)
        log(logger::Info, "[Info] " + message);
}

void Logger::warning(const std::string &message)
{
    if(currentLevel >= logger::Warning)
        log(logger::Warning, "[Warning] " + message);
}

void Logger::error(const std::string &message)
{
    if(currentLevel >= logger::Error)
        log(logger::Error, "[Error] " + message);
}

void Logger::debug(const std::string &message)
{
    if(currentLevel >= logger::Debug)
        log(logger::Debug, "[Debug] " + message);
}

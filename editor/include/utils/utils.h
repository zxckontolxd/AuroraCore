#pragma once

#include <iostream>
#include <ctime>

static std::string getCurrentTime(const std::string &format = "%Y-%m-%d %H:%M:%S")
{
    std::time_t now = std::time(nullptr);
    char buf[100];
    std::strftime(buf, sizeof(buf), format.c_str(), std::localtime(&now));
    return buf;
}

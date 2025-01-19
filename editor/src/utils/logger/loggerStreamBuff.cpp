#include "utils/logger/loggerStreamBuff.h"

LoggerStreamBuff::LoggerStreamBuff(){}

LoggerStreamBuff::LoggerStreamBuff(std::ostream &stream) : targetStream(&stream) {}

void LoggerStreamBuff::setStream(std::ostream *stream)
{
    targetStream = stream;
}

int LoggerStreamBuff::overflow(int c)
{
    if(c == EOF)
        return EOF;

    char ch = static_cast<char>(c);

    (*targetStream) << ch;

    return c;
}

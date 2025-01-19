#pragma once

#include <iostream>

class LoggerStreamBuff : public std::streambuf
{
private:
    std::ostream *targetStream;
protected:
    int overflow(int c) override;
    LoggerStreamBuff();
public:
    LoggerStreamBuff(std::ostream &stream);
    void setStream(std::ostream *targetStream);
};

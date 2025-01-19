#pragma once

#include "utils/logger/loggerStreamBuff.h"

/*
 * this useless trash file
 * */

class NullBuff : public LoggerStreamBuff
{
protected:
    int overflow(int c) override
    {
        return c;
    }
public:
    NullBuff(){}
};

#pragma once
#include <rho.h>

namespace rho
{
    class loggerDevice
    {
    public:
        loggerDevice() {};
        virtual ~loggerDevice() {};

        virtual void logError(string message) = 0;
        virtual void logWarning(string message) = 0;
        virtual void logInfo(string message) = 0;
    };
}
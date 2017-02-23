#pragma once
#include <rho.h>

#include "loggerDevice.h"

namespace rho
{
    class consoleLoggerDevice : public loggerDevice
    {
    private:
        void* _consoleHandle;
    public:
        consoleLoggerDevice();
        ~consoleLoggerDevice();

        virtual void logError(string message) override;

        virtual void logWarning(string message) override;

        virtual void logInfo(string message) override;
    };
}
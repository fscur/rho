#pragma once
#include <rho.h>
#include "coreApi.h"
#include <diagnostic\stopwatch.h>

namespace rho
{
    class time
    {
    private:
        static stopwatch _stopwatch;

    public:
        CORE_API static double totalSeconds;
        CORE_API static double deltaSeconds;

    public:
        CORE_API static void start();
        CORE_API static void update();
    };
}
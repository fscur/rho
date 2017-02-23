#pragma once
#include <rho.h>
#include "coreApi.h"
#include "exception.h"

namespace rho
{
    class invalidInitializationException :
        public exception
    {
    public:
        CORE_API invalidInitializationException(string message);
    };
}
#pragma once
#include <rho.h>
#include "coreApi.h"
#include "exception.h"

namespace rho
{
    class keyNotFoundException :
        public exception
    {
    public:
        CORE_API keyNotFoundException(string message);
    };
}
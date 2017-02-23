#pragma once
#include <rho.h>
#include "coreApi.h"
#include "exception.h"

namespace rho
{
    class argumentException :
        public exception
    {
    public:
        CORE_API argumentException(string message);
    };
}
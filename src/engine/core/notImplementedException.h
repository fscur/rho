#pragma once
#include <rho.h>
#include "coreApi.h"
#include "exception.h"

namespace rho
{
    class notImplementedException :
        public exception
    {
    public:
        CORE_API notImplementedException();
    };
}
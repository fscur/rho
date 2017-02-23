#pragma once
#include <rho.h>
#include <core\eventHandler.h>

#include "mouseEventArgs.h"

namespace rho
{
    class mouseEventHandler :
        public eventHandler<mouseEventArgs*>
    {
    };
}
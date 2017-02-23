#pragma once
#include <rho.h>
#include <core\eventHandler.h>
#include "keyboardEventArgs.h"

namespace rho
{
    class keyboardEventHandler :
        public eventHandler<keyboardEventArgs*>
    {
    };
}
#pragma once
#include <rho.h>
#include "keycode.h"

namespace rho
{
    struct keyboardEventArgs
    {
    public:
        void* sender;
        keycode key;

        keyboardEventArgs() :
            sender(nullptr),
            key(rhoK_UNKNOWN)
        {
        }
    };
}
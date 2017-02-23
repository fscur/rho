#pragma once
#include <rho.h>

namespace rho
{
    class iMouseClickAnimatable
    {
    public:
        virtual void onMouseDown() = 0;
        virtual void onMouseUp() = 0;
        virtual iMouseClickAnimatable* clone() = 0;
    };
}
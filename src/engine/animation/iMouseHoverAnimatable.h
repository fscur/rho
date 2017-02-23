#pragma once
#include <rho.h>

namespace rho
{
    class iMouseHoverAnimatable
    {
    public:
        virtual void onMouseEnter() = 0;
        virtual void onMouseLeave() = 0;
        virtual iMouseHoverAnimatable* clone() = 0;
    };
}
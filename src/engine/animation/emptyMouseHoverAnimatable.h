#pragma once
#include <rho.h>

#include "iMouseHoverAnimatable.h"

namespace rho
{
    class emptyMouseHoverAnimatable :
        public iMouseHoverAnimatable
    {
    public:
        emptyMouseHoverAnimatable() {};
        ~emptyMouseHoverAnimatable() {};

        virtual void onMouseEnter() override {};
        virtual void onMouseLeave() override {};

        virtual iMouseHoverAnimatable* clone() override { return new emptyMouseHoverAnimatable(); }
    };
}
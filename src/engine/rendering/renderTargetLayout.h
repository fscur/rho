#pragma once
#include <rho.h>
#include "textureLayout.h"

namespace rho
{
    struct renderTargetLayout
    {
        renderTargetLayout(
            const string& name,
            const textureLayout& textureLayout) :
            name(name),
            textureLayout(textureLayout)
        {
        }

        const string name;
        const textureLayout textureLayout;
    };
}

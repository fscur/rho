#pragma once
#include <rho.h>
#include "texture.h"

namespace rho
{
    struct renderTarget
    {
        renderTarget(
            const string& name,
            texture* texture) :
            name(name),
            texture(texture)
        {
        }

        const string name;
        texture* texture;
    };
}
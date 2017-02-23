#pragma once
#include <rho.h>

#include <core/guid.h>
#include <core/image.h>

namespace rho
{
    class iTextureRepository
    {
    public:
        virtual image* getById(guid guid) = 0;
    };
}
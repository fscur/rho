#pragma once
#include <rho.h>

#include <core/geometry.h>

namespace rho
{
    class iGeometryRepository
    {
    public:
        virtual geometry* getById(const guid& guid) = 0;
    };
}
#pragma once
#include <rho.h>

#include <core/material.h>

namespace rho
{
    class iMaterialRepository
    {
    public:
        virtual material* getById(const guid& guid) = 0;
    };
}
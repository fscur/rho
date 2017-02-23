#pragma once
#include <rho.h>

#include <core/model.h>

namespace rho
{
    class iModelDataService
    {
    public:
        virtual model* getModelByIndex(const int index) = 0;
        virtual model* getModelById(const rho::guid& id) = 0;
    };
}
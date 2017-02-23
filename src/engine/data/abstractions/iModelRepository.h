#pragma once
#include <rho.h>

#include "data/model/modelDTO.h"

namespace rho
{
    class iModelRepository
    {
    public:
        virtual modelDTO getModelByIndex(const int index) = 0;
        virtual modelDTO getModelById(const rho::guid& id) = 0;
    };
}
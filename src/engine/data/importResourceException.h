#pragma once
#include <rho.h>
#include "dataApi.h"

#include <core/exception.h>

namespace rho
{
    class importResourceException :
        public rho::exception
    {
    private:
        string _resourcePath;
    public:
        DATA_API importResourceException(string message);
        DATA_API importResourceException(string message, string resourcePath);
        string getResourcePath() const { return _resourcePath; };
    };
}
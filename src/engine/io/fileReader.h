#pragma once
#include <rho.h>
#include "ioApi.h"

namespace rho
{
    class IO_API fileReader
    {
    public:
        static string readFile(const string& filePath);
    };
}
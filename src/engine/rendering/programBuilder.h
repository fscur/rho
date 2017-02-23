#pragma once
#include <rho.h>
#include "renderingApi.h"

#include "program.h"

namespace rho
{
    class programBuilder
    {
    public:
        RENDERING_API static program* buildProgram(
            const string& shadersPath,
            const string& vertexShaderName,
            const string& fragmentShaderName);
    };
}
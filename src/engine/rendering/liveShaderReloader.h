#pragma once
#include <rho.h>
#include "renderingApi.h"

#include "program.h"
#include "shader.h"

namespace rho
{
    class liveShaderReloader
    {
    private:
        RENDERING_API static map<string, vector<program*>> _programs;

    public:
        RENDERING_API static void reloadShader(string name);
        RENDERING_API static void add(string shaderFileName, program* program);
    };
}
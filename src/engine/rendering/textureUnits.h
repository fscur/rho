#pragma once
#include <rho.h>
#include "renderingApi.h"

namespace rho
{
    class textureUnits
    {
    private:

        static unordered_map<GLint, bool> _usedUnits;
        static GLint _maxTextureUnits;

    public:
        RENDERING_API static vector<GLint> units;

    public:
        static void initialize();
        static GLint get();
        static void clear(GLint);
    };
}

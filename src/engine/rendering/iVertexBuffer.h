#pragma once
#include <rho.h>

namespace rho
{
    class iVertexBuffer
    {
    public:
        virtual void initialize() = 0;
        virtual ~iVertexBuffer() {}
    };
}

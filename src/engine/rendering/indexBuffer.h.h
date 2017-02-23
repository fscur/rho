#pragma once
#include <rho.h>
#include "buffer.h"
#include "iVertexBuffer.h"

namespace rho
{
    class indexBuffer :
        public buffer, public iVertexBuffer
    {
    private:


    public:
        indexBuffer();
        ~indexBuffer();
    };
}
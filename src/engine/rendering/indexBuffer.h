#pragma once
#include <rho.h>
#include <core\vertex.h>

#include "buffer.h"
#include "iVertexBuffer.h"

namespace rho
{
    class indexBuffer :
        public buffer,
        public iVertexBuffer
    {
    public:
        indexBuffer(const string& name) :
            buffer(name, bufferTarget::element)
        {
        }

        ~indexBuffer() {}

        void initialize() override
        {
            bind();
        }
    };
}
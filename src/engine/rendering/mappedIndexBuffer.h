#pragma once
#include <rho.h>

#include "mappedBuffer.h"
#include "iVertexBuffer.h"

namespace rho
{
    template <typename KEY, typename DATA>
    class mappedIndexBuffer :
        public mappedBuffer<KEY, DATA>,
        public iVertexBuffer
    {
    public:
        mappedIndexBuffer(const string& name) :
            mappedBuffer<KEY, DATA>(name, bufferTarget::element)
        {
        }

        ~mappedIndexBuffer() {}

        void initialize() override
        {
            buffer::bind();
        }
    };
}

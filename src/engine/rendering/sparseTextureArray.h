#pragma once
#include <rho.h>
#include "textureArray.h"

namespace rho
{
    class sparseTextureArray :
        public textureArray
    {
    public:
        sparseTextureArray(
            sizeui size,
            textureLayout layout);

        void onCreate() override;
        
        void onLoadData(
            float page,
            const void* const data) override;

        void onLoadSubData(
            const rectangle<GLint>& rect, 
            float page, 
            const void* const data) override;
    };
}
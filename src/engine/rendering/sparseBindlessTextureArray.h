#pragma once
#include <rho.h>
#include "textureArray.h"

namespace rho
{
    class sparseBindlessTextureArray :
        public textureArray
    {
    public:
        sparseBindlessTextureArray(
            sizeui size,
            textureLayout layout);

        ~sparseBindlessTextureArray();

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
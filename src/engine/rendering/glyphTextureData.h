#pragma once
#include <rho.h>

#include "glyph.h"

namespace rho
{
    struct glyphTextureData
    {
    public:
        glyphTextureData(glyph* glyph) :
            glyph(glyph)
        {
        }

        ~glyphTextureData()
        {
        }

        glyph* glyph;
        vec2 texturePosition; // glyph texture position in texel units
        vec2 textureSize; //glyph texture size in texel units
        vec2 texelSize;
        int unit;
        float page;
    };
}
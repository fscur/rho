#include <precompiled.h>
#include "glyph.h"

namespace rho
{
    glyph::glyph(rho::image* image) :
        image(image)
    {
    }

    glyph::~glyph()
    {
        safeDelete(image);
    }
}
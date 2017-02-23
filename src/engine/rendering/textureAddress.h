#pragma once
#include <rho.h>
#include <core\rectangle.h>

namespace rho
{
    struct textureAddress
    {
        GLuint arrayId;
        GLint index;
        GLint unit;
        GLfloat page;
        rectangle<uint> rect;
    };
}
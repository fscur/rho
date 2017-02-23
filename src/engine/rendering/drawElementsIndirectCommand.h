#pragma once
#include <rho.h>

namespace rho
{
    struct drawElementsIndirectCommand
    {
        GLuint indicesCount;
        GLuint instanceCount;
        GLuint firstIndex;
        GLuint baseVertex;
        GLuint baseInstance;

        drawElementsIndirectCommand(
            GLuint indicesCount,
            GLuint instanceCount,
            GLuint firstIndex,
            GLuint baseVertex,
            GLuint baseInstance) :
            indicesCount(indicesCount),
            instanceCount(instanceCount),
            firstIndex(firstIndex),
            baseVertex(baseVertex),
            baseInstance(baseInstance)
        {
        }
    };
}
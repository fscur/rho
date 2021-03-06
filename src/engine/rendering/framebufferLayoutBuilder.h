#pragma once
#include <rho.h>
#include "renderingApi.h"
#include "framebufferLayout.h"

namespace rho
{
    class framebufferLayoutBuilder
    {
    private:
        framebufferLayout* _framebufferLayout;

    private:
        framebufferLayoutBuilder(framebufferLayout* framebufferLayout);

    public:
        RENDERING_API framebufferLayoutBuilder(const framebufferLayoutBuilder& original);

        RENDERING_API ~framebufferLayoutBuilder();
        RENDERING_API static framebufferLayoutBuilder newFramebufferLayout(const string& name);
        RENDERING_API framebufferLayoutBuilder with(
            const string renderTargetName, 
            const GLenum attachment, 
            const GLenum internalFormat, 
            const GLenum dataFormat);

        RENDERING_API framebufferLayoutBuilder with(const string renderTargetName, const GLenum attachment, const textureLayout& layout);
        RENDERING_API framebufferLayoutBuilder with(renderTarget* renderTarget, const GLenum attachment);
        RENDERING_API framebufferLayout* build();
    };
}
#pragma once
#include <rho.h>

#include <core\resolution.h>

#include "renderPass.h"
#include "framebufferAllocator.h"

namespace rho
{
    class verticalGaussianBlurRenderPass :
        public renderPass
    {
    public:
        verticalGaussianBlurRenderPass(
            const resolution& resolution,
            const string& shadersPath,
            framebufferAllocator* framebufferAllocator);

        ~verticalGaussianBlurRenderPass();

        void onBeginRender() override;
        void onEndRender() override;

    private:
        renderTarget* _defaultRenderTarget;
        renderTarget* _blurHRenderTarget;
        vertexArrayObject* _quadVao;
    };
}
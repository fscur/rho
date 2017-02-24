#pragma once
#include <rho.h>

#include <core/resolution.h>

#ifdef _DEBUG
#include <io/watcher.h>
#endif

#include <rendering/framebufferAllocator.h>
#include <rendering/gl.h>
#include <rendering/camera.h>

#include <application/window.h>
#include <application/commandsManager.h>

#include "library.h"

namespace getting_started
{
    class screen :
        public rho::window
    {
    private:
        rho::gl* _gl;

    private:
        void initGL();
        void initInput();

        void onMouseDown(rho::mouseEventArgs* e);
        void onMouseUp(rho::mouseEventArgs* e);
        void onMouseClick(rho::mouseEventArgs* e);
        void onMouseDoubleClick(rho::mouseEventArgs* e);
        void onMouseMove(rho::mouseEventArgs* e);
        void onBeginMouseWheel(rho::mouseEventArgs* e);
        void onMouseWheel(rho::mouseEventArgs* e);
        void onEndMouseWheel(rho::mouseEventArgs* e);
        void onKeyDown(rho::keyboardEventArgs* e);
        void onKeyUp(rho::keyboardEventArgs* e);

    public:
        screen(rho::wstring title, rho::resolution resolution);
        ~screen(void);

        void onInit() override;
        void onClosing() override;
        void onRender() override;
        void onUpdate() override;
        void onSwapBuffers() override;
        void onResize(rho::resolution resolution) override;
    };
}
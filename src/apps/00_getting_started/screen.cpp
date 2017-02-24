#include <precompiled.h>

#include <diagnostic/stopwatch.h>

#include <core/multiCommand.h>
#include <core/boxCollider.h>

#include <core/ghostMesh.h>

#include <input/input.h>

#include <data/abstractions/iModelDataService.h>
#include <data/geometryRepository.h>
#include <data/materialRepository.h>
#include <data/textureRepository.h>
#include <data/modelRepository.h>
#include <data/modelDataService.h>

#include <io/path.h>

#include <loader/importer.h>
#include <loader/exporter.h>

#include <rendering/defaultFramebuffer.h>
#include <rendering/pickingFramebuffer.h>

#ifdef _DEBUG
#include <rendering/liveShaderReloader.h>
#endif

#include <application/application.h>
#include <application/undoCommand.h>
#include <application/redoCommand.h>

#include <core/skyBox.h>

#include "screen.h"

using namespace rho;

namespace getting_started
{
    screen::screen(wstring title, resolution resolution) :
        window(title, resolution)
    {
    }

    screen::~screen()
    {
    }

    void screen::onInit()
    {
        initGL();
        initInput();
    }

    void screen::initGL()
    {
        application::logInfo("Initializing OpenGl");

        auto initState = gl::state();
        initState.clearColor = vec4(1.0f);
        initState.frontFace = gl::frontFace::ccw;
        initState.culling = true;
        initState.cullFace = gl::cullFace::back;
        initState.depthMask = true;
        initState.depthTest = true;
        initState.useBindlessTextures = false;
        initState.useSparseTextures = false;
        initState.swapInterval = 1;

        auto info = gl::glInfo();
        info.state = initState;
        info.shadersPath = application::resourcesPath + "/shaders";
        info.fontsPath = application::resourcesPath + "/fonts";
        _gl = new gl(info);

        application::logInfo("Vendor: " + _gl->getVendor() + ".");
        application::logInfo("Renderer: " + _gl->getRenderer() + ".");
        application::logInfo("Version: " + _gl->getVersion() + ".");

        application::logInfo("Extensions:");
        for (auto extensionStatus : _gl->extensions)
        {
            auto status = extensionStatus.second ? " [Ok]" : " [Not Ok]";
            application::logInfo(extensionStatus.first + status);
        }
    }

    void screen::initInput()
    {
        input::mouseDown->assign(std::bind(&screen::onMouseDown, this, std::placeholders::_1));
        input::mouseUp->assign(std::bind(&screen::onMouseUp, this, std::placeholders::_1));
        input::mouseClick->assign(std::bind(&screen::onMouseClick, this, std::placeholders::_1));
        input::mouseDoubleClick->assign(std::bind(&screen::onMouseDoubleClick, this, std::placeholders::_1));
        input::mouseMove->assign(std::bind(&screen::onMouseMove, this, std::placeholders::_1));
        input::beginMouseWheel->assign(std::bind(&screen::onBeginMouseWheel, this, std::placeholders::_1));
        input::mouseWheel->assign(std::bind(&screen::onMouseWheel, this, std::placeholders::_1));
        input::endMouseWheel->assign(std::bind(&screen::onEndMouseWheel, this, std::placeholders::_1));
        input::keyDown->assign(std::bind(&screen::onKeyDown, this, std::placeholders::_1));
        input::keyUp->assign(std::bind(&screen::onKeyUp, this, std::placeholders::_1));
    }

    void screen::onMouseDown(rho::mouseEventArgs* e)
    {
        _unused(e);
    }

    void screen::onMouseUp(rho::mouseEventArgs* e)
    {
        _unused(e);
    }

    void screen::onMouseClick(rho::mouseEventArgs * e)
    {
        _unused(e);
    }

    void screen::onMouseDoubleClick(rho::mouseEventArgs* e)
    {
        _unused(e);
    }

    void screen::onMouseMove(rho::mouseEventArgs* e)
    {
        _unused(e);
    }

    void screen::onBeginMouseWheel(rho::mouseEventArgs* e)
    {
        _unused(e);
    }

    void screen::onMouseWheel(rho::mouseEventArgs* e)
    {
        _unused(e);
    }

    void screen::onEndMouseWheel(rho::mouseEventArgs* e)
    {
        _unused(e);
    }

    void screen::onKeyDown(rho::keyboardEventArgs* e)
    {
        _unused(e);
    }

    void screen::onKeyUp(rho::keyboardEventArgs* e)
    {
        _unused(e);
    }

    void screen::onRender()
    {
    }

    void screen::onUpdate()
    {
    }

    void screen::onSwapBuffers()
    {
        gl::syncPipeline();
    }

    void screen::onClosing()
    {
        safeDelete(_gl);

        rho::framebuffer::release();
        rho::image::release();
        rho::material::release();
    }

    void screen::onResize(rho::resolution resolution)
    {
        window::onResize(resolution);
        gl::resize(resolution);
    }
}
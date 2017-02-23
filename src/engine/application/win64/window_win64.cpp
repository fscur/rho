#include <precompiled.h>

#include <core/exception.h>
#include <core/invalidInitializationException.h>

#include <input/input.h>

#include <diagnostic/stopwatch.h>

#include <ShellScalingApi.h>

#include "../window.h"
#include "../mouseButtonEventDispatcher.h"

namespace rho
{
    using namespace std::chrono;

    //TODO: free memory
    HWND _windowHandle;
    HINSTANCE _applicationInstance;
    HDC _deviceContext;
    HGLRC _renderingContext;
    DWORD _windowExStyle = 0;
    DWORD _windowStyle = WS_OVERLAPPEDWINDOW;
    LPARAM _lastMouseMove;
    POINT _lastMouseMovePt;
    resolution _currentResolution;

    nanoseconds _lastMouseWheelElapsed;
    nanoseconds _firstMouseWheelElapsed;

    int _mouseWheelDelta;
    bool _isMouseWheeling = false;

    bool _isBeingFirstShown = true;
    bool _hasEnteredSizeMove = false;
    bool _isResizing = false;
    bool _isBeingRestored = false;
    bool _isBeingMaximized = false;
    bool _isBeingMinimized = false;
    bool _wasMaximized = false;
    bool _wasMinimized = false;
    bool _isMouseFrozen = false;
    bool _isCursorVisible = true;

    mouseButtonEventDispatcher* _leftMouseButton;
    mouseButtonEventDispatcher* _rightMouseButton;
    mouseButtonEventDispatcher* _middleMouseButton;

    int convertToKey(WPARAM wParam)
    {
        switch (wParam)
        {
        case VK_BACK: return rhoK_BACKSPACE;
        case VK_TAB: return rhoK_TAB;
        case VK_CLEAR: return rhoK_CLEAR;
        case VK_RETURN: return rhoK_RETURN;
        case VK_SHIFT: return rhoK_SHIFT;
        case VK_CONTROL: return rhoK_CTRL;
        case VK_MENU: return rhoK_MENU;
        case VK_PAUSE: return rhoK_PAUSE;
        case VK_CAPITAL: return rhoK_CAPSLOCK;
        case VK_ESCAPE: return rhoK_ESCAPE;
        case VK_SPACE: return rhoK_SPACE;
        case VK_PRIOR: return rhoK_PAGEUP;
        case VK_NEXT: return rhoK_PAGEDOWN;
        case VK_END: return rhoK_END;
        case VK_HOME: return rhoK_HOME;
        case VK_LEFT: return rhoK_LEFT;
        case VK_UP: return rhoK_UP;
        case VK_RIGHT: return rhoK_RIGHT;
        case VK_DOWN: return rhoK_DOWN;
        case VK_SELECT: return rhoK_SELECT;
        case VK_EXECUTE: return rhoK_EXECUTE;
        case VK_SNAPSHOT: return rhoK_PRINTSCREEN;
        case VK_INSERT: return rhoK_INSERT;
        case VK_DELETE: return rhoK_DELETE;
        case VK_HELP: return rhoK_HELP;
        case 0x30: return rhoK_0;
        case 0x31: return rhoK_1;
        case 0x32: return rhoK_2;
        case 0x33: return rhoK_3;
        case 0x34: return rhoK_4;
        case 0x35: return rhoK_5;
        case 0x36: return rhoK_6;
        case 0x37: return rhoK_7;
        case 0x38: return rhoK_8;
        case 0x39: return rhoK_9;
        case 0x41: return rhoK_a;
        case 0x42: return rhoK_b;
        case 0x43: return rhoK_c;
        case 0x44: return rhoK_d;
        case 0x45: return rhoK_e;
        case 0x46: return rhoK_f;
        case 0x47: return rhoK_g;
        case 0x48: return rhoK_h;
        case 0x49: return rhoK_i;
        case 0x4A: return rhoK_j;
        case 0x4B: return rhoK_k;
        case 0x4C: return rhoK_l;
        case 0x4D: return rhoK_m;
        case 0x4E: return rhoK_n;
        case 0x4F: return rhoK_o;
        case 0x50: return rhoK_p;
        case 0x51: return rhoK_q;
        case 0x52: return rhoK_r;
        case 0x53: return rhoK_s;
        case 0x54: return rhoK_t;
        case 0x55: return rhoK_u;
        case 0x56: return rhoK_v;
        case 0x57: return rhoK_w;
        case 0x58: return rhoK_x;
        case 0x59: return rhoK_y;
        case 0x5A: return rhoK_z;
        case VK_APPS: return rhoK_APPLICATION; // TODO: is this the right key?
        case VK_SLEEP: return rhoK_SLEEP;
        case VK_NUMPAD0: return rhoK_KP_0;
        case VK_NUMPAD1: return rhoK_KP_1;
        case VK_NUMPAD2: return rhoK_KP_2;
        case VK_NUMPAD3: return rhoK_KP_3;
        case VK_NUMPAD4: return rhoK_KP_4;
        case VK_NUMPAD5: return rhoK_KP_5;
        case VK_NUMPAD6: return rhoK_KP_6;
        case VK_NUMPAD7: return rhoK_KP_7;
        case VK_NUMPAD8: return rhoK_KP_8;
        case VK_NUMPAD9: return rhoK_KP_9;
        case VK_MULTIPLY: return rhoK_KP_MULTIPLY;
        case VK_ADD: return rhoK_KP_PLUS;
        case VK_SUBTRACT: return rhoK_KP_MINUS;
        case VK_DIVIDE: return rhoK_KP_DIVIDE;
        case VK_DECIMAL: return rhoK_KP_DECIMAL;
        case VK_F1: return rhoK_F1;
        case VK_F2: return rhoK_F2;
        case VK_F3: return rhoK_F3;
        case VK_F4: return rhoK_F4;
        case VK_F5: return rhoK_F5;
        case VK_F6: return rhoK_F6;
        case VK_F7: return rhoK_F7;
        case VK_F8: return rhoK_F8;
        case VK_F9: return rhoK_F9;
        case VK_F10: return rhoK_F10;
        case VK_F11: return rhoK_F11;
        case VK_F12: return rhoK_F12;
        case VK_F13: return rhoK_F13;
        case VK_F14: return rhoK_F14;
        case VK_F15: return rhoK_F15;
        case VK_F16: return rhoK_F16;
        case VK_F17: return rhoK_F17;
        case VK_F18: return rhoK_F18;
        case VK_F19: return rhoK_F19;
        case VK_F20: return rhoK_F20;
        case VK_F21: return rhoK_F21;
        case VK_F22: return rhoK_F22;
        case VK_F23: return rhoK_F23;
        case VK_F24: return rhoK_F24;
        case VK_NUMLOCK: return rhoK_NUMLOCKCLEAR;
        case VK_SCROLL: return rhoK_SCROLLLOCK;
        case VK_BROWSER_BACK: return rhoK_AC_BACK;
        case VK_BROWSER_FORWARD: return rhoK_AC_FORWARD;
        case VK_BROWSER_REFRESH: return rhoK_AC_REFRESH;
        case VK_BROWSER_STOP: return rhoK_AC_STOP;
        case VK_BROWSER_SEARCH: return rhoK_AC_SEARCH;
        case VK_BROWSER_FAVORITES: return rhoK_AC_BOOKMARKS;
        case VK_BROWSER_HOME: return rhoK_AC_HOME;
        case VK_VOLUME_MUTE: return rhoK_MUTE;
        case VK_VOLUME_DOWN: return rhoK_VOLUMEDOWN;
        case VK_VOLUME_UP: return rhoK_VOLUMEUP;
        case VK_MEDIA_NEXT_TRACK: return rhoK_AUDIONEXT;
        case VK_MEDIA_PREV_TRACK: return rhoK_AUDIOPREV;
        case VK_MEDIA_STOP: return rhoK_AUDIOSTOP;
        case VK_MEDIA_PLAY_PAUSE: return rhoK_AUDIOPLAY;
        case VK_LAUNCH_MAIL: return rhoK_MAIL;
        case VK_LAUNCH_MEDIA_SELECT: return rhoK_MEDIASELECT;
        }

        return 0;
    }

    vec2 getDpi(HWND hWnd)
    {
        _unused(hWnd);
        //TODO: FIX DPI AWARE 

        /*auto monitor = MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST);

        auto x = unsigned{};
        auto y = unsigned{};

        GetDpiForMonitor(monitor, MDT_EFFECTIVE_DPI, &x, &y);

        return vec2(x, y);*/

        HDC dc = GetDC(0);
        const double dpiX = GetDeviceCaps(dc, LOGPIXELSX);
        const double dpiY = GetDeviceCaps(dc, LOGPIXELSY);
        ReleaseDC(0, dc);
        return vec2(dpiX, dpiY);
    }

    LRESULT onActivate(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _unused(hWnd);
        _unused(message);
        _unused(lParam);

        if (!HIWORD(wParam)) // Is minimized
        {
            // active
            //debug("active");
        }
        else
        {
            // inactive
            //debug("inactive");
        }

        return 0;
    }

    LRESULT onSysCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch (wParam)
        {
        case SC_SCREENSAVE:
        case SC_MONITORPOWER:
            return 0;
        case SC_MINIMIZE:
            _wasMaximized = _isBeingMaximized;
            _isBeingMinimized = true;
            _isBeingMaximized = false;
            _isBeingRestored = false;
            break;
        case SC_MAXIMIZE:
            _wasMinimized = _isBeingMinimized;
            _isBeingMinimized = false;
            _isBeingMaximized = true;
            _isBeingRestored = false;
            break;
        case SC_RESTORE:
            _wasMaximized = _isBeingMaximized;
            _wasMinimized = _isBeingMinimized;
            _isBeingMaximized = false;
            _isBeingMinimized = false;
            _isBeingRestored = true;
            break;
        }

        return DefWindowProcW(hWnd, message, wParam, lParam);
    }

    LRESULT onWindowPosChanged(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        const WINDOWPOS* windowPos = (WINDOWPOS *)lParam;

        RECT rectangle = { 0, 0, 0, 0 };
        GetClientRect(hWnd, &rectangle);
        auto width = rectangle.right - rectangle.left;
        auto height = rectangle.bottom - rectangle.top;

        _currentResolution = resolution(static_cast<float>(width), static_cast<float>(height), getDpi(hWnd));

        auto flags = windowPos->flags;

        if (flags & SWP_SHOWWINDOW)
        {
            if (_isBeingFirstShown)
            {
                window::resize.raise(_currentResolution);
                _isBeingFirstShown = false;
            }
        }

        if (flags & SWP_HIDEWINDOW)
        {
            return 0;
        }

        if (!(flags & SWP_NOMOVE))
        {
            //debug("window_moved_to(pwp->x, pwp->y)");
        }

        if (!(flags & SWP_NOSIZE))
        {
            if (width == 0 && height == 0)
                return 0;

            if (_isBeingMinimized)
                return 0;

            if (_wasMinimized)
            {
                _wasMinimized = false;
                return 0;
            }

            bool hasToRaiseResize = false;

            if (_isBeingMaximized)
            {
                hasToRaiseResize = true;
            }
            else if (_isBeingRestored && _wasMaximized)
            {
                hasToRaiseResize = true;
                _isBeingRestored = false;
                _wasMaximized = false;
            }
            else if (!_hasEnteredSizeMove)
                hasToRaiseResize = true;

            if (_hasEnteredSizeMove)
                _isResizing = true;

            if (hasToRaiseResize)
            {
                window::resize.raise(_currentResolution);
                return 0;
            }
        }

        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    LRESULT onEnterSizeMove(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _unused(hWnd);
        _unused(message);
        _unused(wParam);
        _unused(lParam);

        _hasEnteredSizeMove = true;
        return 0;
    }

    LRESULT onExitSizeMove(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _unused(hWnd);
        _unused(message);
        _unused(wParam);
        _unused(lParam);

        if (_isResizing)
            window::resize.raise(_currentResolution);

        _hasEnteredSizeMove = false;
        _isResizing = false;
        return 0;
    }

    LRESULT onDestroy(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _unused(hWnd);
        _unused(message);
        _unused(wParam);
        _unused(lParam);

        PostQuitMessage(0);
        return 0;
    }

    LRESULT onKeyDown(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _unused(hWnd);
        _unused(message);
        _unused(lParam);

        input::notifyKeyDown(convertToKey(wParam));
        return 0;
    }

    LRESULT onKeyUp(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _unused(hWnd);
        _unused(message);
        _unused(lParam);

        input::notifyKeyUp(convertToKey(wParam));
        return 0;
    }

    LRESULT onMouseWheel(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _unused(hWnd);
        _unused(message);

        auto point = POINT();
        point.x = GET_X_LPARAM(lParam);
        point.y = GET_Y_LPARAM(lParam);
        ScreenToClient(_windowHandle, &point);
        auto delta = GET_WHEEL_DELTA_WPARAM(wParam);
        auto now = high_resolution_clock::now().time_since_epoch();

        if (!_isMouseWheeling)
        {
            _isMouseWheeling = true;
            _mouseWheelDelta = delta;
            _firstMouseWheelElapsed = now;
            input::notifyBeginMouseWheel(delta, point.x, point.y);
            input::notifyMouseWheel(delta, point.x, point.y);
        }
        else
        {
            _mouseWheelDelta += delta;
            input::notifyMouseWheel(delta, point.x, point.y);
        }

        _lastMouseWheelElapsed = now;

        return 0;
    }

    LRESULT onLButtonDown(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _leftMouseButton->notifyButtonDown(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
        return DefWindowProcW(hWnd, message, wParam, lParam);
    }

    LRESULT onLButtonUp(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _leftMouseButton->notifyButtonUp(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
        return DefWindowProcW(hWnd, message, wParam, lParam);
    }

    LRESULT onLButtonDblClk(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _leftMouseButton->notifyButtonDoubleClick(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
        return DefWindowProcW(hWnd, message, wParam, lParam);
    }
    
    LRESULT onRButtonDown(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _rightMouseButton->notifyButtonDown(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
        return DefWindowProcW(hWnd, message, wParam, lParam);
    }

    LRESULT onRButtonUp(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _rightMouseButton->notifyButtonUp(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
        return DefWindowProcW(hWnd, message, wParam, lParam);
    }

    LRESULT onRButtonDblClk(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _rightMouseButton->notifyButtonDoubleClick(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
        return DefWindowProcW(hWnd, message, wParam, lParam);
    }

    LRESULT onMButtonDown(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _middleMouseButton->notifyButtonDown(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
        return DefWindowProcW(hWnd, message, wParam, lParam);
    }

    LRESULT onMButtonUp(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _middleMouseButton->notifyButtonUp(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
        return DefWindowProcW(hWnd, message, wParam, lParam);
    }

    LRESULT onMButtonDblClk(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _middleMouseButton->notifyButtonDoubleClick(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
        return DefWindowProcW(hWnd, message, wParam, lParam);
    }

    LRESULT onMouseMove(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        if (_isMouseFrozen)
            return DefWindowProcW(hWnd, message, wParam, lParam);

        if (lParam != _lastMouseMove)
            input::notifyMouseMove(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));

        _lastMouseMove = lParam;

        return 0;
    }

    LRESULT onCaptureChanged(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _unused(hWnd);
        _unused(message);
        _unused(wParam);
        _unused(lParam);
        //Any operation that uses SetCapture function and has an end state should set it end state here,
        //for example changing the cursor at the end of a drag and drog operation.
        return 0;
    }

    LRESULT onDpiChanged(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        _unused(message);
        _unused(wParam);

        auto rect = *reinterpret_cast<RECT *>(lParam);

        HWND doesNotHaveRelativeWindow = 0;

        SetWindowPos(hWnd,
            doesNotHaveRelativeWindow,
            rect.left,
            rect.top,
            rect.right - rect.left,
            rect.bottom - rect.top,
            SWP_NOACTIVATE | SWP_NOZORDER);

        return 0;
    }

    LRESULT CALLBACK windowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch (message)
        {
        case WM_ACTIVATE:
            return onActivate(hWnd, message, wParam, lParam);
        case WM_SYSCOMMAND:
            return onSysCommand(hWnd, message, wParam, lParam);
        case WM_CLOSE:
        case WM_DESTROY:
            return onDestroy(hWnd, message, wParam, lParam);
        case WM_KEYDOWN:
        case WM_SYSKEYDOWN:
            return onKeyDown(hWnd, message, wParam, lParam);
        case WM_KEYUP:
        case WM_SYSKEYUP:
            return onKeyUp(hWnd, message, wParam, lParam);
        case WM_MOUSEWHEEL:
            return onMouseWheel(hWnd, message, wParam, lParam);
        case WM_LBUTTONDOWN:
            return onLButtonDown(hWnd, message, wParam, lParam);
        case WM_LBUTTONDBLCLK:
            return onLButtonDblClk(hWnd, message, wParam, lParam);
        case WM_LBUTTONUP:
            return onLButtonUp(hWnd, message, wParam, lParam);
        case WM_RBUTTONDOWN:
            return onRButtonDown(hWnd, message, wParam, lParam);
        case WM_RBUTTONDBLCLK:
            return onRButtonDblClk(hWnd, message, wParam, lParam);
        case WM_RBUTTONUP:
            return onRButtonUp(hWnd, message, wParam, lParam);
        case WM_MBUTTONDOWN:
            return onMButtonDown(hWnd, message, wParam, lParam);
        case WM_MBUTTONDBLCLK:
            return onMButtonDblClk(hWnd, message, wParam, lParam);
        case WM_MBUTTONUP:
            return onMButtonUp(hWnd, message, wParam, lParam);
        case WM_MOUSEMOVE:
            return onMouseMove(hWnd, message, wParam, lParam);
        case WM_CAPTURECHANGED:
            return onCaptureChanged(hWnd, message, wParam, lParam);
        case WM_ENTERSIZEMOVE:
            return onEnterSizeMove(hWnd, message, wParam, lParam);
        case WM_EXITSIZEMOVE:
            return onExitSizeMove(hWnd, message, wParam, lParam);
        case WM_WINDOWPOSCHANGED:
            return onWindowPosChanged(hWnd, message, wParam, lParam);
        //case WM_DPICHANGED:
            //return onDpiChanged(hWnd, message, wParam, lParam);
        }

        return DefWindowProcW(hWnd, message, wParam, lParam);
    }

    void createWindow(wstring title, resolution resolution)
    {
        _applicationInstance = GetModuleHandle(NULL);
        WNDCLASSEXW wndClass;
        auto cTitle = title.c_str();
        wndClass.cbSize = sizeof(WNDCLASSEXW);
        wndClass.style = CS_HREDRAW | CS_VREDRAW |  CS_DBLCLKS ;
        wndClass.lpfnWndProc = (WNDPROC)windowProcedure;
        wndClass.cbClsExtra = 0;
        wndClass.cbWndExtra = 0;
        wndClass.hInstance = _applicationInstance;
        wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
        wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
        wndClass.lpszMenuName = NULL;
        wndClass.lpszClassName = title.c_str();
        wndClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);

        if (!RegisterClassExW(&wndClass))
            throw invalidInitializationException("Could not register window class!");

        auto screenWidth = static_cast<float>(GetSystemMetrics(SM_CXSCREEN));
        auto screenHeight = static_cast<float>(GetSystemMetrics(SM_CYSCREEN));

        RECT windowRect;
        windowRect.left = static_cast<long>(screenWidth * 0.5f - resolution.width * 0.5f);
        windowRect.right = static_cast<long>(windowRect.left + resolution.width);
        windowRect.top = static_cast<long>(screenHeight * 0.5f - resolution.height * 0.5f);
        windowRect.bottom = static_cast<long>(windowRect.top + resolution.height);

        AdjustWindowRectEx(&windowRect, _windowStyle, FALSE, _windowExStyle);

        _windowHandle = CreateWindowExW(
            0,
            cTitle,
            cTitle,
            _windowStyle,
            windowRect.left,
            windowRect.top,
            windowRect.right - windowRect.left,
            windowRect.bottom - windowRect.top,
            NULL,
            NULL,
            _applicationInstance,
            NULL);

        if (!_windowHandle)
            throw invalidInitializationException("Could not create the window!");
    }

    PIXELFORMATDESCRIPTOR getPixelFormatDescriptor()
    {
        PIXELFORMATDESCRIPTOR result = {};
        result.nSize = sizeof(PIXELFORMATDESCRIPTOR);
        result.nVersion = 1;
        result.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        result.iPixelType = PFD_TYPE_RGBA;
        result.cColorBits = 32;
        result.cDepthBits = 24;
        result.cStencilBits = 8;
        result.cAuxBuffers = 0;
        result.iLayerType = PFD_MAIN_PLANE;
        return result;
    }

    HGLRC createFakeGLContext()
    {
        HGLRC renderingContext = wglCreateContext(_deviceContext);

        if (!renderingContext)
            throw invalidInitializationException("Could not create fake OpenGL context!");

        if (!wglMakeCurrent(_deviceContext, renderingContext))
            throw invalidInitializationException("Could not set fake OpenGL context!");

        return renderingContext;
    }

    void createGLContext()
    {
        _deviceContext = GetDC(_windowHandle);

        PIXELFORMATDESCRIPTOR pixelFormatDescriptor = getPixelFormatDescriptor();

        int pixelFormat = ChoosePixelFormat(_deviceContext, &pixelFormatDescriptor);

        if (!pixelFormat)
            throw invalidInitializationException("Could not choose pixel format!");

        if (!SetPixelFormat(_deviceContext, pixelFormat, &pixelFormatDescriptor))
            throw invalidInitializationException("Could not set pixel format!");

        //we need to create a fake context so we have access to the opengl extensions
        HGLRC tempRenderingContext = createFakeGLContext();

        GLenum err = glewInit();

        if (err != GLEW_OK)
            throw invalidInitializationException("GLEW is not initialized!");

        int attribs[] =
        {
            WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
            WGL_CONTEXT_MINOR_VERSION_ARB, 5,
            WGL_CONTEXT_FLAGS_ARB, 0, 0
        };

        if (wglewIsSupported("WGL_ARB_create_context") == GL_TRUE)
        {
            _renderingContext = wglCreateContextAttribsARB(_deviceContext, 0, attribs);
            wglMakeCurrent(NULL, NULL);
            wglDeleteContext(tempRenderingContext);
            wglMakeCurrent(_deviceContext, _renderingContext);
        }
        else
            _renderingContext = tempRenderingContext;

        if (!_renderingContext)
            throw invalidInitializationException("Could not create a GL context!");
    }

    void releaseGLContext()
    {
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(_renderingContext);
    }

    void initMouseButtonDispatchers()
    {
        _leftMouseButton = new mouseButtonEventDispatcher(_windowHandle);
        _leftMouseButton->setButtonClickFunction([](int x, int y) { input::notifyLeftMouseClick(x, y); });
        _leftMouseButton->setButtonDoubleClickFunction([](int x, int y) { input::notifyLeftMouseDoubleClick(x, y); });
        _leftMouseButton->setButtonDownFunction([](int x, int y) 
        { 
            SetCapture(_windowHandle);
            input::notifyLeftMouseDown(x, y);
        });
        _leftMouseButton->setButtonUpFunction([](int x, int y)
        {
            input::notifyLeftMouseUp(x, y);
            ReleaseCapture();
        });

        _rightMouseButton = new mouseButtonEventDispatcher(_windowHandle);
        _rightMouseButton->setButtonClickFunction([](int x, int y) { input::notifyRightMouseClick(x, y); });
        _rightMouseButton->setButtonDoubleClickFunction([](int x, int y) { input::notifyRightMouseDoubleClick(x, y); });
        _rightMouseButton->setButtonDownFunction([](int x, int y)
        {
            SetCapture(_windowHandle);
            input::notifyRightMouseDown(x, y);
        });
        _rightMouseButton->setButtonUpFunction([](int x, int y)
        {
            input::notifyRightMouseUp(x, y);
            ReleaseCapture();
        });

        _middleMouseButton = new mouseButtonEventDispatcher(_windowHandle);
        _middleMouseButton->setButtonClickFunction([](int x, int y) { input::notifyMiddleMouseClick(x, y); });
        _middleMouseButton->setButtonDoubleClickFunction([](int x, int y) { input::notifyMiddleMouseDoubleClick(x, y); });
        _middleMouseButton->setButtonDownFunction([](int x, int y)
        {
            SetCapture(_windowHandle);
            input::notifyMiddleMouseDown(x, y);
        });
        _middleMouseButton->setButtonUpFunction([](int x, int y)
        {
            input::notifyMiddleMouseUp(x, y);
            ReleaseCapture();
        });
    }

    void deleteMouseButtonDispatchers()
    {
        safeDelete(_leftMouseButton);
        safeDelete(_rightMouseButton);
        safeDelete(_middleMouseButton);
    }

    void window::initWindow()
    {
        adjustWindowToScreenBounds();
        createWindow(_title, _resolution);
        createGLContext();

        ShowWindow(_windowHandle, SW_SHOW);
        SetForegroundWindow(_windowHandle);
        SetFocus(_windowHandle);

        _resolution.dpi = getDpi(_windowHandle);
    }

    void window::adjustWindowToScreenBounds()
    {
        auto screenWidth = static_cast<float>(GetSystemMetrics(SM_CXSCREEN));
        auto screenHeight = static_cast<float>(GetSystemMetrics(SM_CYSCREEN));

        RECT rectangle = { 0, 0, 0, 0 };
        AdjustWindowRectEx(&rectangle, _windowStyle, FALSE, _windowExStyle);

        auto verticalBorderSize = static_cast<float>(rectangle.bottom - rectangle.top);

        auto width = std::min(_resolution.width, screenWidth);
        auto height = std::min(_resolution.height, screenHeight - verticalBorderSize);
        _resolution = resolution(width, height);
    }

    void window::init()
    {
        initWindow();
        initMouseButtonDispatchers();

        onInit();

        _resizeToken = window::resize.assign([&](rho::resolution resolution)
        {
            onResize(resolution);
        });
    }

    void window::input()
    {
        MSG msg;

        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
        {
            if (msg.message == WM_QUIT)
            {
                closed = true;
                return;
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    void window::update()
    {
        if (_isMouseFrozen)
        {
            POINT p;
            GetCursorPos(&p);

            input::notifyMouseMove(p.x - _lastMouseMovePt.x, p.y - _lastMouseMovePt.y);

            SetCursorPos(_lastMouseMovePt.x, _lastMouseMovePt.y);
        }

        if (_isMouseWheeling)
        {
            auto now = high_resolution_clock::now().time_since_epoch();
            auto lastMouseWheelElapsed = duration_cast<duration<double>>(now - _lastMouseWheelElapsed).count();

            if(lastMouseWheelElapsed > 0.1f)
            {
                auto elapsed = duration_cast<duration<double>>(now - _firstMouseWheelElapsed).count();
                input::notifyEndMouseWheel(_mouseWheelDelta, elapsed);
                _isMouseWheeling = false;
            }
        }

        onUpdate();
    }

    void window::swapBuffers()
    {
        SwapBuffers(_deviceContext);
        onSwapBuffers();
    }

    void window::close()
    {
        window::resize.unassign(_resizeToken);

        onClosing();

        deleteMouseButtonDispatchers();
        releaseGLContext();
        ReleaseDC(_windowHandle, _deviceContext);
        DestroyWindow(_windowHandle);
    }

    void window::freezeMouse()
    {
        _isMouseFrozen = true;
        GetCursorPos(&_lastMouseMovePt);
        //ShowCursor(false);
    }

    void window::unfreezeMouse()
    {
        _isMouseFrozen = false;
        //ShowCursor(true);
    }

    void window::showCursor()
    {
        ShowCursor(true);

        _isCursorVisible = true;
    }

    void window::hideCursor()
    {
        ShowCursor(false);

        _isCursorVisible = false;
    }
}
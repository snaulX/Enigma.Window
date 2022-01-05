#include "GlfwModule.h"

static bool glIsInited = false;

PRIVATE Window* Glfw_CreateWindow(const char* title, int x, int y, int w, int h, WindowFlags flags)
{
    GlfwWindow *glfwWindow = malloc(sizeof(GlfwWindow));
    glfwWindow->title = title;

    if (!glIsInited) glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

    bool decorated = CheckFlags(flags, WindowState_Borderless) ? GLFW_FALSE : GLFW_TRUE;
    glfwWindowHint(GLFW_DECORATED, decorated);

    bool resizable = CheckFlags(flags, WindowState_Resizable) ? GLFW_TRUE : GLFW_FALSE;
    glfwWindowHint(GLFW_RESIZABLE, resizable);

    bool maximized = CheckFlags(flags, WindowState_Maximized) ? GLFW_TRUE : GLFW_FALSE;
    glfwWindowHint(GLFW_MAXIMIZED, maximized);

    GLFWmonitor* monitor = nullptr;
    if (CheckFlags(flags, WindowState_Fullscreen))
    {
        monitor = glfwGetPrimaryMonitor();
    }

    if (CheckFlags(flags, WindowState_FullscreenDesktop))
    {
        monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode *mode = glfwGetVideoMode(monitor);

        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

        glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
    }

    GLFWwindow *impl = glfwCreateWindow(w, h, title, monitor, nullptr);
    if (!impl)
    {
        EW_Error("GLFW: Failed to create window");
    }
    glfwWindow->glfwWindow = impl;

    glfwDefaultWindowHints();

    Window *wnd = malloc(sizeof(Window));
    wnd->wndData = glfwWindow;

    glfwSetWindowUserPointer(impl, wnd);
    //glfwSetWindowCloseCallback(impl, );
    //glfwSetWindowSizeCallback(impl, );
    SetPosition(wnd, x, y);

    return wnd;
}

PRIVATE void Glfw_SetOpenGL(int majorVersion, int minorVersion)
{
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);
    glIsInited = true;
}

static inline void OnGLFWError(int code, const char* description)
{
    // (11: first chars) + (8: code's numbers count) + (2: last chars) + description = 21 + description
    char *errText = malloc(21*sizeof(char) + sizeof(description));
    sprintf(errText, "GLFW error %i: %s", code, description);
    EW_Error(errText);
}

PUBLIC void Glfw_InitFunctions()
{
    glfwSetErrorCallback(OnGLFWError);
#ifdef __APPLE__
    glfwInitHint(GLFW_COCOA_CHDIR_RESOURCES, GLFW_FALSE);
#endif
    if (glfwInit() != GLFW_TRUE)
    {
        EW_Error("Failed to initialize GLFW");
        return;
    }

    // Setup base window functions
    Set_CreateWindow(Glfw_CreateWindow);
    Set_SetOpenGL(Glfw_SetOpenGL);
    Set_SetUserData(Glfw_SetUserData);
    Set_GetUserData(Glfw_GetUserData);
    Set_GetTitle(Glfw_GetTitle);
    Set_SetTitle(Glfw_SetTitle);
    Set_SetPosition(Glfw_SetPosition);
    Set_GetPosition(Glfw_GetPosition);
    Set_Show(Glfw_Show);
    Set_ShouldClose(Glfw_ShouldClose);
    Set_Update(Glfw_Update);
    Set_Run(Base_Run);

    // Setup functions for native interop
    Set_GetWin32(Glfw_GetWin32);
}
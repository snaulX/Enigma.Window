#include "GlfwModule.h"

static bool glIsInited = false;

PRIVATE EW_Window* Glfw_CreateWindow(const char* title, int x, int y, int w, int h, EW_WindowFlags flags)
{
    GlfwWindow *glfwWindow = malloc(sizeof(GlfwWindow));
    glfwWindow->title = title;
    glfwWindow->maxWidth = -1;
    glfwWindow->maxHeight = -1;
    glfwWindow->minWidth = -1;
    glfwWindow->minHeight = -1;

    if (!glIsInited) glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

    bool decorated = CheckFlags(flags, EW_WindowState_Borderless) ? GLFW_FALSE : GLFW_TRUE;
    glfwWindowHint(GLFW_DECORATED, decorated);

    bool resizable = CheckFlags(flags, EW_WindowState_Resizable) ? GLFW_TRUE : GLFW_FALSE;
    glfwWindowHint(GLFW_RESIZABLE, resizable);

    bool maximized = CheckFlags(flags, EW_WindowState_Maximized) ? GLFW_TRUE : GLFW_FALSE;
    glfwWindowHint(GLFW_MAXIMIZED, maximized);

    GLFWmonitor* monitor = nullptr;
    if (CheckFlags(flags, EW_WindowState_Fullscreen))
    {
        monitor = glfwGetPrimaryMonitor();
    }

    if (CheckFlags(flags, EW_WindowState_FullscreenDesktop))
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
    glIsInited = false; // opengl hint was set to default, so we change this too

    EW_Window *wnd = malloc(sizeof(EW_Window));
    wnd->wndData = glfwWindow;

    glfwSetWindowUserPointer(impl, wnd);
    EW_SetPosition(wnd, x, y);

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
    Set_EW_CreateWindow(Glfw_CreateWindow);
    Set_EW_SetOpenGL(Glfw_SetOpenGL);
    Set_EW_SetUserData(Base_SetUserData); //Set_SetUserData(Glfw_SetUserData);
    Set_EW_GetUserData(Base_GetUserData); //Set_GetUserData(Glfw_GetUserData);
    Set_EW_GetTitle(Glfw_GetTitle);
    Set_EW_SetTitle(Glfw_SetTitle);
    Set_EW_SetPosition(Glfw_SetPosition);
    Set_EW_GetPosition(Glfw_GetPosition);
    Set_EW_SetSize(Glfw_SetSize);
    Set_EW_GetSize(Glfw_GetSize);
    Set_EW_SetMaxSize(Glfw_SetMaxSize);
    Set_EW_GetMaxSize(Glfw_GetMaxSize);
    Set_EW_SetMinSize(Glfw_SetMinSize);
    Set_EW_GetMinSize(Glfw_GetMinSize);
    Set_EW_Close(Glfw_Close);
    Set_EW_Update(Glfw_Update);
    Set_EW_Show(Glfw_Show);
    Set_EW_Hide(Glfw_Hide);
    Set_EW_ShouldClose(Glfw_ShouldClose);
    Set_EW_Update(Glfw_Update);
    Set_EW_Run(Base_Run);
    Set_EW_SetFramebufferResizeCallback(Glfw_SetFramebufferResizeCallback);
    Set_EW_SetUpdateCallback(Glfw_SetUpdateCallback);

    // Setup functions for native interop
    Set_EW_GetWin32(Glfw_GetWin32);

    Set_EW_GetLibType(Glfw_GetLibType);
}
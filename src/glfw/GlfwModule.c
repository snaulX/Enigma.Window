#include "GlfwModule.h"

static uint windowCount = 0;

PRIVATE Window* Glfw_CreateWindow(const char* title, int x, int y, int w, int h, WindowFlags flags)
{
    GlfwWindow *glfwWindow = malloc(sizeof(GlfwWindow));
    glfwWindow->title = title;

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

    bool decorated = CheckBitsAny(flags, WindowState_Borderless) ? GLFW_FALSE : GLFW_TRUE;
    glfwWindowHint(GLFW_DECORATED, decorated);

    bool resizable = CheckBitsAny(flags, WindowState_Resizable) ? GLFW_TRUE : GLFW_FALSE;
    glfwWindowHint(GLFW_RESIZABLE, resizable);

    bool maximized = CheckBitsAny(flags, WindowState_Maximized) ? GLFW_TRUE : GLFW_FALSE;
    glfwWindowHint(GLFW_MAXIMIZED, maximized);

    GLFWmonitor* monitor = nullptr;
    if (CheckBitsAny(flags, WindowState_Fullscreen))
    {
        monitor = glfwGetPrimaryMonitor();
    }

    if (CheckBitsAny(flags, WindowState_FullscreenDesktop))
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
        LOGE("GLFW: Failed to create window");
    }
    glfwWindow->glfwWindow = impl;

    windowCount++;

    glfwDefaultWindowHints();

    Window *wnd = malloc(sizeof(Window));
    wnd->data = glfwWindow;

    glfwSetWindowUserPointer(impl, wnd);
    //glfwSetWindowCloseCallback(impl, );
    //glfwSetWindowSizeCallback(impl, );
    SetPosition(wnd, x, y);

    return wnd;
}

static inline void OnGLFWError(int code, const char* description)
{
    printf("GLFW error %i: %s", code, description);
}

PUBLIC void Glfw_InitFunctions()
{
    glfwSetErrorCallback(OnGLFWError);
#ifdef __APPLE__
    glfwInitHint(GLFW_COCOA_CHDIR_RESOURCES, GLFW_FALSE);
#endif
    if (glfwInit() != GLFW_TRUE)
    {
        LOGE("Failed to initialize GLFW");
        return;
    }
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    Set_CreateWindow(Glfw_CreateWindow);
    Set_GetTitle(Glfw_GetTitle);
    Set_SetTitle(Glfw_SetTitle);
    Set_SetPosition(Glfw_SetPosition);
    Set_GetPosition(Glfw_GetPosition);
    Set_Show(Glfw_Show);
    Set_Update(Glfw_Update);
    Set_Run(Base_Run);
}
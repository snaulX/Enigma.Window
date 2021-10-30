#include "GlfwModule.h"

PRIVATE Window* Glfw_CreateWindow()
{
    GlfwWindow *glfwWindow = malloc(sizeof(GlfwWindow));
    Window *wnd = malloc(sizeof(Window));
    wnd->data = glfwWindow;
    return wnd;
}

static inline void OnGLFWError(int code, const char* description)
{
    printf("GLFW error %i: %s", code, description);
}

PUBLIC void Glfw_InitFunctions()
{
    glfwSetErrorCallback(OnGLFWError);
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
    Set_Update(Glfw_Update);
}
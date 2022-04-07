#include "GlfwInterop.h"
#include "GlfwInput.h"

bool Glfw_IsKeyDown(EW_Window *wnd, int keyCode) {
    return glfwGetKey(Glfw_CastWindow(wnd), keyCode) == GLFW_PRESS;
}

bool Glfw_IsKeyUp(EW_Window *wnd, int keyCode) {
    return glfwGetKey(Glfw_CastWindow(wnd), keyCode) == GLFW_RELEASE;
}

PRIVATE void Native_KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    EW_Window *wnd = glfwGetWindowUserPointer(window);
    void (*keyCallback)(EW_Window*, int, bool) = ((GlfwWindow*)wnd->wndData)->keyCallback;
    if (keyCallback)
        keyCallback(wnd, key, action != GLFW_RELEASE);
}

void Glfw_SetKeyCallback(EW_Window *wnd, void (*callback)(EW_Window*, int, bool)) {
    ((GlfwWindow*)wnd->wndData)->keyCallback = callback;
    glfwSetKeyCallback(Glfw_CastWindow(wnd), Native_KeyCallback);
}

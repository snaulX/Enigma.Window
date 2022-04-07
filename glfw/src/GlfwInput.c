#include "GlfwInterop.h"
#include "GlfwInput.h"

bool Glfw_IsKeyDown(EW_Window *wnd, int keyCode) {
    return glfwGetKey(Glfw_CastWindow(wnd), keyCode) == GLFW_PRESS;
}

bool Glfw_IsKeyUp(EW_Window *wnd, int keyCode) {
    return glfwGetKey(Glfw_CastWindow(wnd), keyCode) == GLFW_RELEASE;
}

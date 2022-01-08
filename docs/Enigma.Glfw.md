# Enigma.Glfw
**Enigma.Glfw** is a module for Enigma.Window that provides [glfw](https://www.glfw.org/) library.  
Requirements:  
* **CMake** version >= 3.6
* **C99** standard
## Getting Started
This module includes into main Enigma.Window repo, so you clone and add Enigma.Window and before all in `CMakeLists.txt` set `ENIGMA_GLFW` to `ON`
```cmake
set(ENIGMA_GLFW ON)
```
If you wanna build *Enigma.Glfw* as shared library, set `ENIGMA_GLFW_DLL` to `ON`.  
After building and linking, you need to use it in code. First of all, you must include [GlfwModule.h](https://github.com/wings-studio/Enigma.Window/blob/main/src/glfw/GlfwModule.h) header file. After it you must link this module in `main` function. Enigma.Glfw contains only one function for linking it in code: `Glfw_InitFunctions()`. Also for safety use `ENIGMA_GLFW` directive that enables when this module was linked using header or cmake.  
After all your code must looks like this:
```c
#include "EnigmaWindow.h"
#include "glfw/GlfwModule.h"

int main(void)
{
#ifdef ENIGMA_GLFW
    Glfw_InitFunctions();
#endif // ENIGMA_GLFW
	
	// your code...
}
```
## Interop with native GLFW
There's no special external function for get native `GLFWwindow` but you can get it another way. `Window` structure contains field `void* wndData`. In Enigma.Glfw module this field contains pointer to `GlfwWindow` structure (struct in [GlfwWindow.h](https://github.com/wings-studio/Enigma.Window/blob/main/src/glfw/GlfwWindow.h) header). `GlfwWindow` has `GLFWwindow* glfwWindow` field which you can use.  
This process in one line of code:
```c
Window* wnd;
GLFWwindow* glfwWindow = ((GlfwWindow*)wnd->wndData)->glfwWindow;
```
Inside Enigma.Glfw library this line describes in `inline GLFWwindow *Glfw_CastWindow(Window*)` function.
## OpenGL interop
Enigma.Window has `SetOpenGL(int majorVersion, int minorVersion)` primary for glfw library. You need to call it before creating window.  
As analogue of `glfwMakeContextCurrent` in Enigma.Glfw use `void Glfw_MakeContextCurrent(Window*)`. **This function exclusively for Enigma.Glfw library and not includes in Engima.Window**

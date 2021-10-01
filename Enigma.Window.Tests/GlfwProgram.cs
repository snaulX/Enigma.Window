using System;
using Vortice.Mathematics;
using Enigma.Glfw;

namespace Enigma.Window.Tests
{
    class GlfwProgram
    {
        static void Main(string[] args)
        {
            GlfwWindow window = new GlfwWindow("GLFW Window", new Int2(100, 100), new Int2(800, 600), WindowState.Resizable);
        }
    }
}

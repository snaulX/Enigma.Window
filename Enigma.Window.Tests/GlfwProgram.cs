using System;
using Vortice.Mathematics;
using Enigma.Glfw;

namespace Enigma.Window.Tests
{
    class GlfwProgram
    {
        static void Main(string[] args)
        {
            IWindow window = new GlfwWindow("GLFW Window", new Int2(100, 100), new Int2(800, 600), WindowState.Resizable);
            Console.WriteLine(window.NativeHandle.PlatformHandle);
            window.OnClosed += () => Console.WriteLine("Window is closed");
            window.OnClosing += () => {
                Console.Write("Do you want to close window? (y/n) ");
                string answer = Console.ReadLine();
                return answer == "n" || answer == "no";
            };
            while (!window.ShouldClose())
            {
                window.Update();
            }
        }
    }
}

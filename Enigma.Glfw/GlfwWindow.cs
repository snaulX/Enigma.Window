using System;
using Enigma.Window;
using Silk.NET.GLFW;
using Silk.NET.Core.Contexts;
using Vortice.Mathematics;
using SilkGlfw = Silk.NET.GLFW.Glfw;

namespace Enigma.Glfw
{
    public unsafe class GlfwWindow : IWindow
    {
        private readonly SilkGlfw glfw;
        private readonly WindowHandle* handle;
        private readonly Monitor* monitor;

        private readonly GlfwNativeWindow nativeWindow;

        private string _title;

        public IntPtr Handle 
        { 
            get 
            {
                switch (nativeWindow.Kind)
                {
                    case NativeWindowFlags.Win32:
                        {
                            (nint Hwnd, nint HDC, nint HInstance)? win32 = nativeWindow.Win32;
                            return win32.Value.Hwnd;
                        }
                    case NativeWindowFlags.X11:
                        return unchecked((IntPtr)(long)(ulong)new UIntPtr(nativeWindow.X11.Value.Window));
                    default:
                        return (IntPtr)nativeWindow.Glfw;
                }
            } 
        }

        public string Title { get => _title; set { glfw.SetWindowTitle(handle, value); _title = value; } }
        public Int2 Position { get { glfw.GetWindowPos(handle, out int x, out int y); return new Int2(x, y); } set => glfw.SetWindowPos(handle, value.X, value.Y); }
        public Int2 Size { get { glfw.GetWindowSize(handle, out int w, out int h); return new Int2(w, h); } set => glfw.SetWindowSize(handle, value.X, value.Y); }

        public bool Exists => handle != null;

        public event Action OnResized;
        public event Action OnClosing;
        public event Action OnClosed;

        public void Close()
        {
        }

        public void Hide()
        {
            glfw.HideWindow(handle);
        }

        public void Show()
        {
            glfw.ShowWindow(handle);
        }

        public GlfwWindow(string title, Int2 position, Int2 size, WindowState flags)
        {
            glfw = SilkGlfw.GetApi();
            if (glfw.Init() == false)
            {
                Console.WriteLine("GLFW doesn't init");
            }
            glfw.WindowHint(WindowHintClientApi.ClientApi, ClientApi.NoApi);

            glfw.WindowHint(WindowHintBool.Decorated, (flags & WindowState.Borderless) != WindowState.Borderless);
            glfw.WindowHint(WindowHintBool.Resizable, (flags & WindowState.Resizable) == WindowState.Resizable);
            glfw.WindowHint(WindowHintBool.Maximized, (flags & WindowState.Maximized) == WindowState.Maximized);

            if ((flags & WindowState.Fullscreen) == WindowState.Fullscreen) monitor = glfw.GetPrimaryMonitor();

            if ((flags & WindowState.FullscreenDesktop) == WindowState.FullscreenDesktop)
            {
                monitor = glfw.GetPrimaryMonitor();
                VideoMode* mode = glfw.GetVideoMode(monitor);
                glfw.WindowHint(WindowHintInt.RedBits, mode->RedBits);
                glfw.WindowHint(WindowHintInt.GreenBits, mode->GreenBits);
                glfw.WindowHint(WindowHintInt.BlueBits, mode->BlueBits);
                glfw.WindowHint(WindowHintInt.RefreshRate, mode->RefreshRate);
                glfw.WindowHint(WindowHintBool.Decorated, false);
            }

            _title = title;
            handle = glfw.CreateWindow(size.X, size.Y, title, monitor, null);
            glfw.DefaultWindowHints();
            nativeWindow = new GlfwNativeWindow(glfw, handle);
        }
    }
}

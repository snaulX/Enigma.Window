using System;
using Enigma.Window;
using Silk.NET.GLFW;
using Vortice.Mathematics;
using SilkGlfw = Silk.NET.GLFW.Glfw;
using Enigma.Window.Silk;

namespace Enigma.Glfw
{
    // Thanks to https://github.com/amerkoleci/alimer/blob/main/Source/Engine/Private/Platform_GLFW.cpp
    // For using it in learning purposes
    public unsafe class GlfwWindow : IWindow
    {
        // Glfw fields
        private readonly SilkGlfw glfw;
        private WindowHandle* handle;
        private readonly Monitor* monitor;

        // Fields for custom usage;
        private string _title;
        private bool _isClosing = false;

        public NativeWindow NativeHandle { get; }

        public string Title { get => _title; set { glfw.SetWindowTitle(handle, value); _title = value; } }
        public Int2 Position { get { glfw.GetWindowPos(handle, out int x, out int y); return new Int2(x, y); } set => glfw.SetWindowPos(handle, value.X, value.Y); }
        public Int2 Size { get { glfw.GetWindowSize(handle, out int w, out int h); return new Int2(w, h); } set => glfw.SetWindowSize(handle, value.X, value.Y); }

        public bool IsMinimized 
        { 
            get 
            {
                if (glfw.WindowShouldClose(handle))
                    return true;

                glfw.GetFramebufferSize(handle, out int w, out int h);
                return w == 0 || h == 0;
            } 
        }
        public bool IsClosing => _isClosing;

        public event Action<int, int> OnResized;
        public event Action<int, int> OnFramebufferResized;
        public event Func<bool> OnClosing;
        public event Action OnClosed;
        public event Action OnShow;
        public event Action OnUpdate;
        public event Action OnRender;

        public void Close()
        {
            if (_isClosing)
                return;

            _isClosing = true;
            bool? cancelClose = OnClosing?.Invoke();
            if (cancelClose == true) // we can't write `if (cancelClose)` because cancelClose is nullable type
            {
                _isClosing = false;
                return;
            }
            glfw.SetWindowShouldClose(handle, true);
            OnClosed?.Invoke();
        }

        public void Hide()
        {
            glfw.HideWindow(handle);
        }

        public void Show()
        {
            OnShow?.Invoke();
            glfw.ShowWindow(handle);
        }

        public void Update()
        {
            glfw.PollEvents();
            OnUpdate?.Invoke();
            OnRender?.Invoke();
        }

        public void Destroy()
        {
            glfw.DestroyWindow(handle);
            handle = null;
        }

        public bool ShouldClose() => glfw.WindowShouldClose(handle);

        public GlfwWindow(string title, Int2 position, Int2 size, WindowState flags)
        {
            glfw = SilkGlfw.GetApi();
            if (glfw.Init() == false)
            {
                Console.WriteLine("GLFW doesn't init");
            }

            // Set hints
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
            Position = position;

            // Set callbacks
            glfw.SetWindowSizeCallback(handle, (win, w, h) => OnResized?.Invoke(w, h));
            glfw.SetFramebufferSizeCallback(handle, (win, w, h) => OnFramebufferResized?.Invoke(w, h));
            glfw.SetWindowCloseCallback(handle, (win) => Close());

            NativeHandle = new GlfwNativeWindow(glfw, handle).ToEnigma();
        }
    }
}

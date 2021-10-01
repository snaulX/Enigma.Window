using System;
using Enigma.Window;
using Silk.NET.GLFW;
using Silk.NET.Core.Contexts;
using Vortice.Mathematics;
using SilkGlfw = Silk.NET.GLFW.Glfw;

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
        private readonly GlfwNativeWindow nativeWindow;

        // Fields for custom usage;
        private string _title;
        private bool _isClosing = false;

        public IntPtr Handle 
        { 
            get 
            {
                return nativeWindow.Kind switch
                {
                    NativeWindowFlags.Win32 => nativeWindow.Win32.Value.Hwnd,
                    NativeWindowFlags.Wayland => nativeWindow.Wayland.Value.Surface,
                    NativeWindowFlags.UIKit => nativeWindow.UIKit.Value.Window,
                    NativeWindowFlags.Cocoa => nativeWindow.Cocoa.Value,
                    NativeWindowFlags.WinRT => nativeWindow.WinRT.Value,
                    NativeWindowFlags.Android => nativeWindow.Android.Value.Window, // Window or Surface?
                    NativeWindowFlags.X11 => unchecked((IntPtr)(long)(ulong)new UIntPtr(nativeWindow.X11.Value.Window)),
                    _ => (IntPtr)nativeWindow.Glfw,
                };
            } 
        }

        public string Title { get => _title; set { glfw.SetWindowTitle(handle, value); _title = value; } }
        public Int2 Position { get { glfw.GetWindowPos(handle, out int x, out int y); return new Int2(x, y); } set => glfw.SetWindowPos(handle, value.X, value.Y); }
        public Int2 Size { get { glfw.GetWindowSize(handle, out int w, out int h); return new Int2(w, h); } set => glfw.SetWindowSize(handle, value.X, value.Y); }

        public bool Exists => handle != null;
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

        public event Action OnResized;
        public event Func<bool> OnClosing;
        public event Action OnClosed;
        public event Action OnShow;

        public void Close()
        {
            if (_isClosing)
                return;

            _isClosing = true;
            bool? cancelClose = OnClosing?.Invoke();
            if (cancelClose == true) // we can't write if (cancelClose) because cancelClose is nullable type
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
        }

        public void Destroy()
        {
            glfw.DestroyWindow(handle);
            handle = null;
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
            Position = position;
            nativeWindow = new GlfwNativeWindow(glfw, handle);
        }
    }
}

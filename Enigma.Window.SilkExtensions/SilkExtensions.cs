using System;
using Silk.NET.Core.Contexts;

namespace Enigma.Window.Silk
{
    public static class SilkExtensions
    {
        public static NativeWindowType ToEnigma(this NativeWindowFlags windowFlags)
        {
            return windowFlags.CheckFlags(
                (NativeWindowFlags.Win32, NativeWindowType.Win32),
                (NativeWindowFlags.X11, NativeWindowType.X11),
                (NativeWindowFlags.Cocoa, NativeWindowType.Cocoa),
                (NativeWindowFlags.Wayland, NativeWindowType.Wayland),
                (NativeWindowFlags.Android, NativeWindowType.Android),
                (NativeWindowFlags.WinRT, NativeWindowType.WinRT),
                (NativeWindowFlags.UIKit, NativeWindowType.UIKit),
                (NativeWindowFlags.Vivante, NativeWindowType.Vivante));
        }

        public static NativeWindow ToEnigma(this INativeWindow nativeWindow)
        {
            Func<NativeWindow> defaultNw = () => new NativeWindow(nativeWindow.Kind.ToEnigma());
            return nativeWindow.Kind.CheckFlags(
                (NativeWindowFlags.Glfw, defaultNw), // use functions to don't create windows before checking flags
                (NativeWindowFlags.Sdl, defaultNw),
                (NativeWindowFlags.Win32, () => NativeWindow.CreateWin32(nativeWindow.Win32.Value.Hwnd, nativeWindow.Win32.Value.HInstance)),
                (NativeWindowFlags.Wayland, defaultNw),
                (NativeWindowFlags.DirectFB, defaultNw),
                (NativeWindowFlags.X11, defaultNw),
                (NativeWindowFlags.Haiku, defaultNw),
                (NativeWindowFlags.OS2, defaultNw),
                (NativeWindowFlags.Vivante, defaultNw),
                (NativeWindowFlags.Android, () => NativeWindow.CreateAndriod(nativeWindow.Android.Value.Window, nativeWindow.Android.Value.Surface)),
                (NativeWindowFlags.WinRT, () => NativeWindow.CreateWinRT(nativeWindow.WinRT.Value)),
                (NativeWindowFlags.Cocoa, () => NativeWindow.CreateCocoa(nativeWindow.Cocoa.Value)),
                (NativeWindowFlags.UIKit, defaultNw));
        }
    }
}

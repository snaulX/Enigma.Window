using System;

namespace Enigma.Window
{
    public class NativeWindow
    {
        public NativeWindow(NativeWindowType nativeWindowType)
        {
            Type = nativeWindowType;
        }

        public static NativeWindow CreateWin32(IntPtr hwnd, IntPtr hInstance) 
            => new NativeWindow(NativeWindowType.Win32) { Win32 = new Win32NativeWindow { HInstance = hInstance, Hwnd = hwnd } };

        public static NativeWindow CreateWinRT(IntPtr window)
            => new NativeWindow(NativeWindowType.WinRT) { WinRT = new WinRTNativeWindow { Window = window } };

        public NativeWindowType Type { get; set; }

        public Win32NativeWindow Win32 { get; set; }
        public AndroidNativeWindow Android { get; set;  }
        public WaylandNativeWindow Wayland { get; set; }
        public X11NativeWindow X11 { get; set; }
        public CocoaNativeWindow Cocoa { get; set; }
        public WinRTNativeWindow WinRT { get; set; }
        public VivanteNativeWindow Vivante { get; set; }

        public IntPtr PlatformHandle => Type switch
        {
            NativeWindowType.Win32 => Win32.Hwnd,
            NativeWindowType.X11 => unchecked((IntPtr)(long)(ulong)X11.Window),
            NativeWindowType.Wayland => Wayland.Surface,
            NativeWindowType.Cocoa => Cocoa.Window,
            NativeWindowType.UIKit => throw new NotImplementedException(),
            NativeWindowType.Android => Android.Window,
            NativeWindowType.WinRT => WinRT.Window,
            NativeWindowType.Vivante => Vivante.Window,
            _ => throw new NotImplementedException(),
        };
    }
}

using System;
using System.Collections.Generic;

namespace Enigma.Window
{
    [Flags]
    public enum WindowState
    {
        None = 0,
        Fullscreen = 1 << 0,
        FullscreenDesktop = 1 << 1,
        Borderless = 1 << 2,
        Resizable = 1 << 3,
        Maximized = 1 << 4,
    }
}

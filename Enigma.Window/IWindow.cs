using System;
using Vortice.Mathematics;

namespace Enigma.Window
{
    public interface IWindow
    {
        IntPtr Handle { get; }
        string Title { get; set; }
        Int2 Position { get; set; }
        Int2 Size { get; set; }
        bool Exists { get; }
        bool IsMinimized { get; }
        bool IsClosing { get; }

        event Action OnResized;
        event Action OnClosed;
        event Action OnShow;
        event Func<bool> OnClosing;

        void Show();
        void Hide();
        void Close();
        void Update();
    }
}

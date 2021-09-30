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

        event Action OnResized, OnClosing, OnClosed;

        void Show();
        void Hide();
        void Close();
    }
}

using System;
using Vortice.Mathematics;

namespace Enigma.Window
{
    public interface IWindow
    {
        NativeWindow NativeHandle { get; }
        string Title { get; set; }
        Int2 Position { get; set; }
        Int2 Size { get; set; }
        bool IsMinimized { get; }
        bool IsClosing { get; }

        event Action<int, int> OnResized;
        event Action<int, int> OnFramebufferResized;
        event Action OnClosed;
        event Action OnShow;
        event Action OnRender;
        event Action OnUpdate;
        event Func<bool> OnClosing;

        void Show();
        void Hide();
        void Close();
        void Update();
        void Destroy();
        bool ShouldClose();
    }
}

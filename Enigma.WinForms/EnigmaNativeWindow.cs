using System;
using System.Drawing;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using Enigma.Window;
using Vortice.Mathematics;
using WFNativeWindow = System.Windows.Forms.NativeWindow;
using ENativeWindow = Enigma.Window.NativeWindow;

namespace Enigma.WinForms
{
    public class EnigmaNativeWindow : WFNativeWindow, IWindow
    {
        public ENativeWindow NativeHandle => _eNativeWindow;

        public string Title { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }
        public Int2 Position { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }
        public Int2 Size { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }

        public bool IsMinimized => throw new NotImplementedException();

        public bool IsClosing => throw new NotImplementedException();

        public event Action<int, int> OnResized;
        public event Action<int, int> OnFramebufferResized;
        public event Action OnClosed;
        public event Action OnShow;
        public event Action OnRender;
        public event Action OnUpdate;
        public event Func<bool> OnClosing;

        #region WM_ constants
        // http://pinvoke.net/default.aspx/Constants.WM
        private const int WM_PAINT = 0xF;
        private const int WM_QUIT = 0x12;
        private const int WM_CLOSE = 0x10;
        #endregion

        private ENativeWindow _eNativeWindow;
        private bool _isClosed = false;

        public EnigmaNativeWindow(Control parent, int x, int y, int width, int height, WindowState states)
        {
            CreateParams cp = new CreateParams
            {
                X = x,
                Y = y,
                Width = width,
                Height = height,
                Parent = parent.Handle
            };

            CreateHandle(cp);
        }

        public void Close()
        {
            if (OnClosing?.Invoke() != true)
            {
                _isClosed = true;
                Destroy();
                OnClosed?.Invoke();
            }
        }

        public void Destroy()
        {
            DestroyHandle();
        }

        public void Hide()
        {
        }

        public bool ShouldClose()
        {
            return _isClosed;
        }

        public void Show()
        {
        }

        public void Update() => OnUpdate?.Invoke();

        protected override void OnHandleChange()
        {
            _eNativeWindow = ENativeWindow.CreateWin32(Handle, IntPtr.Zero);
        }

        protected override void WndProc(ref Message m)
        {
            switch (m.Msg)
            {
                case WM_PAINT:
                    OnRender?.Invoke();
                    break;
                case WM_CLOSE:
                case WM_QUIT:
                    Close();
                    break;
            }
            base.WndProc(ref m);
        }
    }
}

#include <windows.h>

LRESULT CALLBACK myfunc(HWND, UINT, WPARAM, LPARAM);
WNDCLASS a;
int flag = 0, x1, y1;

int APIENTRY WinMain(HINSTANCE i, HINSTANCE j, char *k, int l)
{
    HWND h;
    MSG m;

	a.style = CS_HREDRAW | CS_VREDRAW;
    a.hInstance = i;
    a.lpszClassName = L"my";
    a.lpfnWndProc = myfunc;
    a.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));

    RegisterClass(&a);
    h = CreateWindow(L"my", L"title", WS_OVERLAPPEDWINDOW, 20, 20, 300, 200, 0, 0, i, 0);
    ShowWindow(h, 3);

    while (GetMessage(&m, 0, 0, 0))
    {
        DispatchMessage(&m);
    }

    return 0;
}

LRESULT CALLBACK myfunc(HWND w, UINT x, WPARAM y, LPARAM z)
{
    HDC d;
    switch (x)
    {
        case WM_LBUTTONDOWN:
            if (!flag)
            {
				x1 = LOWORD(z);
                y1 = HIWORD(z);
                flag = 1;
            }
            else
            {
                d = GetDC(w);
				MoveToEx(d, x1, y1, 0);
				LineTo(d, LOWORD(z), HIWORD(z));
                ReleaseDC(w, d);
                flag = 0;
            }
			break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(w, x, y, z);
    }
    return 0;
}
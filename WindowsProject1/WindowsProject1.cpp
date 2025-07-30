#include <windows.h>

LRESULT CALLBACK myfunc(HWND, UINT, WPARAM, LPARAM);
WNDCLASS a;

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
	PAINTSTRUCT p;
	RECT r;
    switch (x)
    {
        case WM_PAINT:
            d = BeginPaint(w, &p);
            GetClientRect(w, &r);
			DrawText(d, L"Hello!", -1, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            EndPaint(w, &p);
			break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(w, x, y, z);
    }
    return 0;
}
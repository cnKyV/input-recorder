#include <iostream>
#include <cwchar>
#include <windef.h>
#include <windows.h>
#include <debugapi.h>


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Register the window class
    const wchar_t CLASS_NAME[]  = L"MyWindowClass";

    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = reinterpret_cast<LPCSTR>(CLASS_NAME);

    RegisterClass(&wc);

    // Create the window
    HWND hwnd = CreateWindowExW(
            0,                              // Optional window styles
            CLASS_NAME,                     // Window class
            L"My Window",                   // Window text
            WS_OVERLAPPEDWINDOW,            // Window style

            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            NULL,       // Parent window
            NULL,       // Menu
            hInstance,  // Instance handle
            NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    wchar_t msg[32];
    switch (uMsg)
    {
        case WM_SYSKEYDOWN:
            swprintf_s(msg, L"WM_SYSKEYDOWN: 0x%x\n", wParam);
            OutputDebugStringW(msg);
            break;

        case WM_SYSCHAR:
            swprintf_s(msg, L"WM_SYSCHAR: %c\n", (wchar_t)wParam);
            OutputDebugStringW(msg);
            break;

        case WM_SYSKEYUP:
            swprintf_s(msg, L"WM_SYSKEYUP: 0x%x\n", wParam);
            OutputDebugStringW(msg);
            break;

        case WM_KEYDOWN:
            swprintf_s(msg, L"WM_KEYDOWN: 0x%x\n", wParam);
            OutputDebugStringW(msg);
            break;

        case WM_KEYUP:
            swprintf_s(msg, L"WM_KEYUP: 0x%x\n", wParam);
            OutputDebugStringW(msg);
            break;

        case WM_CHAR:
            swprintf_s(msg, L"WM_CHAR: %c\n", (wchar_t)wParam);
            OutputDebugStringW(msg);
            break;

            /* Handle other messages (not shown) */

    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
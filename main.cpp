#include <iostream>
#include "include/win-api/win-kbd-hook.hpp"

int main()
{
    HHOOK kbd = SetWindowsHookEx(WH_KEYBOARD_LL, &KBDHook, 0, 0);

    MSG message;
    while(GetMessage(&message, NULL, NULL, NULL) > 0){
        TranslateMessage(&message);
        DispatchMessage(&message);

    }

    UnhookWindowsHookEx(kbd);
    return 0;
}
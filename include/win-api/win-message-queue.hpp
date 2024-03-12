//
// Created by cenka on 3/12/2024.
//

#ifndef INPUT_RECORDER_WIN_MESSAGE_QUEUE_HPP
#define INPUT_RECORDER_WIN_MESSAGE_QUEUE_HPP

#include "win-kbd-hook.hpp"
#include <thread>

struct message_queue{
private:
    HHOOK kbd;
    bool stopFlag;

    static void start_message_queue()
    {
        MSG message;
        while(GetMessage(&message, NULL, NULL, NULL) > 0){
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
    }


public:
    void start()
    {
        stopFlag = false;
        kbd = SetWindowsHookEx(WH_KEYBOARD_LL, WinKeyboardHook::KBDHook , 0, 0);
        std::thread t(&message_queue::start_message_queue);
        t.join();
    }

    void stop()
    {
        stopFlag = true;
        UnhookWindowsHookEx(kbd);
    }
};

#endif //INPUT_RECORDER_WIN_MESSAGE_QUEUE_HPP

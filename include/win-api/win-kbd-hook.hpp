//
// Created by cenka on 3/9/2024.
//

#ifndef INPUT_RECORDER_WIN_KBD_HOOK_HPP
#define INPUT_RECORDER_WIN_KBD_HOOK_HPP

#include "../stdafx.h"
#include <windows.h>
#include <vector>
#include "../utils/time-utilities.hpp"
#include "key.hpp"


LRESULT CALLBACK KBDHook(int nCode, WPARAM wParam, LPARAM lParam)
{
    auto *s = reinterpret_cast<KBDLLHOOKSTRUCT *>(lParam);
    char c;
    static std::unique_ptr<std::chrono::steady_clock::time_point> ptrBegin = nullptr;
    static auto* pressedDownKeys = new std::vector<Key>;
    std::chrono::steady_clock::time_point end;

    switch (wParam) {
        case WM_KEYDOWN:
            if (std::find_if(pressedDownKeys->begin(), pressedDownKeys->end(),[&](const Key& key) {
                return key.key == s->vkCode;
            }) == pressedDownKeys->end())
            {
                ptrBegin = std::make_unique<std::chrono::steady_clock::time_point>(std::chrono::steady_clock::now());
                pressedDownKeys->emplace_back(s->vkCode, *ptrBegin);
            }

            c = MapVirtualKey(s->vkCode, MAPVK_VK_TO_CHAR);
            std::cout << "Vk Code: " << s->vkCode << std::endl;
            std::cout << "VirtualKeyResult: " << c << std::endl;
            std::cout << "Time lapsed" << std::endl;

            break;

        case WM_KEYUP:
            if (ptrBegin)
            {
                end = std::chrono::steady_clock::now();
                std::cout << "Elapsed Time(ms): " << std::chrono::duration_cast<std::chrono::milliseconds>(end-*ptrBegin).count() << " ms" << std::endl;

                if (std::find_if(pressedDownKeys->begin(), pressedDownKeys->end(),[&](const Key& key) {
                    return key.key == s->vkCode;
                }) != pressedDownKeys->end())
                {
                    for (size_t i = 0; i < pressedDownKeys->size(); ++i) {
                        if (pressedDownKeys->at(i).key == s->vkCode)
                        {
                            pressedDownKeys->erase(pressedDownKeys->begin() + i, pressedDownKeys->begin()+i+1);
                        }
                    }
                }

            }
            break;

        default:
            break;
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}





#endif //INPUT_RECORDER_WIN_KBD_HOOK_HPP

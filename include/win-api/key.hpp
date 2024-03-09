//
// Created by cenka on 3/9/2024.
//

#ifndef INPUT_RECORDER_KEY_HPP
#define INPUT_RECORDER_KEY_HPP

#include "../stdafx.h"
#include <windows.h>

struct Key{
    DWORD key;
    std::chrono::steady_clock::time_point start_time;

    Key(DWORD key, std::chrono::steady_clock::time_point start_time):key(key),start_time(start_time){}
};
#endif //INPUT_RECORDER_KEY_HPP

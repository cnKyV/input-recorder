//
// Created by cenka on 3/7/2024.
//

#ifndef INPUT_RECORDER_INPUT_HPP
#define INPUT_RECORDER_INPUT_HPP

#include "stdafx.h"
#include "enum-types.hpp"
#include <chrono>

typedef std::chrono::duration<double, std::milli> MsDuration;

struct Input
{
    Input(wchar_t key, InputPressType inputPressType, MsDuration duration):
    _key(key), _inputPressType(inputPressType), _duration(duration){}

    [[nodiscard]] wchar_t getKey() const {return _key;}
    [[nodiscard]] InputPressType getInputPressType() const {return _inputPressType;}
    [[nodiscard]] MsDuration getDuration() const {return _duration;}

private:
    wchar_t _key;
    InputPressType _inputPressType;
    MsDuration _duration;
};



#endif //INPUT_RECORDER_INPUT_HPP

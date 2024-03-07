//
// Created by cenka on 3/7/2024.
//

#ifndef INPUT_RECORDER_INPUT_HPP
#define INPUT_RECORDER_INPUT_HPP

#include <utility>

#include "stdafx.h"
#include "enum-types.hpp"

struct Input
{
    Input(std::string key, InputPressType inputPressType, MsDuration duration):
    _key(std::move(key)), _inputPressType(inputPressType), _duration(duration){}

    [[nodiscard]] std::string getKey() const {return _key;}
    [[nodiscard]] InputPressType getInputPressType() const {return _inputPressType;}
    [[nodiscard]] MsDuration getDuration() const {return _duration;}

private:
    std::string _key;
    InputPressType _inputPressType;
    MsDuration _duration;
};



#endif //INPUT_RECORDER_INPUT_HPP

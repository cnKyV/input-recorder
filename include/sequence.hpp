//
// Created by cenka on 3/7/2024.
//

#ifndef INPUT_RECORDER_SEQUENCE_HPP
#define INPUT_RECORDER_SEQUENCE_HPP

#include "stdafx.h"
#include "input.hpp"
#include "input-reader.hpp"
#include <queue>


class Sequence{
std::queue<Input> inputs;
Clock::time_point startTime, endTime;
bool beginRead = false;

public:
    void startSequence(){
        startTime = Clock::now();
        beginRead = true;
    }
    void endSequence(){
        endTime = Clock::now();
        beginRead = false;
    }

    void registerInput(const Input& input)
    {
        if (beginRead) inputs.push(input);
    }

    std::queue<Input> getSequence()
    {
        return inputs;
    }
};

#endif //INPUT_RECORDER_SEQUENCE_HPP

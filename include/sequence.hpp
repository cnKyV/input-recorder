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
    void start_sequence(){
        startTime = Clock::now();
        beginRead = true;
    }
    void end_sequence(){
        endTime = Clock::now();
        beginRead = false;
    }

    void initialize_sequence(std::queue<Input> inputList)
    {
        inputs = inputList;

    }

    std::queue<Input> get_sequence()
    {
        return inputs;
    }
};

#endif //INPUT_RECORDER_SEQUENCE_HPP

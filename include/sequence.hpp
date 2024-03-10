//
// Created by cenka on 3/7/2024.
//

#ifndef INPUT_RECORDER_SEQUENCE_HPP
#define INPUT_RECORDER_SEQUENCE_HPP

#include "stdafx.h"
#include "input.hpp"
#include "input-reader.hpp"
#include <queue>
#include "win-api/key.hpp"


class Sequence{
std::vector<Key> inputs;
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

    void initialize_sequence(std::vector<Key> inputList)
    {
        inputs = inputList;

    }
};

#endif //INPUT_RECORDER_SEQUENCE_HPP

//
// Created by cenka on 3/7/2024.
//

#ifndef INPUT_RECORDER_SEQUENCE_HPP
#define INPUT_RECORDER_SEQUENCE_HPP

#include "stdafx.h"
#include "input.hpp"
#include "input-reader.hpp"
#include <queue>
#include "win-api/win-message-queue.hpp"
#include "win-api/key.hpp"


class Sequence{
    std::vector<Key> inputs;
    Clock::time_point startTime, endTime;
    message_queue messageQueue;
    bool beginRead = false;

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
public:
    void begin()
    {
        start_sequence();
        messageQueue.start();
    }

    void end()
    {
      if(beginRead)
      {
          messageQueue.stop();
          end_sequence();
      }
    }

    ~Sequence()
    {
        std::time_t time = std::chrono::system_clock::to_time_t(Clock::now());
        std::cout << "Deconstruct Sequence Timestamp: " << std::ctime(&time) << std::endl;
    }

};

#endif //INPUT_RECORDER_SEQUENCE_HPP

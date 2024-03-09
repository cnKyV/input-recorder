//
// Created by cenka on 3/9/2024.
//

#ifndef INPUT_RECORDER_TIME_UTILITIES_HPP
#define INPUT_RECORDER_TIME_UTILITIES_HPP

#include "../stdafx.h"

template <
        class result_t   = std::chrono::milliseconds,
        class clock_t    = std::chrono::steady_clock,
        class duration_t = std::chrono::milliseconds
>
auto since(std::chrono::time_point<clock_t, duration_t> const& start)
{
return std::chrono::duration_cast<result_t>(clock_t::now() - start);
}

template <class DT = std::chrono::milliseconds,
        class ClockT = std::chrono::steady_clock>
class Timer
{
    using timep_t = typename ClockT::time_point;
    timep_t _start = ClockT::now(), _end = {};

public:
    void tick() {
        _end = timep_t{};
        _start = ClockT::now();
    }

    void tock() { _end = ClockT::now(); }

    template <class T = DT>
    auto duration() const {
        gsl_Expects(_end != timep_t{} && "toc before reporting");
        return std::chrono::duration_cast<T>(_end - _start);
    }
};
#endif //INPUT_RECORDER_TIME_UTILITIES_HPP

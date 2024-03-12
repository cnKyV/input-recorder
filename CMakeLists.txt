cmake_minimum_required(VERSION 3.26)
project(input_recorder)

set(CMAKE_CXX_STANDARD 17)

add_executable(input_recorder main.cpp
        include/input-reader.hpp
        include/defines.hpp
        include/input.hpp
        include/sequence.hpp
        include/stdafx.h
        include/enum-types.hpp
        include/constants/keys.hpp
        include/win-api/win-kbd-hook.hpp
        include/utils/time-utilities.hpp
        include/win-api/key.hpp
        include/win-api/win-message-queue.hpp
)

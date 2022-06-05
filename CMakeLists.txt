cmake_minimum_required(VERSION 3.20)

include_directories(Include)

add_executable(Test-FIFO Tests/Test-FIFO.cpp "Source/BOS/Terminal.cpp")

cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)

add_executable(mainApp main.cpp)
target_link_libraries(mainApp pthread)


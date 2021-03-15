cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)

message("Directory path: " ${CMAKE_CURRENT_SOURCE_DIR})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../include)
#add_subdirectory(include)
add_executable(mainApp main.cpp)
target_link_libraries(mainApp pthread)




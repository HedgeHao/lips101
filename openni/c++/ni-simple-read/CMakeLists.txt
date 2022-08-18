cmake_minimum_required(VERSION 3.3)

project(ni-simple-read CXX)

add_executable(${PROJECT_NAME} ni-simple-read.cpp)

target_link_libraries(${PROJECT_NAME} OpenNI2)

cmake_minimum_required(VERSION 3.3)

project( ni-hello CXX )

add_executable( ${PROJECT_NAME} ni-hello.cpp )

target_link_libraries(${PROJECT_NAME} OpenNI2)


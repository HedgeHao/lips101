cmake_minimum_required(VERSION 3.3)

project( example CXX )

add_executable( ${PROJECT_NAME} example.cpp )

find_package(OpenCV)

target_link_libraries(${PROJECT_NAME} OpenNI2)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
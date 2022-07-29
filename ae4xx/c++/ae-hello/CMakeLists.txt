cmake_minimum_required(VERSION 3.3)

project( ae-hello CXX )

if(MSVC)
    include_directories("C:/Program Files (x86)/Intel RealSense SDK 2.0/include")
    link_directories("C:/Program Files (x86)/Intel RealSense SDK 2.0/lib/x64")
endif()

add_executable( ${PROJECT_NAME} ae-hello.cpp )

find_package(OpenCV)

target_link_libraries(${PROJECT_NAME} realsense2 )
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
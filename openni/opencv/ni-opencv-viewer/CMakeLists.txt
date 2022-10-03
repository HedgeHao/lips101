cmake_minimum_required(VERSION 3.3)

project( ni-opencv-viewer CXX )


include_directories($ENV{OPENNI2_INCLUDE})
link_directories($ENV{OPENNI2_REDIST})

add_executable( ${PROJECT_NAME} ni-opencv-viewer.cpp )

find_package(OpenCV)

target_link_libraries(${PROJECT_NAME} OpenNI2 )
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
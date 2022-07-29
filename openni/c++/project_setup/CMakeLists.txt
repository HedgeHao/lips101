cmake_minimum_required(VERSION 3.3)

project( project_setup CXX )

if(MSVC)
    include_directories("C:/Program Files/OpenNI2/Include")
    link_directories("C:/Program Files/OpenNI2/Lib")
endif()

add_executable( ${PROJECT_NAME} project_setup.cpp )

find_package(OpenCV)

target_link_libraries(${PROJECT_NAME} OpenNI2)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
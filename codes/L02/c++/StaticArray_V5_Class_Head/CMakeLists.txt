cmake_minimum_required(VERSION 3.10)

#add_library(StaticArray StaticArray.cpp)

# add the MathFunctions library
add_subdirectory(StaticArray)



get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${ProjectId})

add_executable(${ProjectId} main.cpp)

target_link_libraries(${ProjectId} PUBLIC StaticArray)
target_include_directories(${ProjectId} PUBLIC
                          "${PROJECT_SOURCE_DIR}/StaticArray"
                          )

#set minimum version
cmake_minimum_required(VERSION 3.10)

#get the dir name as projectn name
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${ProjectId})

#add executable both main and static array
add_executable(${ProjectId} main.cpp StaticArray.cpp)

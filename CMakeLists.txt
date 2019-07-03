cmake_minimum_required(VERSION 3.14)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR})

#------------------LinearList-------------------
set(seqList LinearList/main.c LinearList/SeqList.c)

add_executable(seqList ${seqList})
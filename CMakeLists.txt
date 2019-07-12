cmake_minimum_required(VERSION 3.14)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR})

#------------------LinearList-------------------
set(seqList LinearList/SeqList_main.c LinearList/SeqList.c)
set(linkList  LinearList/LinkList_main.c LinearList/LinkList.c)
set(seqStack Stack&Queue/SeqStackMain.c Stack&Queue/SeqStack.c)


add_executable(seqList ${seqList})
add_executable(linkList ${linkList})
add_executable(seqStack ${seqStack})
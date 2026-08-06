cmake_minimum_required(VERSION 3.10)

project(LinkedList C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(
    LinkedList
    main.c
    src/insert.c
    src/delete.c
    src/utils.c
)
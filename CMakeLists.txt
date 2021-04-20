cmake_minimum_required(VERSION 3.16)
project(os_structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(usr_system_space mains/usr_system_space.cpp)
add_executable(process_management mains/process_management.cpp)
add_executable(fork_and_exec mains/fork_and_exec.cpp)
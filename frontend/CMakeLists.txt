cmake_minimum_required(VERSION 3.15)
project(frontend C)

#SETTING FLAGS
set(CMAKE_C_STANDARD 99)
set(THREADS_PREFER_PTHREAD_FLAG ON)

#INCLUDE PACKAGES
include(FindPkgConfig)
find_package(Threads REQUIRED)

#ADDING EXECUTABLES
add_executable(frontend main.c)

#LINKING
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads) #LINKING LIBRARIES (THREADS)
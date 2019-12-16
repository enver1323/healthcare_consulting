cmake_minimum_required(VERSION 3.15)
project(backend C)

#SETTING FLAGS
set(CMAKE_C_STANDARD 99)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
foreach (FLAG ${LIBMYSQLCLIENT_CFLAGS_OTHER})
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${FLAG}")
endforeach ()

#INCLUDE PACKAGES
include(FindPkgConfig)

find_package(Threads REQUIRED)
pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)

link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})

#ADDING EXECUTABLES
add_executable(backend main.c domain/services/hospitalService.h)

#LINKING
target_include_directories(${PROJECT_NAME} PRIVATE ${LIBMYSQLCLIENT_INCLUDE_DIRS})          #INCLUDING DIRECTORIES (MYSQL)
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBMYSQLCLIENT_LIBRARIES} Threads::Threads) #LINKING LIBRARIES (MYSQL, THREADS)

# DB compile command
# gcc -o EXECUTABLE_FILENAME $(mysql_config --cflags) SOURCEFILE.C $(mysql_config --libs)
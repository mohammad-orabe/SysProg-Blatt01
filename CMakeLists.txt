cmake_minimum_required(VERSION 3.15)
project(HA1)

set(CMAKE_CXX_STANDARD 14)

include_directories("Vorgaben Praxisteil-20200507")

add_executable(HA1
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/HA1.cbp
        cmake-build-debug/Makefile
        "Vorgaben Praxisteil-20200507/main.c"
        "Vorgaben Praxisteil-20200507/Makefile"
        "Vorgaben Praxisteil-20200507/prio_q.c"
        "Vorgaben Praxisteil-20200507/prio_q.h"
        blatt1.pdf
        CMakeLists.txt)

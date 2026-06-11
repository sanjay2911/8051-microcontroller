cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE config/sdcc-toolchain.cmake)

project(build_all LANGUAGES C)

add_subdirectory(apps)
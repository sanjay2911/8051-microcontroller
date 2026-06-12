cmake_minimum_required(VERSION 3.20)
include("../../config/common.cmake")
set_target_name()

if(NOT PROJECT_NAME)
    set(CMAKE_TOOLCHAIN_FILE ../../config/sdcc-toolchain.cmake)
    project(${TARGET_NAME} LANGUAGES C)
endif()

# Sources
file(GLOB SRC_FILES src/*.c)
include_directories(inc)

add_executable(${TARGET_NAME} ${SRC_FILES})
add_hex_target(${TARGET_NAME})
add_flash_target(${TARGET_NAME})
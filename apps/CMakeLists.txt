cmake_minimum_required(VERSION 3.20)

if(NOT PROJECT_NAME)
    set(CMAKE_TOOLCHAIN_FILE ../config/sdcc-toolchain.cmake)
    project(build_all LANGUAGES C)
endif()

# 1. Gather all items while enabling build system auto-refresh
file(GLOB children CONFIGURE_DEPENDS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" *)

# 2. Iterate safely through each item
foreach(child IN LISTS children)
    set(current_item_path "${CMAKE_CURRENT_SOURCE_DIR}/${child}")

    # 3. Verify it is a valid directory
    if(IS_DIRECTORY "${current_item_path}")
        # 4. Check for the mandatory CMakeLists.txt to prevent add_subdirectory crashes
        if(EXISTS "${current_item_path}/CMakeLists.txt")
            message(STATUS "[SUCCESS] Found project directory: ${child}")

            # 5. Dynamically add the directory using the loop variable
            add_subdirectory("${child}")
        else()
            message(WARNING "[SKIPPED] Folder '${child}' has no CMakeLists.txt file.")
        endif()
    endif()
endforeach()

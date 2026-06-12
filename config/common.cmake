cmake_minimum_required(VERSION 3.20)

find_program(PACKIHX_EXECUTABLE packihx REQUIRED)
find_program(AVR_PROGRAMMER avrdude REQUIRED)

macro(set_target_name)
    get_filename_component(
        TARGET_NAME
        ${CMAKE_CURRENT_SOURCE_DIR}
        NAME
    )
endmacro()

function(add_hex_target target_name)
    add_custom_command(
        TARGET ${target_name}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "Generating HEX file..."
        COMMAND ${PACKIHX_EXECUTABLE} ${target_name}.ihx > ${target_name}.hex
        COMMAND mkdir -p ${CMAKE_BINARY_DIR}/out
        COMMAND mv ${target_name}.hex ${CMAKE_BINARY_DIR}/out
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
endfunction()

function(add_flash_target target_name)
    add_custom_target(
        flash-${target_name}
        COMMAND ${AVR_PROGRAMMER} -c usbasp -p at89s52 -C ${CMAKE_CURRENT_SOURCE_DIR}/../../config/avrdude.conf -U flash:w:${CMAKE_BINARY_DIR}/out/${target_name}.hex -F
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS ${target_name}
        USES_TERMINAL
    )
endfunction()

# This will create only one erase target while included multiple times within project
if(NOT TARGET erase)
    add_custom_target(
        erase
        COMMAND avrdude -c usbasp -p at89s52 -C ${CMAKE_SOURCE_DIR}/../avrdude.conf -e
    )
endif()

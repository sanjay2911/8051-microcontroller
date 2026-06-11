set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR mcs51)
set(CMAKE_C_COMPILER /usr/bin/sdcc)
set(CMAKE_C_COMPILER_WORKS 1)

# SDCC Configuration
add_compile_options(-mmcs51 --std-sdcc99)
add_link_options(-mmcs51 -Wl -m)
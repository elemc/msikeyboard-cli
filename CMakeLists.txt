cmake_minimum_required(VERSION 3.17.2)
project(msikeyboard_cli)
set (PROJECT_NAME msikeyboard_cli)
set(CMAKE_CXX_STANDARD 14)

if ( NOT CMAKE_MODULE_PATH )
    set(CMAKE_MODULE_PATH "/usr/share/cmake/Modules" ${CMAKE_MODULE_PATH})
endif( NOT CMAKE_MODULE_PATH)

find_package (libmsikeyboard REQUIRED)
find_package (Boost REQUIRED)

add_executable(msikeyboard_cli main.cpp MSIKeyboard.cpp MSIKeyboard.h Region.cpp Region.h)
target_link_libraries (${PROJECT_NAME} ${libmsikeyboard_LIBRARIES})

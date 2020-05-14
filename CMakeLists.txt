cmake_minimum_required(VERSION 3.16)
project(msikeyboard_cli)
set (PROJECT_NAME msikeyboard_cli)
set(CMAKE_CXX_STANDARD 11)

if ( NOT CMAKE_MODULE_PATH )
    set(CMAKE_MODULE_PATH "/usr/share/cmake/Modules" "/usr/local/share/cmake/Modules" ${CMAKE_MODULE_PATH})
endif( NOT CMAKE_MODULE_PATH)

find_package (libmsikeyboard REQUIRED)
find_package (Boost REQUIRED OPTIONAL_COMPONENTS program_options)

message("Include path: ${libmsikeyboard_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS}")

include_directories(${libmsikeyboard_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

add_executable(msikeyboard_cli main.cpp MSIKeyboard.cpp MSIKeyboard.h Region.cpp Region.h)
target_link_libraries (${PROJECT_NAME} ${libmsikeyboard_LIBRARIES} ${Boost_PROGRAM_OPTIONS_LIBRARY})

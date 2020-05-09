cmake_minimum_required(VERSION 3.16)
project(msikeyboard_cli)

set(CMAKE_CXX_STANDARD 14)
add_link_options("-lmsikeyboard")
add_executable(msikeyboard_cli main.cpp MSIKeyboard.cpp MSIKeyboard.h Region.cpp Region.h)
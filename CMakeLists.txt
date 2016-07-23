#
# CMakeLists.txt
#
# Copyright (c) 2016 Zach Peltzer.
# Subject to the MIT License.
#

cmake_minimum_required(VERSION "3.5" FATAL_ERROR)

project("cgm"
    VERSION "1.0"
    LANGUAGES "C")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")

add_subdirectory("src")
#add_subdirectory("test")


#
# src/CMakeLists.txt
#
# Copyright (c) 2016 Zach Peltzer.
# Subject to the MIT License.
#

include_directories(".")

set(HEADERS "vec2.h" "vec3.h" "vec4.h"
    "mat2.h" "mat3.h" "mat4.h"
    "transform.h" "project.h" "cgm.h")

set(SOURCES "vec2.inl" "vec3.inl" "vec4.inl"
    "mat2.inl" "mat3.inl" "mat4.inl"
    "transform.inl" "project.inl")

set(CGM_INCLUDE_DIR "include/cgm")

install(FILES ${HEADERS} ${SOURCES} DESTINATION ${CGM_INCLUDE_DIR})


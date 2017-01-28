#
# src/vector/CMakeLists.txt
#
# Copyright (c) 2016 Zach Peltzer.
# Subject to the MIT License.
#

set(SOURCES ${SOURCES} "vector/vec2.c" "vector/vec3.c" "vector/vec4.c"
    "vector/bvec2.c" "vector/bvec3.c" "vector/bvec4.c"
    "vector/ivec2.c" "vector/ivec3.c" "vector/ivec4.c"
    "vector/uvec2.c" "vector/uvec3.c" "vector/uvec4.c"
    "vector/dvec2.c" "vector/dvec3.c" "vector/dvec4.c"
    PARENT_SCOPE)

set(VECTOR_HEADERS "vec2.h" "vec3.h" "vec4.h"
    "bvec2.h" "bvec3.h" "bvec4.h"
    "ivec2.h" "ivec3.h" "ivec4.h"
    "uvec2.h" "uvec3.h" "uvec4.h"
    "dvec2.h" "dvec3.h" "dvec4.h")
install(FILES ${VECTOR_HEADERS} DESTINATION "${CGM_INCLUDE_DIR}/vector")


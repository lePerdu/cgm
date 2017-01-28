#
# src/matrix/CMakeLists.txt
#
# Copyright (c) 2016 Zach Peltzer.
# Subject to the MIT License.
#

set(SOURCES ${SOURCES} "matrix/mat2.c" "matrix/mat3.c" "matrix/mat4.c"
    "matrix/dmat2.c" "matrix/dmat3.c" "matrix/dmat4.c"
    PARENT_SCOPE)

set(MATRIX_HEADERS "mat2.h" "mat3.h" "mat4.h"
    "dmat2.h" "dmat3.h" "dmat4.h")
install(FILES ${MATRIX_HEADERS} DESTINATION "${CGM_INCLUDE_DIR}/matrix")


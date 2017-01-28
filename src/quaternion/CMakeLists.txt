#
# src/quaternion/CMakeLists.txt
#
# Copyright (c) 2016 Zach Peltzer.
# Subject to the MIT License.
#

set(SOURCES ${SOURCES} "quaternion/quaternion.c"
    "quaternion/dquaternion.c" PARENT_SCOPE)

set(QUATERNION_HEADERS "quaternion.h" "dquaternion.h")
install(FILES ${QUATERNION_HEADERS} DESTINATION
    "${CGM_INCLUDE_DIR}/quaternion")


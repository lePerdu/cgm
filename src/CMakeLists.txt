#
# src/CMakeLists.txt
#
# Copyright (c) 2016 Zach Peltzer.
# Subject to the MIT License.
#

set(HEADERS "transform.h" "project.h" "cgm.h")

set(SOURCES "transform.c" "project.c")

set(CGM_LIBRARY "cgm")
set(CGM_INCLUDE_DIR "include/cgm")

add_subdirectory("vector")
add_subdirectory("matrix")
add_subdirectory("quaternion")

add_library(${CGM_LIBRARY} SHARED ${SOURCES} ${HEADERS})
target_link_libraries(${CGM_LIBRARY} "m")

install(TARGETS ${CGM_LIBRARY} DESTINATION "lib")
install(FILES ${HEADERS} DESTINATION ${CGM_INCLUDE_DIR})


project( Cross )

add_executable( Cross Cross.cpp )

# generate YCM compile flags
set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )

set( Cross_VERSION_MAJOR 0 )
set( Cross_VERSION_MINOR 1 )

# config
configure_file(
	"${PROJECT_SOURCE_DIR}/CrossConfig.h.in"
	"${PROJECT_BINARY_DIR}/CrossConfig.h"
)


# SDL finder stuff
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Cross_SOURCE_DIR}/sdl2-cmake" )

find_package( SDL2 REQUIRED )
find_package( SDL2_ttf REQUIRED )

include_directories( SDL2_INCLUDE_DIR SDL2_ttf_INCLUDE_DIR )

link_libraries( SDL2_LIBRARY SDL2_ttf_LIBRARIES )


include_directories( "${PROJECT_BINARY_DIR}" )

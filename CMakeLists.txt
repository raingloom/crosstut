project( Cross )

add_executable( Cross Cross.cpp )

# generate YCM compile flags
set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )

set( Cross_VERSION_MAJOR 0 )
set( Cross_VERSION_MINOR 1 )

# don't clutter source and keep CMake stuff separate
set_target_properties( Cross
    PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/out/lib"
	LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/out/lib"
	RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/out/bin"
)

# config
configure_file(
	"${PROJECT_SOURCE_DIR}/CrossConfig.h.in"
	"${PROJECT_BINARY_DIR}/CrossConfig.h"
)
include_directories( "${PROJECT_BINARY_DIR}" )


# SDL finder stuff
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Cross_SOURCE_DIR}/sdl2-cmake" )

find_package( SDL2 REQUIRED )
#find_package( SDL2_ttf REQUIRED )

include_directories( ${SDL2_INCLUDE_DIR} )# ${SDL2_ttf_INCLUDE_DIR} )
message( "SDL2= ${SDL2_LIBRARY}" )
target_link_libraries( Cross ${SDL2_LIBRARY} )# ${SDL2_ttf_LIBRARIES} )

file( COPY assets DESTINATION "${PROJECT_BINARY_DIR}/out/" )

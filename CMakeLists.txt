project( Cross )

add_executable( Cross Cross.cpp )

# generate YCM compile flags
set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )

set( Cross_VERSION_MAJOR 0 )
set( Cross_VERSION_MINOR 1 )

# config
configure_file (
	"${PROJECT_SOURCE_DIR}/CrossConfig.h.in"
	"${PROJECT_BINARY_DIR}/CrossConfig.h"
)

find_package( SDL  )

include_directories( "${PROJECT_BINARY_DIR}" )

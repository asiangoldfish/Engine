# ProjectRoot/src/core/CMakeLists.txt

# Define the module name
set(MODULE_NAME shared)


# Define the core module target
add_library(${MODULE_NAME} SHARED
    JsonParser.h
    JsonParser.cpp
    Logger.h
    Logger.cpp
    Math.h
    Math.cpp
    pch.h
    pch.cpp
)

# Include directories for the core module (public includes)
target_include_directories( ${MODULE_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Internal
target_include_directories( ${MODULE_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/vendor
)

# Link SFML to the core module
target_link_libraries( core PUBLIC 
    sfml-system
    sfml-window
    sfml-graphics
)
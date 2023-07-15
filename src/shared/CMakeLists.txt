# ProjectRoot/src/core/CMakeLists.txt

# Define the module name
set(MODULE_NAME shared)


# Define the core module target
add_library(${MODULE_NAME} SHARED
    Logger.h
    Math.h
    pch.h
    Logger.cpp
    Math.cpp
    pch.cpp
)

# Include directories for the core module (public includes)
target_include_directories(out PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# Link SFML to the core module
target_link_libraries( core PUBLIC 
    sfml-system
    sfml-window
    sfml-graphics
)
# ProjectRoot/src/core/CMakeLists.txt

# Define the core module target
add_library( core
    BasicShape.h
    Framework.h
    GameTime.h
    BasicShape.cpp
    Framework.cpp
    GameTime.cpp
)

# Include directories for the core module (public includes)
target_include_directories( core PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Internal
target_include_directories(core PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# Link SFML to the core module
target_link_libraries(core PUBLIC 
    sfml-system
    sfml-window
    sfml-graphics
)
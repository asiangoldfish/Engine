# ProjectRoot/src/core/CMakeLists.txt

# Define the core module target
add_library( core
    BasicShape.h
    BasicShape.cpp
    Camera.h
    Camera.cpp
    Framework.h
    Framework.cpp
    GameObject.h
    GameObject.cpp
    GameTime.h
    GameTime.cpp
    Renderable.h
    Renderable.cpp
    ResourceHolder.inl
    ResourceHolder.hpp
)

# Include directories for the core module (public includes)
target_include_directories( core PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Internal
target_include_directories(core PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/vendor
)

# Link SFML to the core module
target_link_libraries(core PUBLIC 
    sfml-system
    sfml-window
    sfml-graphics
)
# ProjectRoot/src/core/CMakeLists.txt
set(MODULE_NAME rendering)

# Define the core module target
add_library(${MODULE_NAME}
    BasicShape.h
    Framework.h
    GameTime.h
    BasicShape.cpp
    Framework.cpp
    GameTime.cpp
)

# Include directories for the core module (public includes)
target_include_directories(${MODULE_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Internal
target_include_directories(${MODULE_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# Link SFML to the core module
target_link_libraries(${MODULE_NAME} PUBLIC 
    sfml-system
    sfml-window
    sfml-graphics
)
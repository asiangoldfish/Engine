# ProjectRoot/src/physics/CMakeLists.txt

# Define the physics module target
add_library( physics
    Emitter.h
    Emitter.cpp
    Particle.h
    Particle.cpp
    Physics.h
    Physics.cpp
    RigidBody.h
    RigidBody.cpp
)

# Include directories for the physics module (public includes)
target_include_directories( physics PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# Link SFML to the physics module
target_link_libraries( physics PUBLIC 
    sfml-system
    sfml-window
    sfml-graphics
)
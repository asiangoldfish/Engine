# ProjectRoot/src/events/CMakeLists.txt

# Define the events module target
add_library(events
    IObserver.h
    IObserver.cpp
    ISubject.h
    ISubject.cpp
)

# Include directories for the events module (public includes)
target_include_directories( events PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# Link SFML to the events module
target_link_libraries( events PUBLIC 
    sfml-system
    sfml-window
    sfml-graphics
)
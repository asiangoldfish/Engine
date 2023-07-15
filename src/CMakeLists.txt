# ProjectRoot/src/CMakeLists.txt

# Find SFML package
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Add the main executable and link modules
add_executable(out main.cpp)

# Include directories for modules
#target_include_directories(out PRIVATE
#    ${CMAKE_CURRENT_SOURCE_DIR}/core/include
#    ${CMAKE_CURRENT_SOURCE_DIR}/shared/include
#)

# Add subdirectories for each module
add_subdirectory(core)
add_subdirectory(events)
add_subdirectory(physics)
#add_subdirectory(rendering)
add_subdirectory(shared)

# Link the modules to the main executable
target_link_libraries(out PRIVATE
    core
    events
    physics 
    #rendering 
    shared
)

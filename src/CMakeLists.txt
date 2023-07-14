# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Set the project name
project(GameEngine)

# Add compiler flags or options if needed
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

# Add the subdirectories for each module
add_subdirectory(rendering)
add_subdirectory(physics)
add_subdirectory(events)
# Add more subdirectories for additional modules as needed

# Add the main executable or library target
# add_executable(GameEngine main.cpp)
# target_link_libraries(GameEngine PUBLIC RenderingModule PhysicsModule EventsModule ...)


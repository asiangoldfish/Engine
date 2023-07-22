cmake_minimum_required(VERSION 3.26)
project(GameEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the subdirectory for the source code
add_subdirectory(src)
add_subdirectory(vendor)
add_subdirectory(assets)

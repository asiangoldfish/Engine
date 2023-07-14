cmake_minimum_required(VERSION 3.12)
project(GameEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the subdirectory for the source code
add_subdirectory(src)

# Add the subdirectory for the game assets
add_subdirectory(assets)
add_subdirectory(modules/test)

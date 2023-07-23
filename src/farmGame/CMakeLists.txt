# Define the core module target
add_library( farmGame
    Crops.h
    Crops.cpp

    Tile.h
    Tile.cpp

    Tilemap.h
    Tilemap.cpp

    Tileset.h
    Tileset.cpp
)

# Include directories for the core module (public includes)
target_include_directories( farmGame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Internal
target_include_directories(farmGame PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/vendor
)

# Link SFML to the core module
target_link_libraries(farmGame PUBLIC 
    #sfml-system
    #sfml-window
    #sfml-graphics
)

# Configure dta files by copying them to the build directory
# configure_file(map.dta ${CMAKE_BINARY_DIR}/config/map.dta COPYONLY)

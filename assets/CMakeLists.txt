# Set the assets directory path
set(ASSETS_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Set the build directory path for assets inside the src directory
set(BUILD_DIR ${CMAKE_BINARY_DIR}/src/assets)

# Custom command to copy the entire assets directory to the build directory while preserving the directory structure
add_custom_command(
    OUTPUT ${BUILD_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${ASSETS_DIR} ${BUILD_DIR}
    DEPENDS ${ASSET_FILES}
    COMMENT "Copying assets directory..."
)

# Custom target to ensure the custom command is executed before building the project
add_custom_target(CopyAssets ALL DEPENDS ${BUILD_DIR})

# Function to copy individual asset files from assets to the build directory while preserving the directory structure
function(copy_asset_file FILE_PATH)
    file(RELATIVE_PATH REL_PATH ${ASSETS_DIR} ${FILE_PATH})
    get_filename_component(DIR ${REL_PATH} DIRECTORY)
    set(OUTPUT_DIR ${BUILD_DIR}/${DIR})
    file(MAKE_DIRECTORY ${OUTPUT_DIR})
    configure_file(${FILE_PATH} ${OUTPUT_DIR} COPYONLY)
endfunction()

# Find all files in the assets directory and its subdirectories
file(GLOB_RECURSE ASSET_FILES LIST_DIRECTORIES false ${ASSETS_DIR}/*)

# Copy each asset file to the build directory
foreach(ASSET_FILE ${ASSET_FILES})
    copy_asset_file(${ASSET_FILE})
endforeach()

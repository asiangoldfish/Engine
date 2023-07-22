# ProjectRoot/src/core/CMakeLists.txt

set(MODULE_NAME nlohmann)

# Define the core module target
add_library( ${MODULE_NAME}
    json.hpp
)

# Include directories for the core module (public includes)
target_include_directories( ${MODULE_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(${MODULE_NAME} PROPERTIES LINKER_LANGUAGE CXX)
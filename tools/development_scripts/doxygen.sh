#!/usr/bin/bash

# Exit if this script is run standalone
if [  "$( basename "$0" )" == "doxygen.sh" ]; then
    echo "ERROR: You cannot run this script standalone"
    exit -1
fi

generate_doxygen_docs() {
    # Check that doxygen is installed
    command -v doxygen &> /dev/null || { echo "Doxygen is not installed" && exit -1; }

    echo "Generating/Updating Doxygen documentation..."

    doxygen -g Doxyfile
    doxygen Doxyfile

    echo "Doxygen documentation has been generated/updated."
}

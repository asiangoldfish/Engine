#!/bin/bash

DIRPATH="$( dirname "$0" )"

# imports
source "$DIRPATH/scripts/help.sh"
source "$DIRPATH/scripts/doxygen.sh"
source "$DIRPATH/scripts/module.sh"

if [ "$#" -eq 0 ]; then
    display_help
    exit 0
fi

while [ "$1" != "" ]; do
    case $1 in
        -h | --help )
            case "$2" in
                --new-module | -n )
                    display_new_module_help
                    ;;
                --doxygen | -d )
                    display_doxygen_help
                    ;;
                * )
                    display_help
            esac
            exit 0
            ;;
        -n | --new-module )
            create_module
            exit 0
            ;;
        -d | --doxygen )
            generate_doxygen_docs
            exit 0
            ;;
        * )
            echo "Error: Invalid option: $1"
            display_help
            exit 1
            ;;
    esac
    shift
done


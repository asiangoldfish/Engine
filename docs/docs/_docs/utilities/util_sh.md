---
layout: default
title: util.sh
parent: Utilities
---

# util.sh

`util.sh` is Engine's utility tool that manages the project's various aspects, like building, installation or managing the development process.

## Usage
```shell
Usage: ./create_module.sh [options]
Options:
  -b, --build                  Build the project
  -c, --clean                  Clean the build directory
  -cb, --clean-build           Clean and build the project
  --continuous-build            Automatically builds on change
  -d, --doxygen                Generate or update Doxygen documentation
  -h, --help                   Display this help page
  -n, --new-module             Create a new module
  -r, --run                    Compile and run the program

Examples:
  ./create_module.sh -n             # Create a new module
  ./create_module.sh -d             # Generate or update Doxygen documentation
  ./create_module.sh --help -n      # Get help for the new-module command
```

The script supports help pages for each sub-command. Example:

```shell
./util.sh --help --build
```

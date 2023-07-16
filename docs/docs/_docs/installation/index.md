---
layout: default
title: Installation
has_children: false
---

# Installation

Currently, there's no way to install it from binary. It has to be built from source. 

## Windows

Instructions coming soon.

## Linux

Install [CMake](https://cmake.org/). Most Linux distributions come with CMake preinstalled.

Once CMake is installed, go to the projects root directory and enter the following command:

```
mkdir build
cmake ..
make
```

The project is built. The executable is located at `src/out` inside the build directory. This is a self-contained program anywhere in your system.

Example:
```
sudo chmod g+x src/out
sudo mv build/src/out  /usr/local/bin/engine
```

The program may not be executed from anywhere in the system.
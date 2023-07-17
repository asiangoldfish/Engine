---
layout: default
title: Core
parent: Modules
grand_parent: Source Code
---

# Core

The `core` module is the foundation of the Game Engine. It's responsible
abstracting low level implementations to APIs that the Engine's modules may
use. It also acts as the middleman between all the modules, even if they may
not know about each other.

## Table of contents
1. TOC
{:toc .text-delta}

## Framework

| Header | Source |
|:-------|:-------|
| `Framework.h` | `Framework.cpp` |

Framework handles low level implementations necessary to start the Engine. It
also cleans up all resources when the game should close. The current list of
responsibilities are as follows:

- User inputs
- File I/O
- Rendering
- Audio

By providing APIs, consumers don't know anything about the Frameworks
implementations. That means we are able to replace, upgrade, fix and remove
components without affecting the rest of system.

## GameObject

| Header | Source |
|:-------|:-------|
| `GameObject.h` | `GameObject.cpp` |

The bare-bones object that any class may implement. It's main objective
is to implement the [Observer pattern](https://en.wikipedia.org/wiki/Observer_pattern). By abstracting the pattern implementation, classes that inherit from GameObject may easily
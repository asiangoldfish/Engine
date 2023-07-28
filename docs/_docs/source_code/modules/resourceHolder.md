---
layout: default
title: Resource Holder
parent: Modules
grand_parent: Source Code
---

1. TOC
{:toc .text-delta}

# Overview

The `ResourceHolder` is a container that manages resources in memory. By
automagically allocating and deallocating memory, user's do not need to worry
about memory leaks and other memory related vulnerabilities.

# Supported Resources
- sf::Texture
- sf::Audio
- sf::Font

# API

**Identifier**

Enum that lists all available resources to use.

**Resource::get(Identifier identifier, Resource resource)**
Get the resource.
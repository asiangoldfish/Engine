/**
 * @file Sprite.h
 * @author Khai Duong
 * @brief Base class for all sprites.
 * @version 0.1
 * @date 2023-07-17
 * 
 * @copyright Copyright Khai Duong (c) 2023
 * 
 */

#ifndef SPRITE_H
#define SPRITE_H

#include "core/BasicShape.h"

/**
 * @brief The base class for renderable physics objects.
 * Sprite is the base object for renderable physics objects.
 */
class Sprite
{
private:
    BasicShape *shape;      // The sprite's renderable geometry

public:
    Sprite();
    virtual ~Sprite();

// Getters and setters
public:
    BasicShape *getShape();
};

#endif
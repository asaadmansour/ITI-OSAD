#ifndef SHAPE_H
#define SHAPE_H

#include <SDL2/SDL.h>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw(SDL_Renderer* renderer) const = 0;
};

#endif
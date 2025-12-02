#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
#include "line.h"
#include <vector>

class Rectangle : public Shape {
private:
    int x_, y_, w_, h_;
    std::vector<line> edges_;
    void rebuildEdges();
public:
    Rectangle(int x, int y, int w, int h);
    void draw(SDL_Renderer* renderer) const override;
    
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

    void setX(int x);
    void setY(int y);
    void setWidth(int w);
    void setHeight(int h);
    void setPosition(int x, int y);
    void setSize(int w, int h);
};

#endif
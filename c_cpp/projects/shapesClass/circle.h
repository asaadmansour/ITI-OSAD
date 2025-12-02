#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
#include <cmath>

class Circle : public Shape {
private:
    int centerX_, centerY_, radius_;
    
public:
    Circle(int centerX, int centerY, int radius);
    void draw(SDL_Renderer* renderer) const override;

    int getCenterX() const;
    int getCenterY() const;
    int getRadius() const;

    void setCenterX(int x);
    void setCenterY(int y);
    void setRadius(int r);
    void setCenter(int x, int y);
};

#endif
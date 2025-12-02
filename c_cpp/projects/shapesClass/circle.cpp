#include "circle.h"

Circle::Circle(int centerX, int centerY, int radius) 
    : centerX_(centerX), centerY_(centerY), radius_(radius) {}

void Circle::draw(SDL_Renderer* renderer) const {
    const int segments = 100;
    const double PI = 3.14159265358979323846;
    
    for (int i = 0; i < segments; i++) {
        double angle1 = (2.0 * PI * i) / segments;
        double angle2 = (2.0 * PI * (i + 1)) / segments;
        
        int x1 = centerX_ + radius_ * cos(angle1);
        int y1 = centerY_ + radius_ * sin(angle1);
        int x2 = centerX_ + radius_ * cos(angle2);
        int y2 = centerY_ + radius_ * sin(angle2);
        
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
}

int Circle::getCenterX() const { return centerX_; }
int Circle::getCenterY() const { return centerY_; }
int Circle::getRadius() const { return radius_; }

void Circle::setCenterX(int x) { centerX_ = x; }
void Circle::setCenterY(int y) { centerY_ = y; }
void Circle::setRadius(int r) { radius_ = r; }
void Circle::setCenter(int x, int y) { centerX_ = x; centerY_ = y; }
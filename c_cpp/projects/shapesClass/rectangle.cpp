#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h) : x_(x), y_(y), w_(w), h_(h) {
    rebuildEdges();
}

void Rectangle::rebuildEdges() {
    edges_.clear();
    edges_.emplace_back(x_, y_, x_ + w_, y_);         // top
    edges_.emplace_back(x_ + w_, y_, x_ + w_, y_ + h_); // right
    edges_.emplace_back(x_ + w_, y_ + h_, x_, y_ + h_); // bottom
    edges_.emplace_back(x_, y_ + h_, x_, y_);         // left
}

int Rectangle::getX() const { return x_; }
int Rectangle::getY() const { return y_; }
int Rectangle::getWidth() const { return w_; }
int Rectangle::getHeight() const { return h_; }

void Rectangle::setX(int x) { x_ = x; rebuildEdges(); }
void Rectangle::setY(int y) { y_ = y; rebuildEdges(); }
void Rectangle::setWidth(int w) { w_ = w; rebuildEdges(); }
void Rectangle::setHeight(int h) { h_ = h; rebuildEdges(); }
void Rectangle::setPosition(int x, int y) { x_ = x; y_ = y; rebuildEdges(); }
void Rectangle::setSize(int w, int h) { w_ = w; h_ = h; rebuildEdges(); }

void Rectangle::draw(SDL_Renderer* renderer) const {
    for (const auto &e : edges_) e.draw(renderer);
}
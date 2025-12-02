#include "square.h"

Square::Square(int x, int y, int s) : x_(x), y_(y), s_(s) {
    rebuildEdges();
}

void Square::rebuildEdges() {
    edges_.clear();
    edges_.emplace_back(x_, y_, x_ + s_, y_);         // top
    edges_.emplace_back(x_ + s_, y_, x_ + s_, y_ + s_); // right
    edges_.emplace_back(x_ + s_, y_ + s_, x_, y_ + s_); // bottom
    edges_.emplace_back(x_, y_ + s_, x_, y_);         // left
}

int Square::getX() const { return x_; }
int Square::getY() const { return y_; }
int Square::getSide() const { return s_; }

void Square::setX(int x) { x_ = x; rebuildEdges(); }
void Square::setY(int y) { y_ = y; rebuildEdges(); }
void Square::setSide(int s) { s_ = s; rebuildEdges(); }
void Square::setPosition(int x, int y) { x_ = x; y_ = y; rebuildEdges(); }
void Square::setSize(int s) { s_ = s; rebuildEdges(); }

void Square::draw(SDL_Renderer* renderer) const {
    for (const auto &e : edges_) e.draw(renderer);
}
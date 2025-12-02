#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
#include "line.h"
#include <vector>
class Square : public Shape {
    private:
        int x_, y_, s_;
        std::vector<line> edges_;
        void rebuildEdges();
    public:    
    Square(int x, int y, int s);
    void draw(SDL_Renderer* renderer) const override;
    
    int getX() const;
    int getY() const;
    int getSide() const;

    void setX(int x);
    void setY(int y);
    void setSide(int s);

    void setPosition(int x, int y);
    void setSize(int s);
};
#endif
#include "line.h"

line::line():start(0,0),end(0,0){}

line::line(int xStartPoint, int yStartPoint, int xEndPoint, int yEndPoint): 
    start(xStartPoint, yStartPoint), end(xEndPoint, yEndPoint){}

void line:: setXStartPoint(int number){
    start.setX(number);
}
void line::setYStartPoint(int number){
    start.setY(number);
}
void line::setXEndPoint(int number){
    end.setX(number);
}
void line::setYEndPoint(int number){
    end.setY(number);
}
int line::getXStartPoint() const {
    return start.getX();
}
int line::getYStartPoint() const {
    return start.getY();
}
int line::getXEndPoint() const {
    return end.getX();
}
int line::getYEndPoint() const {
    return end.getY();
}
void line::draw(SDL_Renderer* renderer) const {
    SDL_RenderDrawLine(renderer, 
                       start.getX(), start.getY(), 
                       end.getX(), end.getY());
}

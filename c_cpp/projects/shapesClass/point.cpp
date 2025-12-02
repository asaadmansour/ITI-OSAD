#include "point.h"

Point::Point(){
    this->startPoint = 0;
    this->endPoint = 0;
};
Point::Point(int startPoint,int endPoint){
    this->startPoint = startPoint;
    this->endPoint = endPoint;
};

void Point::setX(int point) {
    this->startPoint = point;
}
void Point::setY(int point) {
    this->endPoint = point;
}
int Point::getX() const {
    return this->startPoint;
}
int Point::getY() const {
    return this->endPoint;
}
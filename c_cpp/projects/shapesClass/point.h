#ifndef POINT_H
#define POINT_H
class Point {
    private:
        int startPoint,endPoint;
    public:
        Point();
        Point(int startPoint,int endPoint);


        void setX(int point);
        void setY(int point);
        int getX() const;
        int getY() const;
};
#endif
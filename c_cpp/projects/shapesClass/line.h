#ifndef LINE_H
#define LINE_H

#include "point.h"
#include <SDL2/SDL.h>

class line {
    private:
        Point start;
        Point end;
    public:
        line();
        line(int xStartPoint,int xEndPoint,int yStartPoint,int yEndPoint);
        void setXStartPoint(int number);
        void setYStartPoint(int number);
        void setXEndPoint(int number);
        void setYEndPoint(int number);
        int getXStartPoint() const ;
        int getYStartPoint() const ;
        int getXEndPoint() const ;
        int getYEndPoint() const ;
        void draw(SDL_Renderer* renderer) const;
};
#endif
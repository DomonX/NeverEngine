#ifndef MOUSECONTROLLER_HPP_INCLUDED
#define MOUSECONTROLLER_HPP_INCLUDED

#include "../screen/bitmapScaler.hpp"

class MouseController{
    public:
    int x;
    int y;
    int r_x(){
        return x * bitmapScaler::getScaleRev();
    }
    int r_y(){
        return (y - bitmapScaler::getShift()) * bitmapScaler::getScaleRev() ;
    }
};

#endif // MOUSECONTROLLER_HPP_INCLUDED

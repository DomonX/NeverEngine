#ifndef MAPCOLLIDER_HPP_INCLUDED
#define MAPCOLLIDER_HPP_INCLUDED

using namespace std;

class MapCollider{
public:
    int pos_x_begin;
    int pos_x_end;
    int pos_y_begin;
    int pos_y_end;
    MapCollider(int x, int x2, int y, int y2){
        pos_x_begin = x;
        pos_x_end = x2;
        pos_y_begin = y;
        pos_y_end = y2;
    }
    bool checkCollisions(int position_x, int position_y){
        if(position_x > pos_x_begin && position_x < pos_x_end && position_y > pos_y_begin && position_y < pos_y_end ){
            return true;
        }
        return false;
    }
};

#endif // MAPCOLLIDER_HPP_INCLUDED

#ifndef SHADOWS_HPP_INCLUDED
#define SHADOWS_HPP_INCLUDED

#include <allegro5/allegro.h>

class Shadow{
private:
ALLEGRO_BITMAP * sprite;
public:
    int position_x;
    int position_y;
    double intensivity;
    Shadow(ALLEGRO_BITMAP * sprite, int x, int y, double intense){
        this->sprite = sprite;
        position_x = x;
        position_y = y;
        intensivity = intense;
    }
    void draw_alpha(){
        al_draw_bitmap(sprite,position_x,position_y,NULL);
    }
    void draw_sprite(){
        al_draw_tinted_bitmap(sprite,al_map_rgba_f(1,1,1,intensivity),position_x,position_y,NULL);
    }
};

class Light{
private:
    ALLEGRO_BITMAP * sprite;
public:
    int position_x;
    int position_y;
    double intensivity;
    Light(ALLEGRO_BITMAP * sprite, int x, int y, double intense){
        this->sprite = sprite;
        position_x = x - al_get_bitmap_width(sprite)/2;
        position_y = y - al_get_bitmap_height(sprite)/2;
        intensivity = intense;
    }
    void draw_alpha(){
        al_draw_bitmap(sprite,position_x,position_y,NULL);
    }
    void draw_sprite(){
        al_draw_tinted_bitmap(sprite,al_map_rgba_f(1,1,1,intensivity),position_x,position_y,NULL);
    }
};

#endif // SHADOWS_HPP_INCLUDED

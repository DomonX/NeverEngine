#ifndef MAPOBJECT_HPP_INCLUDED
#define MAPOBJECT_HPP_INCLUDED

class MapObject{
    private:
    int position_x;
    int position_y;
    ALLEGRO_BITMAP * imgBack;
    ALLEGRO_BITMAP * imgFront;
    int shift;
    public:
    MapObject(ALLEGRO_BITMAP * src, int x, int y, double perc){
        position_x = x;
        position_y = y;
        imgFront = al_create_sub_bitmap(src,0,0,al_get_bitmap_width(src),al_get_bitmap_height(src)*perc);
        imgBack = al_create_sub_bitmap(src,0,al_get_bitmap_height(src)*perc,al_get_bitmap_width(src),al_get_bitmap_height(src)-al_get_bitmap_height(src)*perc);
        shift = al_get_bitmap_height(src)*perc;
    }
    void draw_sprite(){
        al_draw_bitmap(imgBack,position_x,position_y+shift,NULL);
    }
    void draw_spriteL2(){
        al_draw_bitmap(imgFront,position_x,position_y,NULL);
    }
};

#endif // MAPOBJECT_HPP_INCLUDED

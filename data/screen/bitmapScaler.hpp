#ifndef BITMAPSCALER_HPP_INCLUDED
#define BITMAPSCALER_HPP_INCLUDED

#include <allegro5/allegro.h>

class bitmapScaler{
    public :
    static void draw_scaled_bitmap(ALLEGRO_BITMAP * bitmap, int x, int y, int flags){
        int width = al_get_bitmap_width(bitmap);
        int height = al_get_bitmap_height(bitmap);
        double scale = getScale();
        al_draw_scaled_bitmap(bitmap,0,0,width,height,getScaledX(x),getScaledY(y),width*scale,height*scale,flags);
    }
    static void draw_scaled_alpha_bitmap(ALLEGRO_BITMAP * bitmap, int x, int y, int flags, float alpha){
        int width = al_get_bitmap_width(bitmap);
        int height = al_get_bitmap_height(bitmap);
        double scale = getScale();
        al_draw_tinted_scaled_bitmap(bitmap,al_map_rgba_f(1,1,1,(float)alpha),0,0,width,height,getScaledX(x),getScaledY(y),width*scale,height*scale,flags);
    }
    static double getScale(){
        int width = al_get_display_width(window);
        int screen_width = 1920;
        return (double)width/screen_width;
    }
    static double getScaleRev(){
        int width = al_get_display_width(window);
        int screen_width = 1920;
        return screen_width/(double)width;
    }
    static int getScaledX(int x){
        return x*getScale();
    }
    static int getScaledY(int y){
        return y*getScale()+getShift();
    }
    static int getShift(){
        int height = al_get_display_height(window);
        int screen_height = 1080 * getScale();
        return (height - screen_height)/2;

    }
};

#endif // BITMAPSCALER_HPP_INCLUDED

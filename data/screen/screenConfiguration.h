#ifndef SCREENCONFIGURATION_H_INCLUDED
#define SCREENCONFIGURATION_H_INCLUDED


#include <allegro5/allegro.h>

using namespace std;

ALLEGRO_DISPLAY * window;

class Screen_configuration{
private:
    int width;
    int height;
public:
    Screen_configuration(int width, int height){
        this->width = width;
        this->height= height;
    }
    int get_width(){
        return width;
    }
    int get_height(){
        return height;
    }
    void apply_resolution(ALLEGRO_DISPLAY * target){
        al_resize_display(target,width,height);
    }
    void window_center(ALLEGRO_DISPLAY * target){
        ALLEGRO_MONITOR_INFO minfo;
        al_get_monitor_info(0,&minfo);
        int desktop_width = minfo.x2 - minfo.x1;
        int desktop_height = minfo.y2 - minfo.y1;
        int width = al_get_display_width(target);
        int height = al_get_display_height(target);
        al_set_window_position(target,(desktop_width-width)/2,(desktop_height-height)/2);
    }
    static void toogle_windowed(){
        al_set_display_flag(window, ALLEGRO_FULLSCREEN_WINDOW, !(al_get_display_flags(window) & ALLEGRO_FULLSCREEN_WINDOW));
    }
};

#endif // SCREENCONFIGURATION_H_INCLUDED

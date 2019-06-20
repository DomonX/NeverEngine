#ifndef KEYBOARDMENU_HPP_INCLUDED
#define KEYBOARDMENU_HPP_INCLUDED

#include <allegro5/allegro.h>
#include "menu.hpp"
#include "../keyboard/keyboardController.hpp"

class KeyboardMenu : public Menu{
public:
    KeyboardMenu(int options):Menu(options){

    }
    bool controller(){
        if(keyboard.key_down(ALLEGRO_KEY_DOWN)){
            return goDown();
        }
        if(keyboard.key_down(ALLEGRO_KEY_UP)){
            return goUp();
        }
        if(keyboard.key_down_absolute(ALLEGRO_KEY_ENTER)){
            return action();
        }
        return false;
    }
    bool goUp(){
        if(currentState > 0){
            currentState--;
            return false;
        }
        return false;
    }
    bool goDown(){
        if(currentState < options-1){
            currentState++;
            return false;
        }
        return false;
    }
    virtual bool action(){}

    void printMenuCentered(ALLEGRO_FONT * font, ALLEGRO_DISPLAY * target){
        int textHeight = font->height * options;
        int x = al_get_display_width(target)/2;
        int y = (al_get_display_height(target) - textHeight )/2;
        for(int i = 0; i < options; i++){
            if(i == currentState){
                al_draw_textf(font,al_map_rgb(125,125,0),x,y+font->height*i,ALLEGRO_ALIGN_CENTER,"%s", titles.at(i).c_str());
            }else{
                al_draw_textf(font,al_map_rgb(0,0,255),x,y+font->height*i,ALLEGRO_ALIGN_CENTER,"%s", titles.at(i).c_str());
            }
        }
    }
};

#endif // KEYBOARDMENU_HPP_INCLUDED

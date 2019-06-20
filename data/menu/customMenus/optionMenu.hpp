#ifndef OPTIONMENU_HPP_INCLUDED
#define OPTIONMENU_HPP_INCLUDED


#include <allegro5/allegro.h>
#include <vector>
#include <string>
#include "../../configs.h"


using namespace std;


class OptionMenu : KeyboardMenu{
    public:
    int resolutionPicker;
    OptionMenu():KeyboardMenu(3){
        setTitle("Resolution",0);
        setTitle("Display Mode",1);
        setTitle("Back",2);
        resolutionPicker = 0;
    }
    bool resPickerRight(){
        if(resolutionPicker < config.screen_configurations.size()-1){
            resolutionPicker++;
        }
        return false;
    }
    bool resPickerLeft(){
        if(resolutionPicker > 0){
            resolutionPicker--;
        }
        return false;
    }
    bool controller(){
        if(currentState == 0){
            if(keyboard.key_down(ALLEGRO_KEY_RIGHT)){
                resPickerRight();
                changeResTitle();
            }
            if(keyboard.key_down(ALLEGRO_KEY_LEFT)){
                resPickerLeft();
                changeResTitle();
            }
            if(keyboard.key_down_absolute(ALLEGRO_KEY_ENTER)){
                config.screen_configurations.at(resolutionPicker)->apply_resolution(window);
                config.screen_configurations.at(resolutionPicker)->window_center(window);
            }
        }
        return KeyboardMenu::controller();
    }
    void changeResTitle(){
        string resTitle;
        stringstream ss;
        int width = config.screen_configurations.at(resolutionPicker)->get_width();
        int height = config.screen_configurations.at(resolutionPicker)->get_height();
        resTitle += "Resolution ";
        ss << width;
        ss << "x";
        ss << height;
        resTitle += ss.str();
        setTitle(resTitle,0);
    }
    bool action()override{
        if(currentState == 0){
            return false;
        }
        if(currentState == 1){
            Screen_configuration::toogle_windowed();
            return false;
        }
        if(currentState == 2){
            return true;
        }
        return true;
    }
    void resetState(){
        currentState = 0;
    }
    void printMenuCentered(ALLEGRO_FONT * font, ALLEGRO_DISPLAY * target){
        KeyboardMenu::printMenuCentered(font,target);
    }
};

#endif // OPTIONMENU_HPP_INCLUDED

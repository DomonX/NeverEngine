#ifndef ESCAPEMENU_HPP_INCLUDED
#define ESCAPEMENU_HPP_INCLUDED

//#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "../keyboardMenu.hpp"
#include "../../scenes/sceneConfig.hpp"
#include "optionMenu.hpp"

class EscapeMenu : public KeyboardMenu{
public:
    OptionMenu * nestedMenu;
    bool isNestedMenuActive;

    // Constructor

    EscapeMenu():KeyboardMenu(3){
        setTitle("Return",0);
        setTitle("Options",1);
        setTitle("Exit",2);
        isNestedMenuActive = false;
        nestedMenu = new OptionMenu();
    }

    bool controller(){
        if(!isNestedMenuActive){
            KeyboardMenu::controller();
        }
        if(isNestedMenuActive){
            if(nestedMenu->controller()){
                isNestedMenuActive = false;
                currentState = 0;
            }
        }
        return false;
    }

    bool action()override{
        if(currentState == 0){
            int temp = prevScene;
            prevScene = scene;
            scene = temp;
            return true;
        }
        if(currentState == 1){
            isNestedMenuActive = true;
            nestedMenu->resetState();
            return false;
        }
        if(currentState == 2){
            quitter = false;
            return false;
        }
        return false;
    }

    void printMenuCentered(ALLEGRO_FONT * font, ALLEGRO_DISPLAY * target){
        if(isNestedMenuActive){
            nestedMenu->printMenuCentered(font,target);
        }
        if(!isNestedMenuActive){
            KeyboardMenu::printMenuCentered(font,target);
        }
    }
};

EscapeMenu * escapeMenu = new EscapeMenu();

#endif // ESCAPEMENU_HPP_INCLUDED

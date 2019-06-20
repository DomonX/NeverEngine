#ifndef KEYBOARDCONTROLLER_HPP_INCLUDED
#define KEYBOARDCONTROLLER_HPP_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Keyboard_controller{
public:
    bool keysClicked[226];
    bool keysDown[226];
    ALLEGRO_KEYBOARD_STATE keyboard;

    void start(){
        al_get_keyboard_state(&keyboard);
        clear();
    }

    bool key_clicked(int key){
        if(al_key_down(&keyboard,key)){
            return true;
        }
        return false;
    }

    bool key_down(int key){
        if(keysDown[key]){
            return true;
        }
        if(al_key_down(&keyboard,key) && keysClicked[key] == false){
            keysClicked[key] = true;
            keysDown[key] = true;
            return true;
        }
        return false;
    }

    bool key_down_absolute(int key){
         if(al_key_down(&keyboard,key) && keysClicked[key] == false){
            keysClicked[key] = true;
            keysDown[key] = true;
            return true;
        }
        return false;
    }

    void clear(){
        for(int i = 0; i < 226; i++){
            clear_key(i);
        }
    }

    void clear_key(int key){
        keysDown[key] = false;
        if(!al_key_down(&keyboard,key)){
            keysClicked[key] = false;
        }
    }

};

Keyboard_controller keyboard;

#endif // KEYBOARDCONTROLLER_HPP_INCLUDED

#ifndef CHARACTERCONTOLLER_HPP_INCLUDED
#define CHARACTERCONTOLLER_HPP_INCLUDED

#include <allegro5/allegro.h>
#include "../sprites/animated_sprites/characterSprite.h"
#include "../keyboard/keyboardController.hpp"
#include "../screen/bitmapScaler.hpp"
#include <vector>
#include "../map/colliders/mapCollider.hpp"


using namespace std;

class CharacterController{
public :
    CharacterSprite * sprite;
    vector <CharacterSprite *> addons;
    double position_x;
    double position_y;
    int facing;
    float animationSpeed;
    float animationFrame;
    double move_speed;

    CharacterController(CharacterSprite * sprite, int x, int y, float animationSpeed, double move_speed){
        this->sprite = sprite;
        position_x = (double)x;
        position_y = (double)y;
        facing = 0;
        this->animationSpeed = animationSpeed;
        animationFrame = 0.0;
        this->move_speed = move_speed;
    }
    void giveAddon(CharacterSprite * sprite){
        addons.push_back(sprite);
    }
    void animate(){
        if(animationFrame == 0.0){
            animationFrame = 1.0;
        }
        animationFrame += animationSpeed;
        if(animationFrame >= 4.0){
            animationFrame = 0.0;
        }
    }

    void controller(vector < MapCollider *> colliders){
        if(keyboard.key_clicked(ALLEGRO_KEY_UP)){
            moveUp(colliders);
        }else if(keyboard.key_clicked(ALLEGRO_KEY_DOWN)){
            moveDown(colliders);
        }else if(keyboard.key_clicked(ALLEGRO_KEY_RIGHT)){
            moveRight(colliders);
        }else if(keyboard.key_clicked(ALLEGRO_KEY_LEFT)){
            moveLeft(colliders);
        }else{
            rest();
        }
    }

    bool checkCollistion(vector < MapCollider *> colliders){
        vector < MapCollider *>::iterator i;
        for(i = colliders.begin(); i != colliders.end(); i++){
            if((*i)->checkCollisions(position_x,position_y)){
                return true;
            }
        }
        return false;
    }
    void moveUp(vector < MapCollider *> colliders){
        position_y -= move_speed;
        if(checkCollistion(colliders)){
           position_y += move_speed;
        }
        facing = 2;
        animate();
    }
    void moveDown(vector < MapCollider *> colliders){
        position_y += move_speed;
        if(checkCollistion(colliders)){
           position_y -= move_speed;
        }
        facing = 0;
        animate();
    }
    void moveRight(vector < MapCollider *> colliders){
        position_x += move_speed;
        if(checkCollistion(colliders)){
           position_x -= move_speed;
        }
        facing = 3;
        animate();
    }
    void moveLeft(vector < MapCollider *> colliders){
        position_x -= move_speed;
        if(checkCollistion(colliders)){
           position_x += move_speed;
        }
        facing = 1;
        animate();
    }
    void rest(){
        animationFrame = 0.0;
    }

    void printChar(){
        ALLEGRO_BITMAP * current = sprite->getMovement(facing,animationFrame);
        bitmapScaler::draw_scaled_bitmap(current,(1920-al_get_bitmap_width(sprite->calm_down))/2,(1080-al_get_bitmap_height(sprite->calm_down))/2,0);
        vector<CharacterSprite *>::iterator i;
        for(i = addons.begin(); i != addons.end(); i++){
            ALLEGRO_BITMAP * addon = (*i)->getMovement(facing,animationFrame);
            bitmapScaler::draw_scaled_bitmap(addon,(1920-al_get_bitmap_width(sprite->calm_down))/2,(1080-al_get_bitmap_height(sprite->calm_down))/2,0);
        }
    }
};

#endif // CHARACTERCONTOLLER_HPP_INCLUDED

#ifndef CHARACTERSPRITE_H_INCLUDED
#define CHARACTERSPRITE_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/bitmap.h>

class CharacterSprite{
    public:
    ALLEGRO_BITMAP * calm_right;
    ALLEGRO_BITMAP * calm_up;
    ALLEGRO_BITMAP * calm_left;
    ALLEGRO_BITMAP * calm_down;
    ALLEGRO_BITMAP * moving_up_01;
    ALLEGRO_BITMAP * moving_up_02;
    ALLEGRO_BITMAP * moving_down_01;
    ALLEGRO_BITMAP * moving_down_02;
    ALLEGRO_BITMAP * moving_right_01;
    ALLEGRO_BITMAP * moving_right_02;
    ALLEGRO_BITMAP * moving_left_01;
    ALLEGRO_BITMAP * moving_left_02;
    CharacterSprite(ALLEGRO_BITMAP * source){

        int width = al_get_bitmap_width(source);
        int height = al_get_bitmap_height(source);
        int piece_width = width/3;
        int piece_height = height/4;

        calm_down = getSingleSprite(source,piece_width,piece_height,1,0);
        moving_down_01 = getSingleSprite(source,piece_width,piece_height,0,0);
        moving_down_02 = getSingleSprite(source,piece_width,piece_height,2,0);

        calm_up = getSingleSprite(source,piece_width,piece_height,1,3);
        moving_up_01 = getSingleSprite(source,piece_width,piece_height,0,3);
        moving_up_02 = getSingleSprite(source,piece_width,piece_height,2,3);

        calm_right = getSingleSprite(source,piece_width,piece_height,1,2);
        moving_right_01 = getSingleSprite(source,piece_width,piece_height,0,2);
        moving_right_02 = getSingleSprite(source,piece_width,piece_height,2,2);

        calm_left = getSingleSprite(source,piece_width,piece_height,1,1);
        moving_left_01 = getSingleSprite(source,piece_width,piece_height,0,1);
        moving_left_02 = getSingleSprite(source,piece_width,piece_height,2,1);

    }
    ALLEGRO_BITMAP * getSingleSprite(ALLEGRO_BITMAP * source, int width, int height, int indexW, int indexH){
        return al_create_sub_bitmap(source, indexW*width, indexH*height, width-1, height-1);
    }
    ALLEGRO_BITMAP * getMovement(int facing, double animationFrame){
        if(facing == 0){
            if((int)animationFrame == 0){
                return calm_down;
            }
            if((int)animationFrame == 1){
                return moving_down_01;
            }
            if((int)animationFrame == 2){
                return calm_down;
            }
            if((int)animationFrame == 3){
                return moving_down_02;
            }
        }
        if(facing == 1){
            if((int)animationFrame == 0){
                return calm_left;
            }
            if((int)animationFrame == 1){
                return moving_left_01;
            }
            if((int)animationFrame == 2){
                return calm_left;
            }
            if((int)animationFrame == 3){
                return moving_left_02;
            }
        }
        if(facing == 2){
            if((int)animationFrame == 0){
                return calm_up;
            }
            if((int)animationFrame == 1){
                return moving_up_01;
            }
            if((int)animationFrame == 2){
                return calm_up;
            }
            if((int)animationFrame == 3){
                return moving_up_02;
            }
        }
        if(facing == 3){
            if((int)animationFrame == 0){
                return calm_right;
            }
            if((int)animationFrame == 1){
                return moving_right_01;
            }
            if((int)animationFrame == 2){
                return calm_right;
            }
            if((int)animationFrame == 3){
                return moving_right_02;
            }
        }
    }

};

#endif // CHARACTERSPRITE_H_INCLUDED

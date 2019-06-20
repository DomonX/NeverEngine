#ifndef MAPCHUNK_HPP_INCLUDED
#define MAPCHUNK_HPP_INCLUDED

#include "mapObject.hpp"
#include "../inGameTime/inGameTime.hpp"

class Chunk{
private:
    ALLEGRO_BITMAP * lightView = al_create_bitmap(1920,1080);
    ALLEGRO_BITMAP * chunkView = al_create_bitmap(1920,1080);
    ALLEGRO_BITMAP * chunkViewL2 = al_create_bitmap(1920,1080);
public:
    vector <Light*> lights;
    vector <MapCollider*> colliders;
    vector <MapObject*> objects;
    ALLEGRO_BITMAP * shadow;
    ALLEGRO_BITMAP * background;

    void print_chunkView(int x, int y, InGameTime * mapTimer){
        bitmapScaler::draw_scaled_bitmap(chunkView,x,y,NULL);
    }
    void print_chunkViewL2(int x, int y, InGameTime * mapTimer){
        bitmapScaler::draw_scaled_bitmap(chunkViewL2,x,y,NULL);
    }
    void print_chunkLight(int x, int y, InGameTime * mapTimer){
        bitmapScaler::draw_scaled_alpha_bitmap(lightView,x,y,NULL,mapTimer->getDarkness(1));
    }

    void load_chunk(){
        load_lightView();
        load_chunkView();
        load_chunkViewL2();
    }

    void load_chunkView(){
        vector<Light*>::iterator i;
        vector<MapObject*>::iterator j;
        al_set_target_bitmap(chunkView);
        al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
        al_draw_bitmap(background,0,0,NULL);
        for(j = objects.begin(); j != objects.end(); j++){
           (*j)->draw_sprite();
        }

        for(i = lights.begin(); i != lights.end(); i++){
           (*i)->draw_sprite();
        }
        al_set_target_backbuffer(window);
    }

    void load_chunkViewL2(){
        vector<MapObject*>::iterator i;
        al_set_target_bitmap(chunkViewL2);
        al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
        for(i = objects.begin(); i != objects.end(); i++){
           (*i)->draw_spriteL2();
        }
        al_set_target_backbuffer(window);
    }

    void load_lightView(){
        vector<Light*>::iterator i;
        al_set_target_bitmap(lightView);
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_bitmap(shadow,0,0,NULL);
        al_set_blender(ALLEGRO_DEST_MINUS_SRC, ALLEGRO_ONE, ALLEGRO_ONE);
        for(i = lights.begin(); i != lights.end(); i++){
            (*i)->draw_alpha();
        }
        al_set_target_backbuffer(window);
    }
};

#endif // MAPCHUNK_HPP_INCLUDED

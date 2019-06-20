#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <vector>
#include "allegro5/allegro.h"
#include "../screen/shadows/shadows.hpp"
#include "colliders/mapCollider.hpp"
#include "mapChunk.hpp"
#include "../characters/characterContoller.hpp"

using namespace std;


class Map{
private:
    ALLEGRO_BITMAP * lightView = al_create_bitmap(1920,1080);
    ALLEGRO_BITMAP * mapView = al_create_bitmap(1920,1080);
public:
    vector < vector<Chunk*> > chunks;
    CharacterController * character;
    InGameTime * mapTimer;

    vector < MapCollider * > get_colliders(){
        int chunk_x = character->position_x / 1920;
        int chunk_y = character->position_y / 1080;
        return chunks.at(chunk_x).at(chunk_y)->colliders;
    }

    void print_map(){
        int chunk_x = character->position_x / 1920;
        int shift_x = (int)character->position_x % 1920 - 1920/2;
        int chunk_y = character->position_y / 1080;
        int shift_y = (int)character->position_y % 1080 - 1080/2;

        try{
            chunks.at(chunk_x).at(chunk_y)->print_chunkView(-shift_x,-shift_y,mapTimer);
        }catch(exception e){

        }
        if(shift_x > 0){
            try{
                chunks.at(chunk_x+1).at(chunk_y)->print_chunkView(1920-shift_x,-shift_y,mapTimer);
            }catch(exception e){

            }
        }
        if(shift_y > 0){
            try{
                chunks.at(chunk_x).at(chunk_y+1)->print_chunkView(-shift_x,1080-shift_y,mapTimer);
            }catch(exception e){

            }
        }
        if(shift_y > 0 && shift_x > 0){
            try{
                chunks.at(chunk_x+1).at(chunk_y+1)->print_chunkView(1920-shift_x,1080-shift_y,mapTimer);
            }catch(exception e){

            }
        }

        character->printChar();

        try{
            chunks.at(chunk_x).at(chunk_y)->print_chunkViewL2(-shift_x,-shift_y,mapTimer);
        }catch(exception e){

        }
        if(shift_x > 0){
            try{
                chunks.at(chunk_x+1).at(chunk_y)->print_chunkViewL2(1920-shift_x,-shift_y,mapTimer);
            }catch(exception e){

            }
        }
        if(shift_y > 0){
            try{
                chunks.at(chunk_x).at(chunk_y+1)->print_chunkViewL2(-shift_x,1080-shift_y,mapTimer);
            }catch(exception e){

            }
        }
        if(shift_y > 0 && shift_x > 0){
            try{
                chunks.at(chunk_x+1).at(chunk_y+1)->print_chunkViewL2(1920-shift_x,1080-shift_y,mapTimer);
            }catch(exception e){

            }
        }

        try{
            chunks.at(chunk_x).at(chunk_y)->print_chunkLight(-shift_x,-shift_y,mapTimer);
        }catch(exception e){

        }
        if(shift_x > 0){
            try{
                chunks.at(chunk_x+1).at(chunk_y)->print_chunkLight(1920-shift_x,-shift_y,mapTimer);
            }catch(exception e){

            }
        }
        if(shift_y > 0){
            try{
                chunks.at(chunk_x).at(chunk_y+1)->print_chunkLight(-shift_x,1080-shift_y,mapTimer);
            }catch(exception e){

            }
        }
        if(shift_y > 0 && shift_x > 0){
            try{
                chunks.at(chunk_x+1).at(chunk_y+1)->print_chunkLight(1920-shift_x,1080-shift_y,mapTimer);
            }catch(exception e){

            }
        }
    }

    void add_chunk(Chunk * newChunk, int x, int y){
        if(chunks.size() <= x){
            chunks.resize(x+1);
        }
        if(chunks.at(x).size() <= y){
            chunks.at(x).resize(y+1);
        }
        chunks.at(x).at(y) = newChunk;
    }

    void run_controller(){
        character->controller(get_colliders());
    }
};

#endif // MAP_HPP_INCLUDED

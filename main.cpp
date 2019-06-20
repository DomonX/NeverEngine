
#include <iostream>
#include <vector>
#include <sstream>

#include "NeverEngine.hpp"

using namespace std;

int main()
{
    float frames_per_second = 6000.0;

    config.addResolution(1920,1080); // 16:9
    config.addResolution(1680,1050);
    config.addResolution(1600,900); // 16:9
    config.addResolution(1536,864); // 16:9
    config.addResolution(1440,900);
    config.addResolution(1366,768); // 16:9
    config.addResolution(1360,768);
    config.addResolution(1280,1024);
    config.addResolution(1280,800);
    config.addResolution(1280,720); // 16:9
    config.addResolution(1024,768);
    config.addResolution(800,600);
    config.addResolution(640,360);

    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_image_addon();
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    window = al_create_display(640,360);
    al_set_window_title(window,"Projekt");

    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    ALLEGRO_FONT * font = al_load_font("font1.ttf", 60, NULL);

    ALLEGRO_BITMAP * tile = al_load_bitmap("tile.png");
    ALLEGRO_BITMAP * temp = al_load_bitmap("char.png");
    ALLEGRO_BITMAP * addon = al_load_bitmap("addon.png");
    ALLEGRO_BITMAP * addon2 = al_load_bitmap("addon2.png");
    ALLEGRO_BITMAP * bg = al_load_bitmap("backtest.png");
    ALLEGRO_BITMAP * shadow = al_load_bitmap("darkness.png");
    ALLEGRO_BITMAP * shadowWork = al_clone_bitmap(shadow);
    ALLEGRO_BITMAP * light = al_load_bitmap("light.png");
    ALLEGRO_BITMAP * light2 = al_load_bitmap("light2.png");
    ALLEGRO_BITMAP * shadow2 = al_load_bitmap("shadow.png");
    ALLEGRO_BITMAP * lamp = al_load_bitmap("lamp.png");
    CharacterSprite * test = new CharacterSprite(temp);
    CharacterSprite * addonSprite = new CharacterSprite(addon);
    CharacterSprite * addonSprite2 = new CharacterSprite(addon2);
    CharacterController * character = new CharacterController(test,500,500,0.12,6);
    character->giveAddon(addonSprite);
    character->giveAddon(addonSprite2);

    InGameTime * dayTimer = new InGameTime(60*24);

    bool frameTick = false;
    MouseController mouse;

    Map * mainmap = new Map();
    mainmap->character = character;
    mainmap->mapTimer = dayTimer;

    Chunk * chunk1 = new Chunk();
    MapObject * mapLamp = new MapObject(lamp,60,60,0.92);
    MapCollider * collider = new MapCollider(60,60+40,165,180+34);
    chunk1->objects.push_back(mapLamp);
    chunk1->lights.push_back(new Light(light,80,65,1.0));
    chunk1->background = bg;
    chunk1->shadow = shadow;
    chunk1->load_chunk();
    chunk1->colliders.push_back(collider);

    Chunk * chunk2 = new Chunk();
    chunk2->background = bg;
    chunk2->shadow = shadow;
    chunk2->load_chunk();

    Chunk * chunk3 = new Chunk();
    chunk3->background = bg;
    chunk3->shadow = shadow;
    chunk3->load_chunk();

    Chunk * chunk4 = new Chunk();
    chunk4->background = bg;
    chunk4->shadow = shadow;
    chunk4->load_chunk();

    mainmap->add_chunk(chunk1,0,0);
    mainmap->add_chunk(chunk2,1,0);
    mainmap->add_chunk(chunk3,0,1);
    mainmap->add_chunk(chunk4,1,1);

    int frames = 0 ;

    ALLEGRO_TIMER * timer = al_create_timer(1.0/frames_per_second);
    ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_start_timer(timer);

    while(quitter){
        frames++;
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        keyboard.start();
        if(events.type == ALLEGRO_EVENT_TIMER){
            frameTick = true;
        }else{
            frameTick = false;
        }
        if(events.type == ALLEGRO_EVENT_MOUSE_AXES){
            mouse.x = events.mouse.x;
            mouse.y = events.mouse.y;
        }
        if(scene == 0){
            if(frameTick){
                mainmap->run_controller();
                dayTimer->flyTime();
            }
            mainmap->print_map();
            al_draw_textf(font,al_map_rgb(255,255,255),0,0,NULL,"%d", frames);
            al_draw_textf(font,al_map_rgb(255,255,255),0,60,NULL,"%d : %d", mainmap->mapTimer->getHours(), mainmap->mapTimer->getMinutes());
            al_flip_display();
            al_clear_to_color(al_map_rgb(0,0,0));
            if(keyboard.key_down(ALLEGRO_KEY_ESCAPE)){
                prevScene = scene;
                scene = 1;
            }
        }

        if(scene == 1){
            escapeMenu->printMenuCentered(font,window);
            al_flip_display();
            al_clear_to_color(al_map_rgb(255,255,255));
            escapeMenu->controller();
        }
    }

    al_destroy_display(window);
    return 0;
}

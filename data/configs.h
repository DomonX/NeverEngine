#ifndef CONFIGS_H_INCLUDED
#define CONFIGS_H_INCLUDED

#include <vector>
#include "screen/screenConfiguration.h"

class Config{
public:
    vector <Screen_configuration *> screen_configurations;
    void addResolution(int x, int y){
        screen_configurations.push_back(new Screen_configuration(x,y));
    }
};

Config config;

#endif // CONFIGS_H_INCLUDED

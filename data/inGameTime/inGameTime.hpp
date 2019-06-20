#ifndef INGAMETIME_HPP_INCLUDED
#define INGAMETIME_HPP_INCLUDED

#include <cmath>

class InGameTime{
public:
    double dayTime;
    double currentTime;

    InGameTime(double dayLenght){
        currentTime = dayLenght/2.0 ;
        dayTime = dayLenght;
    }

    void flyTime(){
        if(currentTime > dayTime){
            currentTime = 0.0;
        }else{
            currentTime++;
        }
    }

    double getDarkness(double scale){
        return getDarkness()*scale;
    }

    double getDarkness(){
        double darkness = pow((abs((currentTime-0.1*dayTime)-(dayTime/2.0))),0.8)/(pow(dayTime/2.0,0.8)) + 0.20;
        if(darkness > 1.0){
            darkness = 1.0;
        }
        return darkness;
    }

    int getTime(){
        double parter = dayTime / (24.0*60.0);
        return currentTime / parter;
    }
    int getMinutes(){
        return getTime()%60;
    }
    int getHours(){
        return getTime()/60;
    }
};

#endif // INGAMETIME_HPP_INCLUDED

#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include <vector>

using namespace std;

class Menu{
protected:
    int options;
    int currentState;
    vector <string> titles;
public:
    Menu(int options){
        this->options = options;
        titles.resize(options);
        currentState = 0;
    }
    void setTitle(string title, int position){
        if(position > options || position < 0){
            return;
        }
        titles.at(position) = title;
    }

};

#endif // MENU_HPP_INCLUDED

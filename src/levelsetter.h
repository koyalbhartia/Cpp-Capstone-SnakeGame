
#ifndef LEVELSETTER_H
#define LEVELSETTER_H

#include "SDL.h"
#include <string>
#include <vector>

#include <iostream>

class Levelsetter
{
public:
    Levelsetter();
    ~Levelsetter();
    void setLevel(int level);
    void setGrid(int width);
    void setGrid(int width, int height);
    int getGrid_width();
    int getGrid_height();
    int getLevel(); 
    void user_level();  
    void user_grid(); 
    int clip_grid(int size);


private:
    int level_; 
    int gridwidth_;
    int gridheight_;
};

#endif
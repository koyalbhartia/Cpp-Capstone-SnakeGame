
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
    // void setBoardColour(std::vector<int> Board_C);
    // std::vector<int> getSnakeColour();
    // std::vector<int> getBoardColour();
    // void setLevel(int level); //ll
    int getGrid_width();
    int getGrid_height();
    // int getGrid();
    int getLevel(); //ll
    void user_level();  //ll
    void user_grid(); // ll 
    // int calibrate(float f);
    int clip_grid(int size);
    // void setSnakeColour(int red,int green,int blue);


private:
    // std::vector<int> SnakeColour_;
    // std::vector<int> BoardColour_;
    int level_; //ll
    int gridwidth_;
    int gridheight_;


};

#endif
#include "levelsetter.h"
#include <iostream>
#include "SDL.h"

Levelsetter::Levelsetter(): level_{0}{
    // std::cout<<"Level Setter Constructor"<<std::endl;
    // Levelsetter::user_level();
    // Levelsetter::user_grid();
}

Levelsetter::~Levelsetter(){
    // std::cout<<"Level Setter Destructor"<<std::endl;
}

int Levelsetter::getLevel(){ 
    return Levelsetter::level_;
}

void Levelsetter::setLevel(int level){
    Levelsetter::level_ =level; 
}

int Levelsetter::getGrid_width(){ 
    return Levelsetter::gridwidth_;
}

int Levelsetter::getGrid_height(){
    return Levelsetter::gridheight_;
}

void Levelsetter::setGrid(int width){
    Levelsetter::gridwidth_ =width; 
    Levelsetter::gridheight_ =width; 
}

void Levelsetter::setGrid(int width, int height){
    Levelsetter::gridwidth_ =width; 
    Levelsetter::gridheight_ =height;
}

int Levelsetter::clip_grid(int size){ 
    if (size>64) return 64;
    else if (size<16) return 16;
    else return size;
}


void Levelsetter::user_level(){ 
    int input_level;
    std::cout << "Select a level of game between 1 to 5..!!" << std::endl;
    std::cout << "Note: 1 (min); 5 (max)" << std::endl;

    bool flag=true;
    while (flag)
  {
    std::cin >> input_level; 
    if (input_level)
    {
      if (input_level >= 1 && input_level <= 5)
      {
        setLevel(input_level);
        bool flag=false;
        break;
      }
    }
    std::cout << "Please enter a valid number between 1 and 5" << std::endl;
  }
}

void Levelsetter::user_grid(){ 
    int input_grid;
    std::cout << "Select a grid size..!!" << std::endl;
    std::cout << "Note: Increasing grid size increases complexity" << std::endl;
    std::cout << "Option 1: Square grid" << std::endl;
    std::cout << "Option 2: Rectangular grid" << std::endl;
    std::cout << "With any other option number default grid will taken" <<std::endl;
    std::cin>>input_grid;

    if (input_grid){
        switch(input_grid) {
            case 1:
            {
                int grid_w=0;
                std::cout << "Enter width of square grid" << std::endl;
                std::cout << "Enter a number between 16 and 64" <<std::endl;
                std::cout << "Any other width will be clipped to this value" <<std::endl;
                std::cin >> grid_w;
                int width=clip_grid(grid_w);
                setGrid(width);
                break;
            }
            case 2:
            {
                int grid_w=0;
                int grid_h=0;
                std::cout << "Enter width of rectangular grid grid" << std::endl;
                std::cout << "Enter a number between 16 and 64" <<std::endl;
                std::cout << "Any other width will be clipped to this value" <<std::endl;
                std::cin>> grid_w;
                std::cout << "Enter height of rectangular grid grid" << std::endl;
                std::cout << "Enter a number between 16 and 64" <<std::endl;
                std::cout << "Any other width will be clipped to this value" <<std::endl;
                std::cin>> grid_h;
                int width=clip_grid(grid_w);
                int height=clip_grid(grid_h);
                setGrid(width,height);
                break;
            }
            default :
            {
                std::cout << "Default Grid Taken" << std::endl;
                int width=32;
                setGrid(width);
                break;
            }
            
        }
    }
}
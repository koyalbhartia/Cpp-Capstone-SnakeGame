#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "SDL.h"

int main(){
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);

  Controller controller;
  Game game(renderer.grid_width, renderer.grid_height);
  game.levelset();
  auto start=SDL_GetTicks();
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "You Score : " << game.GetScore() << "\n";
  std::cout << "and Size : " << game.GetSize() << "\n";
  auto end=SDL_GetTicks();
  auto time = end-start;

  std::cout << "Final result saved\n";
  std::ofstream result;
  result.open ("../final.txt");
  result << "Score : "<< game.GetScore() <<"\n";
  result << "Size : "<< game.GetSize()<< " \n";
  result << "Time played : "<<time;
  result.close();

  

  return 0;
}
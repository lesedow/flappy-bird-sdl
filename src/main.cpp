#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../include/GameWindow.hpp"

int main (int argc, char *argv[]) {
  const int wWidth = 640;
  const int wHeight = 480;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL_Init failed: " << SDL_GetError() << std::endl;
  }
  if (!IMG_Init(IMG_INIT_PNG)) {
    std::cout << "IMG_Init failed: " << SDL_GetError() << std::endl;
  }

  GameWindow window(wWidth, wHeight, "Flappy Bird SDL");
  SDL_Texture* grass = window.loadTexture("res/fat_fucking_bird.png");

  bool running = true;
  
  while(running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
        break;
      }
    }
    window.clearRenderer();
    window.render(grass);
    window.refreshRenderer();
  }

  window.destroy();
  SDL_Quit();
  IMG_Quit();

  return 0;
}


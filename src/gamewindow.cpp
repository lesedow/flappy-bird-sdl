#include "../include/GameWindow.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

GameWindow::GameWindow(int width, int height, const char* title) 
  :window(NULL), renderer(NULL)
{
  window = SDL_CreateWindow(
    title,
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    width, height,
    SDL_WINDOW_SHOWN
  );
  if (window == NULL) {
    std::cout << "Could not initialise the game window: " << SDL_GetError() << std::endl;
  } else {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
      std::cout << "Could not initialise the renderer: " << SDL_GetError() << std::endl;
    }
  }
}

SDL_Texture* GameWindow::loadTexture(const char* path) {
  SDL_Texture* texture = NULL;
  SDL_Surface* surface = IMG_Load(path);
  if (surface == NULL) {
    std::cout << "Could not load the texture: " << SDL_GetError() << std::endl;
  } else {
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) {
      std::cout << "Could not create texture from surface: " << SDL_GetError() << std::endl;
    }
    SDL_FreeSurface(surface);
  }
  return texture;
} 

void GameWindow::render(SDL_Texture* texture) {
  SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void GameWindow::clearRenderer() {
  SDL_RenderClear(renderer);
}

void GameWindow::refreshRenderer() {
  SDL_RenderPresent(renderer);
}

void GameWindow::destroy() {
  SDL_DestroyWindow(window);
}

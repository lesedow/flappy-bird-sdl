#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class GameWindow {
public:
  GameWindow(int width, int height, const char* title);
  SDL_Texture* loadTexture(const char* path);
  void render(SDL_Texture* texture);
  void refreshRenderer();
  void clearRenderer();
  void destroy();
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};

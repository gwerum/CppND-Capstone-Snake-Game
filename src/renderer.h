#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "constants.h"
#include "objects.h"

class Renderer {
 public:
  Renderer();
  ~Renderer();

  void Render(const Snake &snake, const GameCell &food);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  SDL_Rect block; // block variable for rendering any kind of object (food, snake body, snake head)
};

#endif
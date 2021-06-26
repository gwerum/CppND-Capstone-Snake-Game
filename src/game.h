#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "objects.h"

class Game {
 public:
  Game();
  void Run(Controller const &controller, Renderer &renderer);
  int GetScore() const { return score; };
  int GetSize() const { return snake.size(); };

 private:
  Snake snake;
  GameCell food;
  int score{0};
  // Variables required for random engines
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  void PlaceFood();
  void Update();
};

#endif
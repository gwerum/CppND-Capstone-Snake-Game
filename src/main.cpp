#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  Renderer renderer;
  Controller controller;
  Game game;
  game.Run(controller, renderer);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}
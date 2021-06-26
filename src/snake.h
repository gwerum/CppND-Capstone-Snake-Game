#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"
#include "constants.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake()
  : _head_x(constants::kGridWidth / 2),
    _head_y(constants::kGridHeight / 2) {}

  void Update();
  bool SnakeCell(const SDL_Point &point);
  bool eats(const SDL_Point &food) const;
  
  // Moving 'one-liner' methods to header file to give compiler more information
  // to work with when optimizing the code
  void GrowBody(){ _growing = true; };
  void IncreaseSpeed(float speedIncrement) {_speed += speedIncrement;};
  bool isAlive() const{ return _alive; };
  int size() const {return _size;};

  Direction direction = Direction::kUp;

  float _head_x;
  float _head_y;
  std::vector<SDL_Point> _body;

 private:
  // Private methods
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  // Private member variables
  float _speed{0.1f};
  int _size{1};
  bool _alive{true};
  bool _growing{false};
};

#endif
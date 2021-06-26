#include "snake.h"
#include <cmath>
#include <iostream>
#include <algorithm>

void Snake::Update() {
  SDL_Point prev_cell{
      static_cast<int>(_head_x),
      static_cast<int>(_head_y)
      };  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(_head_x),
      static_cast<int>(_head_y)
      };  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell);
  }
}


bool Snake::eats(const SDL_Point &food) const {
  return (food.x == static_cast<int>(_head_x) && food.y == static_cast<int>(_head_y));
}

void Snake::UpdateHead() {
  switch (direction) {
    case Direction::kUp:
      _head_y -= _speed;
      break;

    case Direction::kDown:
      _head_y += _speed;
      break;

    case Direction::kLeft:
      _head_x -= _speed;
      break;

    case Direction::kRight:
      _head_x += _speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  _head_x = fmod(_head_x + constants::kGridWidth, constants::kGridWidth);
  _head_y = fmod(_head_y + constants::kGridHeight, constants::kGridHeight);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
  // Add previous head location to vector
  _body.push_back(prev_head_cell);

  if (!_growing) {
    // Remove the tail from the vector.
    _body.erase(_body.begin());
  } else {
    _growing = false;
    _size++;
  }

  // Check if the snake has died.
  for (auto const &item : _body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      _alive = false;
    }
  }
}

// Improved method to check if cell is occupied by snake.
bool Snake::SnakeCell(const SDL_Point &point) {
  if (point.x == static_cast<int>(_head_x) && point.y == static_cast<int>(_head_y)) {
    return true;
  }
  auto foundElement = std::find_if(_body.begin(), _body.end(), 
    [&point](auto const &item) {return (point.x == item.x && point.y == item.y);} );
  if (foundElement != _body.end())
    return true;

  return false;
}
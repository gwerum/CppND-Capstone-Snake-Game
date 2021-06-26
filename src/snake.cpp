#include "snake.h"
#include <cmath>
#include <iostream>
#include <algorithm>

Snake::Snake()
: _head_x(constants::kGridWidth / 2),
  _head_y(constants::kGridHeight / 2),
  _head(_head_x, _head_y)
{
}

void Snake::Update() {
  // Update head
  GameCell prev_head = _head; // capture current head cell before updating
  UpdateHead();
  // Update all of the body vector items if the snake head 
  // has moved to a new cell.
  if (_head != prev_head)
    UpdateBody(std::move(prev_head));
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
  // Update head cell from updated head positions
  _head.update(_head_x, _head_y);
}

void Snake::UpdateBody(const GameCell &&prev_head_cell) {
  // Add previous head location to vector
  _body.emplace_back(prev_head_cell);

  if (!_growing) {
    // Remove the tail from the vector.
    _body.erase(_body.begin());
  } else {
    _growing = false;
    _size++;
  }

  // Check if the snake has died.
  if ((std::find(_body.begin(), _body.end(), _head)) != _body.end())
    _alive = false;
}

// Improved method to check if cell is occupied by snake.
bool Snake::SnakeCell(const GameCell &point) {
  // Check if point is occupied by head
  if (_head == point)
    return true;
  // Check if point is occupied by body
  if ((std::find(_body.begin(), _body.end(), point)) != _body.end())
    return true;

  return false;
}
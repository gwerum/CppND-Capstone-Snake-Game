#include "objects.h"

GameCell::GameCell(int x_, int y_) {
  x = x_;
  y = y_;
}

GameCell::GameCell(float x_, float y_) {
  x = static_cast<int>(x_);
  y = static_cast<int>(y_);
}

GameCell::GameCell(const GameCell &rhs) {
  x = rhs.x;
  y = rhs.y;
}

GameCell::GameCell(GameCell &&rhs) {
  x = rhs.x;
  y = rhs.y;
}

GameCell& GameCell::operator=(const GameCell &rhs) {
  if (this == &rhs)
    return *this;
  x = rhs.x;
  y = rhs.y;
  return *this;
}

GameCell& GameCell::operator=(GameCell &&rhs) {
  if (this == &rhs)
    return *this;
  x = rhs.x;
  y = rhs.y;
  return *this;
}

bool operator==(const GameCell &lhs, const GameCell &rhs) {
  return ((lhs.x == rhs.x ) && (lhs.y == rhs.y));
}

bool operator!=(const GameCell &lhs, const GameCell &rhs) {
  return ((lhs.x != rhs.x ) || (lhs.y != rhs.y));
}

void GameCell::update(int x_, int y_) {
  x = x_;
  y = y_;
}

void GameCell::update(float x_, float y_) {
  x = static_cast<int>(x_);
  y = static_cast<int>(y_);
}
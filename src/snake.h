#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"
#include "constants.h"
#include "objects.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake();
  ~Snake() {};

  void Update();
  bool SnakeCell(const GameCell &point);
  
  // Moving 'one-liner' methods to header file to give compiler more information
  // to work with when optimizing the code
  inline bool eats(const GameCell &food) const { return _head == food; };
  inline void GrowBody(){ _growing = true; };
  inline void IncreaseSpeed(float speedIncrement) {_speed += speedIncrement;};
  inline bool isAlive() const{ return _alive; };
  inline int size() const {return _size;};
  inline const std::vector<GameCell>& body() const { return _body;}
  inline const GameCell& head() const { return _head; }

  Direction direction = Direction::kUp;

 private:
  // Private methods
  void UpdateHead();
  void UpdateBody(const GameCell &&prev_cell);

  // Private member variables
  float _head_x;
  float _head_y;
  std::vector<GameCell> _body;
  GameCell _head;

  float _speed{0.1f};
  int _size{1};
  bool _alive{true};
  bool _growing{false};
};

#endif
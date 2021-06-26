#include "game.h"
#include "constants.h"
#include <iostream>
#include "SDL.h"

Game::Game()
: engine(dev()),
  random_w(0, static_cast<int>(constants::kGridWidth - 1)),
  random_h(0, static_cast<int>(constants::kGridHeight - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();
    
    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food);

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_end = SDL_GetTicks();
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < constants::kMsPerFrame) {
      SDL_Delay(constants::kMsPerFrame - frame_duration);
    }

  }
}

void Game::PlaceFood() {
  GameCell new_food;
  while (true) {
    new_food.x = random_w(engine);
    new_food.y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(new_food)) {
      food = std::move(new_food);
      return;
    }
  }
}

void Game::Update() {
  // Make no updates if snake is dead
  if (!snake.isAlive()) return;
  
  auto start_clock = std::chrono::steady_clock::now();
  // Make default snake update
  snake.Update();
  // Make additional updates if snake eats food
  if (snake.eats(food)) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.IncreaseSpeed(0.02);

    // Compute execution time and print to console
    auto end_clock = std::chrono::steady_clock::now();
    auto diff_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_clock - start_clock);
    std::cout << "Exec time: " << diff_ns.count() << " ns" << std::endl;
  }
}
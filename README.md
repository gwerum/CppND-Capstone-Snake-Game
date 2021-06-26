# CPPND: Capstone Project Snake Game

This repository contains a "retro-style" implementation in C++ of the famous Snake game. This project is the capstone project of the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213) and the starter code was provided by Udacity and is inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.
## Motivation

Instead of starting a completely new project, I decided to build up on the starter code provided. My overall goal of this project was to apply as much of the techniques learned throughout the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213) in order to improve the overall code quality. 

In particular, I wanted to achieve the following goals (listed by category):

* Loops, Functions, I/O
  * Optimization of loop structures by using loop and search methods with a maximum computation cost of order O(log(n)), e.g. std::find
  * Application of strict const correctness to make clear what a method is allowed to do.
* Object Oriented Programming
  * Strict encapsulation of class member data by introducting clearly defined public and private interfaces for each class.
* Memory management
  * Introduction of a new class GameCell, which is responsible for the memory management of the game data (the data which is updated & rendered in every cycle like the snake body, snake head and the food).
  * The GameCell class implements move constructors and move assignment operators to enable the use of move semantics.
  * Furthermore it implements comparison operators for the game data to improve overall code readability and enable use std::find without implementation a lambda function.
  * Strict use of lvalue references (and rvalue references where it applies) for reducing overall copy overhead. This can be achieved by on the one side strictly defining own function with intent to enable use of rvalue referenes and on the other side by using existing method of the standard library, which are making use of rvalues, e.g. emplace_back() of the std::vector.
  * Introduction of constants and removal of variables, which are not changed over the course of the game (like screen size, width, etc.), to save stack memory and computation time.
* Concurrency
  * It has been decided to not use any concurrency and thread programming techniques. The current design has a strict sequential program sequence with:
    * Step 1: Receive control input
    * Step 2: Update game
    * Step 3: Render display output
  * This overall sequential execution needs to be kept. Also, within the game update method it didn't make sense to introduce parallization with the current "simple" game setup, which is why it has been decided to not use any parallization techniques.

## Game Display

The following GIF shows the main game display, which is used throughout the game. It will start up after using the basic build instructions further below.

<img src="snake_game.gif"/>

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

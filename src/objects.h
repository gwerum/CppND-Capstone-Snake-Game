#ifndef OBJECTS_H
#define OBJECTS_H

#include "SDL.h"

class GameCell : public SDL_Point
{
private:
    // No private data
public:
    // Declare constructors
    GameCell(){};
    ~GameCell(){};
    GameCell(int x_, int y_);
    GameCell(float x_, float y_);
    GameCell(const GameCell &rhs);
    GameCell(GameCell &&rhs);

    // Declare assignment operators
    GameCell& operator=(const GameCell &rhs);
    GameCell& operator=(GameCell &&rhs);

    // Declare comparison operators
    friend bool operator== (const GameCell &lhs, const GameCell &rhs);
    friend bool operator!= (const GameCell &lhs, const GameCell &rhs);

    // Declare setter function to update game cell positions
    void update(int x_, int y_);
    void update(float x_, float y_);
};

#endif
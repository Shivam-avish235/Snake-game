#ifndef FOOD_H
#define FOOD_H

#include <SDL3/SDL.h>

class Food {
public:
    Food(int blockSize, int maxX, int maxY);
    void spawn();
    void render(SDL_Renderer* renderer);
    int getX() const;
    int getY() const;

private:
    int x, y;
    int blockSize;
    int maxX, maxY;
};

#endif

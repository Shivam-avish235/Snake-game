#ifndef SNAKE_H
#define SNAKE_H

#include <SDL3/SDL.h>
#include <vector>

struct SnakeSegment {
    int x, y;
};

class Snake {
public:
    Snake(int blockSize);
    void update();
    void render(SDL_Renderer* renderer);
    void changeDirection(SDL_Keycode key);
    void grow();
    const std::vector<SnakeSegment>& getSegments() const;

private:
    std::vector<SnakeSegment> segments;
    int dirX, dirY;
    int blockSize;
};

#endif

#ifndef GAME_H
#define GAME_H

#include "wall.h"
#include "snake.h"
#include <SDL3/SDL.h>

class Game {
public:
    Game(int width, int height);
    ~Game();

    bool init(const char* title);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool isRunning() const;

private:
    bool running;
    int windowWidth, windowHeight;
    int blockSize;

    SDL_Window* window;
    SDL_Renderer* renderer;

    Snake snake;
    Wall wall;
};

#endif

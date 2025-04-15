#ifndef GAME_H
#define GAME_H

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
    SDL_Window* window;
    SDL_Renderer* renderer;
    int windowWidth, windowHeight;
};

#endif

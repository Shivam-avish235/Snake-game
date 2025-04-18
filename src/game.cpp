#include "game.h"
#include <SDL3/SDL.h>

#include <iostream>

Game::Game(int width, int height)
    : windowWidth(width), windowHeight(height), running(false),
      window(nullptr), renderer(nullptr), blockSize(20),
      snake(blockSize), wall(blockSize, width, height) {}

Game::~Game() {}

bool Game::init(const char* title) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL Init Failed: " << SDL_GetError() << "\n";
        return false;
    }

    window = SDL_CreateWindow(title, windowWidth, windowHeight, SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << "\n";
        return false;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << "\n";
        return false;
    }

    running = true;
    return true;
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                running = false;
                break;

            case SDL_EVENT_KEY_DOWN:
                // snake.changeDirection(event.key.keysym.sym);
;
                break;
        }
    }
}


void Game::update() {
    snake.update();
    if (wall.isCollision(snake.getHead())) {
        running = false;
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    wall.render(renderer);
    snake.render(renderer);

    SDL_RenderPresent(renderer);
}


void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Game::isRunning() const {
    return running;
}

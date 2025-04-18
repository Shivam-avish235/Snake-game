#include "snake.h"

Snake::Snake(int blockSize)
    : blockSize(blockSize), dirX(1), dirY(0) {
    segments.push_back({5, 10});
}

void Snake::update() {
    SnakeSegment newHead = segments.front();
    newHead.x += dirX;
    newHead.y += dirY;

    segments.insert(segments.begin(), newHead);
    segments.pop_back();
}

void Snake::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (const auto& seg : segments) {
        SDL_FRect rect = {
            seg.x * blockSize,
            seg.y * blockSize,
            (float)blockSize,
            (float)blockSize
        };
        SDL_RenderFillRect(renderer, &rect);
    }
}

void Snake::changeDirection(SDL_Keycode key) {
    switch (key) {
        case SDLK_UP:
            if (dirY == 0) { dirX = 0; dirY = -1; }
            break;
        case SDLK_DOWN:
            if (dirY == 0) { dirX = 0; dirY = 1; }
            break;
        case SDLK_LEFT:
            if (dirX == 0) { dirX = -1; dirY = 0; }
            break;
        case SDLK_RIGHT:
            if (dirX == 0) { dirX = 1; dirY = 0; }
            break;
    }
}

void Snake::grow() {
    segments.push_back(segments.back());
}

SDL_FRect Snake::getHead() const {
    SnakeSegment head = segments.front();
    return {
        head.x * blockSize,
        head.y * blockSize,
        (float)blockSize,
        (float)blockSize
    };
}

const std::vector<SnakeSegment>& Snake::getSegments() const {
    return segments;
}

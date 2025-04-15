#include "../include/snake.h"

Snake::Snake(int blockSize) : blockSize(blockSize), dirX(1), dirY(0) {
    segments.push_back({5, 5});
}

void Snake::update() {
    // We'll fill this soon
}

void Snake::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (const auto& seg : segments) {
        SDL_FRect rect = {seg.x * blockSize, seg.y * blockSize, blockSize, blockSize};
        SDL_RenderFillRect(renderer, &rect);
    }
}

void Snake::changeDirection(SDL_Keycode key) {
    // We'll add logic here later
}

void Snake::grow() {
    // We'll add logic here later
}

const std::vector<SnakeSegment>& Snake::getSegments() const {
    return segments;
}

#include "wall.h"

Wall::Wall(int blockSize, int width, int height) : blockSize(blockSize) {
    for (int x = 0; x < width; x += blockSize) {
        blocks.push_back({static_cast<float>(x), 0.0f, static_cast<float>(blockSize), static_cast<float>(blockSize)});
        blocks.push_back({static_cast<float>(x), static_cast<float>(height - blockSize), static_cast<float>(blockSize), static_cast<float>(blockSize)});
    }

    for (int y = blockSize; y < height - blockSize; y += blockSize) {
        blocks.push_back({0.0f, static_cast<float>(y), static_cast<float>(blockSize), static_cast<float>(blockSize)});
        blocks.push_back({static_cast<float>(width - blockSize), static_cast<float>(y), static_cast<float>(blockSize), static_cast<float>(blockSize)});
    }
}
void Wall::render(SDL_Renderer* renderer ){
    SDL_SetRenderDrawColor(renderer,150,150,150,255);
    for(auto& block:blocks){
        SDL_RenderFillRect(renderer,&block);

    }
}

bool Wall::isCollision(SDL_FRect head){
    for(auto& block: blocks ){
        if(SDL_HasRectIntersectionFloat(&head, &block)){
            return true;
        }
        return false;
    }
}
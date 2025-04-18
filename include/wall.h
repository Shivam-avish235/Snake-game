#ifndef Wall_H
#define Wall_H
#include <SDL3/SDL.h>
#include <vector>
class Wall{
    public:
        Wall(int blockSize,int width, int height);
        void render (SDL_Renderer* renderer);
        bool isCollision(SDL_FRect head);

    private:    
         std::vector<SDL_FRect>blocks;
         int blockSize;

};

#endif

#include "food.h"
#include <cstdlib>
#include <ctime>
Food::Food(int blockSize,int maxX,int maxY):blockSize(blockSize),maxX(maxX),maxY(maxY){
       std::srand(static_cast<unsigned>(std::time(0)));
    spawn();
}
void Food::spawn(){
    x=std::rand()%maxX;
    y=std::rand()%maxY;
}
void Food::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_FRect rect={x*blockSize,y*blockSize,blockSize,blockSize};
    SDL_RenderFillRect(renderer,&rect);
    }
int Food::getX()const {return x;}
int Food::getY()const {return y;}
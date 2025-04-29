#include<SDL3/SDL.h>
#include <SDL2/SDL_ttf.h>
#include<iostream>
#include<cstdlib>
#include<ctime>


#define WINDOW_W 720
#define WINDOW_H 720

SDL_Window * window;
SDL_Renderer * renderer;
SDL_Event e;

bool isRunning;


//snake
enum Direction{
    STILL,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Snake{
    // int x, y;
    SDL_FRect rect;
    float speed;
    
    int snakeDirection = STILL;
    
    void render(){
        SDL_SetRenderDrawColor(renderer, 255,0,0,0);
        SDL_RenderFillRect(renderer, &rect);
            
    }

    void update(){
        
        switch (snakeDirection)
        {
            case UP:
            rect.y -= speed;
            break;
            case DOWN:
            rect.y += speed;
            break;
            case LEFT:
            rect.x -= speed;
            break;
            case RIGHT:
            rect.x += speed;
            break;
            
            default:
            break;
        }
      
    }
    void handleEvent(){
        if(e.type == SDL_EVENT_KEY_DOWN){
            switch (e.key.key)
            {
                case SDLK_W:
                snakeDirection = UP;
                break;
                case SDLK_A:
                snakeDirection = LEFT;
                break;
                case SDLK_S:
                snakeDirection = DOWN;
                
                break;
                case SDLK_D:
                /* code */
                snakeDirection = RIGHT;
                
                break;
                
                default:
                break;
            }
        }
    }
    
    
};

Snake snake;
SDL_FRect food;
void update();
void render();
void handleEvent();
void spwanFood();
void checkCollisions();


void spwanFood(){
    int GridSize=20;


    int maxX = (WINDOW_W / GridSize) - 1;
    int maxY = (WINDOW_H / GridSize) - 1;

    int foodx=(rand()%maxX)*GridSize;
    int foody=(rand()%maxY)*GridSize;
    food.x = foodx;
    food.y = foody;
    food.w = food.h = 20;
}


void iscollision(){
    if (snake.rect.x + 20> WINDOW_W) {
    //    isRunning=false;
    snake.snakeDirection=STILL;
    std::cout<<" i am out"<<std::endl;
    snake.rect.x = WINDOW_W - 20;
    }
    else if(snake.rect.y + 20 > WINDOW_H){
        snake.snakeDirection = STILL;
        snake.rect.y = WINDOW_H - 20;
    }
    else if(snake.rect.x < 0){
        snake.snakeDirection = STILL;
        snake.rect.x = 0;
    }
    else if(snake.rect.y < 0){
        snake.snakeDirection = STILL;
        snake.rect.y = 0;
    }
}


void FoodCollision() {

    if (snake.rect.x < food.x + food.w &&
        snake.rect.x + snake.rect.w > food.x &&
        snake.rect.y < food.y + food.h &&
        snake.rect.y + snake.rect.h > food.y) {
        
        std::cout << "Snake ate food!" << std::endl;
        snake.speed += 3;

        spwanFood();
    }
}

int main()
{

    SDL_Init(SDL_INIT_VIDEO);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    window = SDL_CreateWindow("Snake", WINDOW_W,WINDOW_H, SDL_WINDOW_RESIZABLE);
    
    renderer = SDL_CreateRenderer(window, NULL);
    
    snake.rect = {0,0,20,20};
    std::cout << "inital speed!" << std::endl;

    snake.speed = 5;
  int score=0;
    spwanFood();
    
    isRunning = true;
    while(isRunning){
        handleEvent();
        update();
        render();
        SDL_Delay(16);
    }

    return 0;   
}

void handleEvent(){
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_EVENT_QUIT){
            isRunning = false;
        }
        else if(e.type == SDL_EVENT_KEY_DOWN){
            snake.handleEvent();
        }
    }    
}


void update(){
    snake.update();
    iscollision();
    FoodCollision();
    // std:: cout<<"sanke position: "<< snake.rect.x<<" "<<snake.rect.y<<std::endl;
    // std:: cout<<"food position: "<< food.x<<" "<<food.y<<std::endl;


}

void render(){
    SDL_SetRenderDrawColor(renderer, 0,0,0,0);
    SDL_RenderClear(renderer);

    snake.render();

    
    SDL_SetRenderDrawColor(renderer, 0,255,0,255);
    SDL_RenderFillRect(renderer, &food);
    SDL_RenderPresent(renderer);

}
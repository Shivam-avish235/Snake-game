#include "game.h"
int main(int argc, const char *argv[])
{
    Game game(640, 458);
    if (!game.init("Snake Game"))
    {
        return -1;
    }
    while (game.isRunning())
    {
        game.handleEvents();
        game.update();
        game.render();
    }
    game.clean();
    return 0;
}
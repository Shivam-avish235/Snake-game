all:
	g++ src/main.cpp src/game.cpp src/snake.cpp src/food.cpp src/wall.cpp -Iinclude -lSDL3 -o main

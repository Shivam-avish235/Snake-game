all:
	g++ src/*.cpp -Iinclude -lSDL3 -o snake_game && ./snake_game

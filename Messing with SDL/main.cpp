#include <iostream>
#include <SDL.h>

using namespace std;

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
	}

	SDL_Window* window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

	if (NULL == window) {
		cout << "Could not create window: " << SDL_GetError << endl;
	}

	SDL_Event windowEvent;

	while (true) {
		if (SDL_PollEvent(&windowEvent)) {
			if (SDL_QUIT == windowEvent.type) {
				break;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
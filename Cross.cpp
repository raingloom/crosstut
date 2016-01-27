#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#ifdef __EMSCRIPTEN__
	#include <emscripten.h>
#endif
//CMake config
#include "CrossConfig.h"

int x = 0;
int y = 0;
SDL_Surface *screen;

void main_quit();
struct foo {
	int x, y;
};
void main_loop() {
	foo a;
	a.
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
						case SDLK_RIGHT: x++; break;
						case SDLK_LEFT: x--; break;
						case SDLK_UP: y--; break;
						case SDLK_DOWN: y++; break;
						default: printf("Other key"); break;
				}
			case SDL_QUIT: main_quit(); break;
			default: printf("Event"); break;
		}
	}

	// Clears the screen
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
	
	// fill stuff
	SDL_Rect rect = { x, y, 175, 125 };
	SDL_FillRect(screen, &rect, SDL_MapRGBA(screen->format, 0x22, 0x22, 0xff, 0xff));
	
}

int main(int argc, char **argv) {
	/*
	// include GL stuff, to check that we can compile hybrid 2d/GL apps
	extern void glBegin(int mode);
	extern void glBindBuffer(int target, int buffer);
	if (argc == 9876) {
		glBegin(0);
		glBindBuffer(0, 0);
	}
	*/

	// init main loop
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(600, 450, 32, SDL_HWSURFACE);
	
	printf("TTF Init: %d\n", TTF_Init());
	printf("Starting version %d.%d", Cross_VERSION_MAJOR, Cross_VERSION_MINOR);
	#ifdef __EMSCRIPTEN__
		emscripten_set_main_loop(main_loop, 30, 1);
	#else
		while (1) {
			main_loop();
		}
	#endif
	return 0;
}

void main_quit() {
	SDL_Quit();
}

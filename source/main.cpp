#include <stdio.h>
#include <switch.h>
#include <time.h>
#include <string.h>

#include <SDL2/SDL.h>

#include "main.hpp"
#include "App.hpp"


int main() {
	App app;
	app.start();

	while (app.isRunning) {
		app.update();
	}

	SDL_Quit();
	return EXIT_SUCCESS;
}

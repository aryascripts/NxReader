#include <switch.h>
#include <SDL2/SDL.h>

#include "main.hpp"
#include "App.hpp"


int main() {
	App* app = new App();
	app->start();

	while (app->isRunning && appletMainLoop()) {
		app->update();
	}

	delete app;
	SDL_Quit();
	return EXIT_SUCCESS;
}

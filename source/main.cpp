#include <switch.h>
#include <SDL2/SDL.h>

#include "main.hpp"
#include "App.hpp"

#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/errno.h>
#include <unistd.h>

#include <switch.h>

int main() {
	consoleInit(NULL); // TODO remove in final releases
	socketInitializeDefault();
	nxlinkStdio();


	printf("starting application...\n");
	App* app = new App();
	app->start();

	while (app->isRunning && appletMainLoop()) {
		app->update();
	}

	printf("stopping application...\n");

	delete app;
	consoleExit(NULL); // TODO remove in final release
	socketExit();
	SDL_Quit();
	return EXIT_SUCCESS;
}

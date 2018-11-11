#include <switch.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "App.hpp"

// Public
App::App() {
  isRunning = 1;
}

void App::start() {
  SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	romfsInit();

  mainWindow = new Window("NxReader-Main");

}


App::~App() {
  delete mainWindow;
}

void App::update() {
  hidScanInput();
  u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
  handleInput(&kDown);
}

void App::handleInput(u64 *kDown) {
  if(*kDown & KEY_PLUS || *kDown & KEY_MINUS) {
    // TODO ask for confirmation ?
    isRunning = 0;
  };

}

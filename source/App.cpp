#include <switch.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "App.hpp"
#include "Util.hpp"
#include "TextContent.hpp"
#include "Menu.hpp"

// Public
App::App() {
  isRunning = 1;
  winState = MENU;
  orientation = LAND;
}

App::~App() {
  delete mainWindow;
  delete mainMenu;
}

void App::start() {
  SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	romfsInit();

  mainWindow = new Window("NxReader-Main");
  mainMenu = new Menu(mainWindow, "NxReader - Books List");
}

void App::update() {
  frameStart = SDL_GetTicks();

  hidScanInput();
  u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
  handleInput(&kDown);

  mainWindow->clearWindow();
  mainMenu->renderHeader(orientation);
  mainWindow->update();

  frameTime = SDL_GetTicks() - frameStart;
  if(FRAME_DELAY > frameTime) {
    // delay the time that is remaining in this frame.
    SDL_Delay(FRAME_DELAY - frameTime);
  }
}

void App::handleInput(u64 *kDown) {
  if(*kDown & KEY_PLUS) {
    // TODO ask for confirmation ?
    isRunning = 0;
  }
  else if(*kDown & KEY_MINUS) {
    orientation = PORT;
  }
}

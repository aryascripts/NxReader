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

  // TTF_Font* font = TTF_OpenFont("romfs:/resources/fonts/Verdana.ttf", 24);


  mainWindow = new Window("NxReader-Main");
  // sansSmall = new TextContent(font, "Hello World");
  // SDL_Color color = {255, 255, 255};
  // sansSmall->renderText(mainWindow, color, 20, 710, 270.0);

  mainMenu = new Menu(mainWindow);

}

void App::update() {
  mainMenu->renderHeader();

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

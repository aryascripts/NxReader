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
  Util::setOrientation(PORT_R);
  SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	romfsInit();

  // printf("setting prev_touches and start_x\n");
  prev_touches = 0;
  start_x = 80;

  mainWindow = new Window("NxReader-Main");
  mainMenu = new Menu(mainWindow, "NxReader - Books List");
}

void App::update() {
  frameStart = SDL_GetTicks();

  hidScanInput();
  u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
  u32 touches = hidTouchCount();
  // printf("calling input methods\n");
  handleInput(&kDown);
  handleTouches(&touches);

  mainWindow->clearWindow();
  mainMenu->renderBooks(&start_x);
  mainMenu->renderHeader();
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
}

void App::handleTouches(u32 *touches) {
  touchPosition touch;
  // printf("if statement 1\n");
  if(prev_touches != *touches) {

    // last frame, user was not touching, this frame they are.
    if(prev_touches == 0 && *touches > prev_touches) {
      // printf("setting affect = 1\n");
      affect_x = 1; //true
      hidTouchRead(&touch, 0);
      // printf("setting touch_start_x \n");
      touch_start_x = touch.px;
      // printf("setting old_x\n");
      old_x = start_x;
    }
    if(*touches == 0) {
      // printf("affect_x = 0\n");
      affect_x = 0; //false
      touch_start_x = -1;
    }

    // printf("prev_touches = *touches\n");
    prev_touches = *touches;
  }


  if(affect_x && *touches > 0 && touch_start_x > 0) {
    // printf("reading touches\n");
    hidTouchRead(&touch, 0);
    // printf("setting start_x for frame\n");
    start_x = old_x + (touch.px - touch_start_x);
  }

  // printf("start_x > 80?\n");
  if(start_x > 80) {
    // printf("reset start_x\n");
    start_x = 80;
  }
}

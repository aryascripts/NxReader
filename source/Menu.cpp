#include "Menu.hpp"
#include <SDL2/SDL.h>


Menu::Menu(Window* win) {
  window = win;
  init("NxReader");
}

Menu::Menu(Window* win, const char* text) {
  window = win;
  init(text);
}

void Menu::init(const char* text) {
  headerFont = TTF_OpenFont("romfs:/resources/fonts/Verdana.ttf", 28);

  headerRect->x = 0;
  headerRect->y = 0;
  headerRect->w = window->w;
  headerRect->h = 60;

  headerText = new TextContent(headerFont, "NxHeader");
  headerColor = {0, 0, 0};

}

void Menu::renderHeader() {
  SDL_SetRenderDrawColor(window->getRenderer(),
                         0, 195, 227, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(window->getRenderer(), headerRect);

  headerText->renderText(window, headerColor, 20, headerRect->h/2 - 20, 0);

}

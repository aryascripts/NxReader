#include "Menu.hpp"
#include "Util.hpp"
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

  headerText = new TextContent(headerFont, text);
  headerColor = {255, 255, 255};

}

void Menu::renderHeader(Orientation orient) {

  SDL_SetRenderDrawColor(window->getRenderer(),
                         0, 195, 227, SDL_ALPHA_OPAQUE);

  if(orient == PORT) {
    headerRect->x = 0;
    headerRect->y = 0;
    headerRect->w = 60;
    headerRect->h = window->h;

    headerTextPos.x = 20;
    headerTextPos.y = headerRect->h - 20;

  }
  else {
    headerTextPos.x = 20;
    headerTextPos.y = headerRect->h / 2;
  }

  SDL_RenderFillRect(window->getRenderer(), headerRect);
  headerText->renderText(window, headerColor, headerTextPos.x, headerTextPos.y, 0);

}

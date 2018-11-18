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

Menu::~Menu() {
  delete headerText;
}

void Menu::init(const char* text) {
  headerFont = TTF_OpenFont("romfs:/resources/fonts/Verdana.ttf", 28);

  headerRect->x = 0;
  headerRect->y = 0;
  headerRect->w = 60;
  headerRect->h = window->h;

  headerTextPos.x = 15;
  headerTextPos.y = headerRect->h - 20;

  headerText = new TextContent(headerFont, text);
  headerColor = {255, 255, 255};

  char** ebooks;
  int file_count = Util::listFilesFromFolder("sdmc:/ebooks", &ebooks);

}

void Menu::renderHeader() {
  SDL_SetRenderDrawColor(window->getRenderer(), 0, 195, 227, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(window->getRenderer(), headerRect);
  headerText->renderText(window, headerColor, headerTextPos.x, headerTextPos.y, 270.0f);

}

#include "Menu.hpp"
#include "Util.hpp"
#include <dirent.h>
#include <malloc.h>
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
  delete ebooks;
}

void Menu::init(const char* text) {
  headerFont = TTF_OpenFont("romfs:/resources/fonts/Verdana.ttf", 28);
  printf("Loaded headerFont\n");

  headerRect = new SDL_Rect;
  headerRect->x = 0;
  headerRect->y = 0;
  headerRect->w = 60;
  headerRect->h = window->h;
  printf("set header positions, %d %d %d %d\n", headerRect->x, headerRect->y, headerRect->w, headerRect->h);

  headerTextPos.x = 15;
  headerTextPos.y = headerRect->h - 20;
  printf("set header text positions\n");

  headerText = new TextContent(headerFont, text);
  printf("created text content \n");

  ebooks = new std::vector<std::string>();
  int file_count = listFilesFromFolder("sdmc:/ebooks/", ebooks);

  printf("File count, %d\n", file_count);
}

void Menu::renderHeader() {
  printf("rendering header ... ");
  SDL_SetRenderDrawColor(window->getRenderer(), 0, 195, 227, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(window->getRenderer(), headerRect);
  headerText->renderText(window, (SDL_Color){255,255,255}, headerTextPos.x, headerTextPos.y, 270.0f);
  printf("finished rendering header \n");
}

void Menu::renderPage(int *page) {
  MenuItem items[12];
}

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
  itemsFont = TTF_OpenFont("romfs:/resources/fonts/Verdana.ttf", 22);
  printf("Loaded headerFont\n");

  headerRect = new SDL_Rect;
  headerRect->x = 0;
  headerRect->y = 0;
  headerRect->w = 80;
  headerRect->h = window->h;
  printf("set header positions, %d %d %d %d\n", headerRect->x, headerRect->y, headerRect->w, headerRect->h);

  headerTextPos.x = headerRect->x + 20;
  headerTextPos.y = headerRect->h - 20;
  printf("set header text positions\n");

  headerText = new TextContent(headerFont, text);
  printf("created text content \n");

  ebooks = new std::vector<std::string>();
  int file_count = listFilesFromFolder("sdmc:/ebooks/", ebooks);

  printf("File count, %d\n", file_count);
}

void Menu::renderHeader() {
  // printf("rendering header ... ");
  SDL_SetRenderDrawColor(window->getRenderer(), 0, 195, 227, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(window->getRenderer(), headerRect);
  headerText->renderText(window, (SDL_Color){255,255,255}, headerTextPos.x, headerTextPos.y, 270.0f);
  // printf("finished rendering header \n");
}

void Menu::renderBooks(int *startX) {

  int width = 50;
  // int startX = headerRect->w;
  // int perPage = 20;
  int max = (*ebooks).size();
  maxHeight = max * 50 + 80;

  // int startIndex = startingIndexForPage((*ebooks).size(), page, perPage);
  // int endIndex = startIndex + perPage;

  // printf("\nPAGES INFO: %d %d %d %d", width, startX, perPage, startIndex);

  int count = 0;
  for(int i = 0; i < max; i++) {
    int posX = (width * count++) + (*startX);

    // If the box is not displayed on the screen
    if((posX + width) < 0 || posX > window->w) {
      continue;
    }

    TextContent itemText(itemsFont, (*ebooks).at(i).c_str());
    SDL_Rect textRect = { posX, 0, width, window->h };
    SDL_SetRenderDrawColor(window->getRenderer(), 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(window->getRenderer(), &textRect);
    itemText.renderText(window, (SDL_Color){0,0,0}, textRect.x + 10, textRect.h - 20, 270.0f);
  }
}

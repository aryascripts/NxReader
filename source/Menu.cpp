#include "Menu.hpp"
#include "Util.hpp"
#include <dirent.h>
#include <malloc.h>
#include <SDL2/SDL.h>
#include <vector>
#include <string>

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


  headerRect->x = 0;
  headerRect->y = 0;
  headerRect->w = 60;
  headerRect->h = window->h;

  headerTextPos.x = 15;
  headerTextPos.y = headerRect->h - 20;

  headerText = new TextContent(headerFont, text);

  // char** ebooks;
  ebooks = new std::vector<std::string>();

  (*ebooks).push_back("hello world");
  printf("%s", (*ebooks).at(0));

  int file_count = listFilesFromFolder("sdmc:/ebooks/", ebooks);
  printf("File count, %d\n", file_count);
  // printf("books loaded... size %lu\n", (unsigned long)sizeof(**ebooks));
  // printf("first book name.. %s", ebooks[0]);
}

void Menu::renderHeader() {
  SDL_SetRenderDrawColor(window->getRenderer(), 0, 195, 227, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(window->getRenderer(), headerRect);
  headerText->renderText(window, (SDL_Color){255,255,255}, headerTextPos.x, headerTextPos.y, 270.0f);
}

void Menu::renderPage(int *page) {
  MenuItem items[12];
}

int Menu::listFilesFromFolder(const char *path, std::vector<std::string> *list) {
  printf("Starting dir read.. \n");

  DIR *dir = NULL;
  struct dirent *file = NULL;

  dir = opendir("sdmc:/ebooks/");
  printf("tried to open dir \n");

  if(dir == NULL) {
      printf("dir was empty/could not open.. \n");
      return 0;
  }
  printf("directory is valid \n");


  (*list).clear();
  printf("clear vector \n");

  file = readdir(dir);
  printf("read first element.. \n");

  while(file != NULL){
    printf("name: %s\n", file->d_name);
    (*list).push_back(std::string(file->d_name));
    file = readdir(dir);
  }
  printf("vector size, %lu", (unsigned long) (*list).size());

  closedir(dir);
  return (int)(*list).size();
}

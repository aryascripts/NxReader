#ifndef _NXREADER_MENU
#define _NXREADER_MENU

#include "Window.hpp"
#include "TextContent.hpp"
#include "Util.hpp"
#include "MenuItem.hpp"
#include <SDL2/SDL.h>

struct Point {
  int x;
  int y;
};

class Menu {
public:
  char** ebooks;

  // Constructors, one with a title
  Menu(Window* win);
  Menu(Window* win, const char* title);
  ~Menu();

  //Renders the header to the given window in the constructor
  void renderHeader();
  void setHeaderText(const char* text);
  void init(const char* text);
  void renderPage(int *page);

private:
  SDL_Rect* headerRect;
  Window* window;
  TextContent* headerText;

  Point headerTextPos;

  TTF_Font* headerFont;
  char* text;

};

#endif

#ifndef _NXREADER_MENU
#define _NXREADER_MENU

#include "Window.hpp"
#include "TextContent.hpp"
#include <SDL2/SDL.h>

class Menu {

public:

  // Constructors, one with a title
  Menu(Window* win);
  Menu(Window* win, const char* title);

  //Renders the header to the given window in the constructor
  void renderHeader();
  void setHeaderText(const char* text);
  void init(const char* text);

private:
  SDL_Rect* headerRect;
  Window* window;
  TextContent* headerText;

  TTF_Font* headerFont;
  SDL_Color headerColor;
  char* text;
};

#endif

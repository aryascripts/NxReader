#ifndef _NXREADER_CONTENT
#define _NXREADER_CONTENT

#include "Window.hpp"
#include <SDL2/SDL.h>

class TextContent {

public:
  TextContent(TTF_Font* font, const char* t);

  void renderText(Window* win, SDL_Color color, int x, int y, double angle);

  void setText(const char* text);

  int getHeight();

private:
  SDL_Surface* _surface;
  SDL_Texture* _texture;
  SDL_Rect rect;
  SDL_Point top;

  TTF_Font* font;
  int* size;

  const char* text;
};


#endif

#include "TextContent.hpp"
#include "Window.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


TextContent::TextContent(TTF_Font* f, const char* t) {
  font = f;
  text = t;
  top = {0, 0};
}

void TextContent::renderText(Window* win, SDL_Color color, int x, int y, double angle) {
  _surface = TTF_RenderText_Solid(font, text, color);
  _texture = SDL_CreateTextureFromSurface(win->getRenderer(), _surface);
  SDL_FreeSurface(_surface);

  rect.x = x;
  rect.y = y;
  rect.w = _surface->w;
  rect.h = _surface->h;

  SDL_RenderCopyEx(win->getRenderer(), _texture, NULL, &rect, angle, &top, SDL_FLIP_NONE);
  SDL_DestroyTexture(_texture);
}

int TextContent::getHeight() {
  return rect.h;
}

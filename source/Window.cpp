
#include "Window.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// TODO TEMP includes to be moved
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

Window::Window() {
  window = SDL_CreateWindow("NxReader-Main", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
}

Window::Window(const char* title) {
  window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

  SDL_Surface* bg_surface = IMG_Load("romfs:/resources/images/main.png");			// Read image as surface
  SDL_Texture* bg_texture = SDL_CreateTextureFromSurface(renderer, bg_surface);	// Create texture from surface

  // Create font:
  TTF_Font* font = TTF_OpenFont("romfs:/resources/fonts/Verdana.ttf", 24);
  SDL_Color color = {0, 0, 0};

  // Clear renderer:
  SDL_RenderClear(renderer);

  // Copy bg texture to renderer:
  SDL_RenderCopy(renderer, bg_texture, NULL, NULL);

  // Create text texture
  SDL_Surface* txt_surface = TTF_RenderText_Solid(font, "test", color);
  SDL_Texture* txt_texture = SDL_CreateTextureFromSurface(renderer, txt_surface);
  SDL_Rect txt_rect;
  txt_rect.x = 10;
  txt_rect.y = 10;
  txt_rect.w = txt_surface->w;
  txt_rect.h = txt_surface->h;

  // Copy text texture to renderer:
  SDL_RenderCopy(renderer, txt_texture, NULL, &txt_rect);

  // Render
  SDL_RenderPresent(renderer);						// Render renderer

}

Window::Window(const char* title, int* w, int* h) {
  window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, *w, *h, SDL_WINDOW_BORDERLESS);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
}

Window::~Window() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

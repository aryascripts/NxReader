
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
  setWidthHeight();
}

Window::Window(const char* title) {
  window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  setWidthHeight();


  SDL_Surface* bg_surface = IMG_Load("romfs:/resources/images/main.png");			// Read image as surface
  SDL_Texture* bg_texture = SDL_CreateTextureFromSurface(renderer, bg_surface);	// Create texture from surface

  // Clear renderer:
  SDL_RenderClear(renderer);

  // Copy bg texture to renderer:
  SDL_RenderCopy(renderer, bg_texture, NULL, NULL);

  // Render
  SDL_RenderPresent(renderer);						// Render renderer

}

Window::Window(const char* title, int* w, int* h) {
  window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, *w, *h, SDL_WINDOW_BORDERLESS);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  setWidthHeight();
}

Window::~Window() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

void Window::setWidthHeight() {
  SDL_GetRendererOutputSize(renderer, &w, &h);
}

SDL_Renderer* Window::getRenderer() {
  return renderer;
}

void Window::clearWindow() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

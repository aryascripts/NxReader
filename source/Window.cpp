
#include "Window.hpp"
#include "Util.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// TODO TEMP includes to be moved
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

Window::Window() {
  createBaseWindow();
  setWidthHeight();

  // _textureTarget = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
  // SDL_SetRenderTarget(renderer, _textureTarget);
}

Window::Window(const char* title) {
  createBaseWindow();
  setWidthHeight();

  // _textureTarget = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
  // SDL_SetRenderTarget(renderer, _textureTarget);
}

Window::Window(const char* title, int* wx, int* hy) {
  w = *wx;
  h = *hy;
  window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_BORDERLESS);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_SOFTWARE);

  // _textureTarget = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
  // SDL_SetRenderTarget(renderer, _textureTarget);
}

Window::~Window() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

void Window::createBaseWindow() {
  window = SDL_CreateWindow("NxReader-Main", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_FULLSCREEN_DESKTOP);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE | SDL_RENDERER_TARGETTEXTURE);
}

void Window::update() {
  // Clear the render target so it displays on the screen
  // SDL_SetRenderTarget(renderer, NULL);

  // SDL_RenderClear(renderer);

  // Copy the textureTarget to the real screen renderer, with any flips
  // if(Util::getOrientation() == PORT) {
    // SDL_RenderCopyEx(renderer, _textureTarget, NULL, NULL, 0, NULL, SDL_FLIP_HORIZONTAL);
  // }
  // else {
    // SDL_RenderCopy(renderer, _textureTarget);
  // }

  // Display to the screen
  SDL_RenderPresent(renderer);

  // Set the texture target to internal texture for next frame
  // SDL_SetRenderTarget(renderer, _textureTarget);
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
}

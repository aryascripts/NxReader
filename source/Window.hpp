#ifndef _NXREADER_WINDOW
#define _NXREADER_WINDOW

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Window  {

public:
  // Default constructor, make a full screen window
  // Default Title
  Window();

  // Default full screen window, given title
  Window(const char* title);

  // Default window with given title and size
  Window(const char* title, int* w, int* h);

private:

  // SDL_Window for rendering
  SDL_Window* window;

  // SDL Renderer for displaying textures
  SDL_Renderer* renderer;

};

#endif

#ifndef _NXREADER_WINDOW
#define _NXREADER_WINDOW

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Window  {

public:

  // Window width and height
  int w, h;

  // Default constructor, make a full screen window
  // Default Title
  Window();

  // Default full screen window, given title
  Window(const char* title);

  // Default window with given title and size
  Window(const char* title, int* w, int* h);

  // Destructor
  ~Window();

  // Clear window
  void clearWindow();

  SDL_Renderer* getRenderer();

  void update();

  void createBaseWindow();

private:

  // SDL_Window for rendering
  SDL_Window* window;

  // SDL Renderer for displaying textures
  SDL_Renderer* renderer;

  SDL_Texture* _textureTarget;

  void setWidthHeight();


};

#endif

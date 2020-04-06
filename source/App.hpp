#ifndef _NXREADER_APP
#define _NXREADER_APP

#include "Window.hpp"
#include "Util.hpp"
#include "TextContent.hpp"
#include "Menu.hpp"

class App {
public:
  int isRunning;
  WindowState winState;
  u32 prev_touches;

  App();
  ~App();

  void start();
  void update();

private:
  void run();
  void handleInput(u64* kDown);
  void handleTouches(u32* touches, int maxHeight);

  Window* mainWindow;
  Menu* mainMenu;

  int touch_start_x, affect_x, old_x, start_x;
  touchPosition start_touch;

  TextContent* sansSmall;

  int frameTime;
  int frameStart;
  const int FRAMES_PER_SECOND = 5;
  const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

};

#endif

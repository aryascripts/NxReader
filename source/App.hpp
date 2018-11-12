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

  App();
  ~App();

  void start();
  void update();

private:
  void run();
  void handleInput(u64* kDown);

  Window* mainWindow;
  Menu* mainMenu;

  TextContent* sansSmall;

};

#endif

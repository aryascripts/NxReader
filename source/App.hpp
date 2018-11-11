#ifndef _NXREADER_APP
#define _NXREADER_APP

#include "Window.hpp"

class App {

public:
  int isRunning;

  App();
  ~App();

  void start();
  void update();

private:
  void run();
  void handleInput(u64* kDown);

  Window* mainWindow;

};


#endif

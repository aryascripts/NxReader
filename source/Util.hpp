#ifndef _NXREADER_UTILS
#define _NXREADER_UTILS

enum WindowState { MENU, BOOK };
enum Orientation { LAND    = 0,
                   LAND_R  = 180,
                   PORT    = 90,
                   PORT_R  = 270 };

const int FRAMES_PER_SECOND = 20;
const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

class Util {
  static float getAngle(Orientation o);
}

#endif

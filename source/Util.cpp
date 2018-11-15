#include "Util.hpp"

Orientation Util::orientation = LAND;

void Util::setOrientation(Orientation o) {
  orientation = o;
}

Orientation Util::getOrientation() {
  return orientation;
}

float Util::getAngle() {
  switch(orientation) {
    case LAND:
      return 0.0f;
    case LAND_R:
      return 180.0f;
    case PORT:
      return 90.0f;
    case PORT_R:
      return 270.0f;
  }
  return 270.0f;
}

int Util::getFullWidth() {
  if(orientation == LAND || orientation == LAND_R) {
    return 1280;
  }
  else {
    return 720;
  }
}

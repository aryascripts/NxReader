#include "Util.hpp"
#include <stdio.h>
#include <dirent.h>
#include <malloc.h>

Orientation Util::orientation = LAND;
int Util::page = 0;

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



int startingIndexForPage(const int total, const int page, const int count) {
  // count = count per page
  // page = which page?
  // page always starts with 0
  // total = total in array

  // Find the maximum amount of pages that is valid
  int max_pages = total / count;
  if(total % count == 0) max_pages--;

  // requested for more than you can access
  if(page > max_pages) return max_pages;

  // return the start index of the page requested
  return (count * page);
}

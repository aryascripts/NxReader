#include "Util.hpp"
#include <stdio.h>
#include <dirent.h>
#include <malloc.h>

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

int Util::listFilesFromFolder(const char *path, char ***list) {
    int count = 0;
    DIR *directory = NULL;
    struct dirent *element = NULL;

    directory = opendir(path);
    if(directory != NULL) {
        return 0;
    }

    *list = NULL;
    element = readdir(directory);
    while(element != NULL){
        count++;
        element = readdir(directory);
    }

    rewinddir(directory);
    *list = (char**) calloc(count, sizeof(char *));

    count = 0;
    element = readdir(directory);
    while(NULL != element){
        (*list)[count++] = element->d_name;
        element = readdir(directory);
    }

    closedir(directory);
    return count;
}

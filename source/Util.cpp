#include "Util.hpp"
#include <stdio.h>
#include <dirent.h>
#include <malloc.h>
#include <vector>
#include <string>

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

int listFilesFromFolder(const char *path, std::vector<std::string> *list) {
  printf("Starting dir read.. \n");

  DIR *dir = NULL;
  struct dirent *file = NULL;

  dir = opendir("sdmc:/ebooks/");
  printf("tried to open dir \n");

  if(dir == NULL) {
      printf("dir was empty/could not open.. \n");
      return 0;
  }
  printf("directory is valid \n");


  (*list).clear();
  printf("clear vector \n");

  file = readdir(dir);
  printf("read first element.. \n");

  while(file != NULL){
    printf("name: %s\n", file->d_name);
    (*list).push_back(std::string(file->d_name));
    file = readdir(dir);
  }
  printf("vector size, %lu", (unsigned long) (*list).size());

  closedir(dir);
  return (int)(*list).size();
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

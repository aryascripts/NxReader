#ifndef _NXREADER_MENUITEM
#define _NXREADER_MENUITEM

#include "TextContent.hpp"

class MenuItem {
public:
  MenuItem();
  void setText(const char* text);

private:
  TextContent* tx;

};


#endif

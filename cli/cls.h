#ifndef CLS_H
#define CLS_H

#include <cstdlib>
void cls() {
  #ifdef _WINDOWS
    system("cls");
  #endif
  #ifdef linux
    system("clear");
  #endif
}

#endif

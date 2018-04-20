#include <iostream>

#include "init.h"

int main() {
  auto CLI = init_cli("config.cfg", std::cin, std::cout);
  try {
    while(true) CLI();
  }
  catch(...) {
    std::cout << "程序现在退出" << endl;
  }
  return 0;
}

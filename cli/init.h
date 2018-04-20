#ifndef INIT_H
#define INIT_H

#include <functional>
#include <iostream>
#include <string>
#include "menu.h"

std::function<void()> init_cli(const std::string &cfg, std::istream &is, std::ostream &os);


#endif

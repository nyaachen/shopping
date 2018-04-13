#ifndef MANAGER_H
#define MANAGER_H

#include <sstream>
#include <fstream>
#include <vector>

#include "goods.h"
#include "goods_list.cpp"
#include "user.h"

class Manager {
private:
  std::vector<User> user_list;
  std::vector<SuperUser> admin_list;
  goods_list stock;
public:
  explicit Manager(const std::string filename) {
    // TODO finish initializing library from file
  }
  
};



#endif

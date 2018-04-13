#ifndef MANAGER_H
#define MANAGER_H

#include <sstream>
#include <fstream>
#include <vector>

#include "goods.h"
#include "goods_list.cpp"
#include "user.h"

class Manager {
  constexpr User defaultUser("游客", "请登录");
private:
  std::vector<User> user_list;
  std::vector<SuperUser> admin_list;
  goods_list stock;
  bool init_stock(std::string filename) {}
  bool init_user_list(std::string filename) {}
  bool init_superuser_list(std::string filename) {}
public:
  explicit Manager(const std::string filename) {
    // TODO finish initializing library from file
  }
  SuperUser &superuser_login(std::string uname, std::string pwd) {
    auto iter = std::find_if(admin_list.begin(), admin_list.end(), [uname] (const SuperUser &u) -> bool {return u.get_username() == uname;});
    if ((iter != user_list.end()) and (iter->verify(pwd)))
      return *iter;
    //FIX report this error correctly
    throw "Invalid Argument";
  }
  bool superuser_remove_item(const SuperUser &u, const std::string &id) {}
  bool superuser_remove_item(const SuperUser &u, const Goods &item) {}
  bool superuser_add_item(const SuperUser &u, const Goods &item) {}
  bool superuser_modify_item(const SuperUser &u, const Goods &item) {}
  std::string superuser_view_sell_list(const SuperUser &u) {}
  void superuser_view_item(const SuperUser &u) {} //FIX

  User &login(std::string uname, std::string pwd) {
    auto iter = std::find_if(user_list.begin(), user_list.end(), [uname] (const User &u) -> bool {return u.get_username() == uname;});
    if ((iter != user_list.end()) and (iter->verify(pwd)))
      return *iter;
    return defaultUser;
  }
  void user_view_item(const User &u, ) {} //FIX
};



#endif

#ifndef MANAGER_H
#define MANAGER_H



#include <vector>

#include "goods.h"
#include "goods_list.h"
#include "user.h"

class Manager {
private:
  std::vector<User> users;
  std::vector<SuperUser> admins;
  std::string configfile;
  goods_list stock;
  bool init_stock(std::string filename) {}
  bool init_user_list(std::string filename) {}
  bool init_superuser_list(std::string filename) {}
public:
  explicit Manager(const std::string filename);
  Manager(const Manager &m) = delete;
  Manager &operator=(Const Manager&) = delete;

  decltype(stock.cbegin()) cbegin() {return stock.cbegin();}
  decltype(stock.cend()) cend() {return stock.cend();}

  SuperUser &superuser_login(std::string uname, std::string pwd);
  bool superuser_remove_item(const SuperUser &u, const std::string &id);
  bool superuser_remove_item(const SuperUser &u, const Goods &item);
  bool superuser_add_item(const SuperUser &u, const Goods &item);
  Goods &superuser_modify_item(const SuperUser &u, const std::string &id);
  Goods &superuser_modify_item(const SuperUser &u, const Goods &item);
  std::string superuser_view_sell_list(const SuperUser &u);

  User &login(std::string uname, std::string pwd) {
    auto iter = std::find_if(user_list.begin(), user_list.end(), [uname] (const User &u) -> bool {return u.get_username() == uname;});
    if ((iter != user_list.end()) and (iter->verify(pwd)))
      return *iter;
    return defaultUser;
  }
  void user_checkout(User &u) {}
};



#endif

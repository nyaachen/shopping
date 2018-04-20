#ifndef MANAGER_H
#define MANAGER_H



#include <vector>

#include "goods.h"
#include "goods_list.h"
#include "user.h"

class Manager {
protected:
  std::vector<User> users;
  std::vector<SuperUser> admins;
  std::string configfile;
  goods_list stock;
  bool init_stock(std::string filename);
  bool init_user_list(std::string filename);
  bool init_superuser_list(std::string filename);

  bool has_superuser(const SuperUser &u);
  bool has_user(const User &u);
  bool add_item(const Goods &item);
  bool remove_item(const std:string &id);
  bool modify_item(const std::string &id);
public:
  explicit Manager(const std::string filename);
  Manager(const Manager &m) = delete;
  Manager &operator=(Const Manager&) = delete;

  decltype(stock.cbegin()) cbegin() {return stock.cbegin();}
  decltype(stock.cend()) cend() {return stock.cend();}
  Goods_list find_by_id(const std::string &id) {return stock.find_by_id(id);}
  Goods_list find_by_name(const std::string &name) {return stock.find_by_name(name);}

  bool new_user(const std::string &username, const std::string &pwd);
  SuperUser &superuser_login(std::string uname, std::string pwd);
  bool superuser_remove_item(const SuperUser &u, const std::string &id);
  bool superuser_remove_item(const SuperUser &u, const Goods &item);
  bool superuser_add_item(const SuperUser &u, const Goods &item);
  Goods &superuser_modify_item(const SuperUser &u, const std::string &id);
  Goods &superuser_modify_item(const SuperUser &u, const Goods &item);
  std::string superuser_view_sell_list(const SuperUser &u);

  User &login(std::string uname, std::string pwd);
  void user_checkout(User &u);
};



#endif

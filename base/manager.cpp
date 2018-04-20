#include <algorithm>

#include "manager.h"

Manager::Manager(const std::string filename) : configfile(filename), users(), admins(), stock() {
  // TODO finish initializing library from file
  // users.emplace_back();
  ;
}

bool init_stock(std::string filename) {}
bool init_user_list(std::string filename) {}
bool init_superuser_list(std::string filename) {}

SuperUser &Manager::superuser_login(std::string uname, std::string pwd) {
  auto iter = std::find_if(admins.begin(), admins.end(), [uname] (const SuperUser &u) -> bool {return u.get_username() == uname;});
  if ((iter != admins.end()) and (iter->verify(pwd)))
    return *iter;
  else throw "Invalid Argument";
}
User &Manager::login(std::string uname, std::string pwd) {
  auto iter = std::find_if(users.begin(), users.end(), [uname] (const User &u) -> bool {return u.get_username() == uname;});
  if ((iter != users.end()) and (iter->verify(pwd)))
    return *iter;
  else throw "Invalid Argument";
}
bool Manager::new_user(const std::string &username, const std::string &pwd){
  auto iter = std::find_if(users.begin(), users.end(), [username] (const User &u) {return u.get_username() == username;});
  if (iter == users.end()) throw "Invalid Argument";
  users.emplace_back(username, pwd, Goods_list());
  return true;
}
bool Manager::has_user(const User &u){
  auto iter = std::find_if(users.begin(), users.end(), [&u] (const User &user) {return &u == &user;});
  if (iter == users.end()) return false;
  return true;
}
bool Manager::has_superuser(const SuperUser &u) {
  auto iter = std::find_if(admins.begin(), admins.end(), [&u] (const User &user) {return &u == &user;});
  if (iter == admins.end()) return false;
  return true;
}
bool Manager::remove_item(const std:string &id) {
  auto iter = std::find_if(stock.begin(), stock.end(), [id] (const Goods &g) {return g.get_id() == id;});
  if (iter == stock.end())  return false;
  *iter.set_number(-1);
  return true;
}
bool Manager::superuser_remove_item(const SuperUser &u, const std::string &id) {
  if (has_superuser(u))
    return remove_item(id);
  else
    raise "Invalid Argument";
}
bool Manager::superuser_remove_item(const SuperUser &u, const Goods &item) {
  if (has_superuser(u))
    return remove_item(item.get_id());
  else
    raise "Invalid Argument";
}
bool Manager::add_item(const Goods &item) {
  stock.push_back(item);
  return true;
}
bool Manager::superuser_add_item(const SuperUser &u, const Goods &item) {
  if (has_superuser(u))
    return add_item(item);
  else
    raise "Invalid Argument";
}
Goods &modify_item(const std::string &id) {
  auto iter = std::find_if(stock.begin(), stock.end(), [id] (const Goods &g) {return g.get_id() == id;});
  if (iter == stock.end()) raise "Invalid Argument";
  else return *iter;
}
Goods &superuser_modify_item(const SuperUser &u, const std::string &id) {
  if (has_superuser(u))
    return modify_item(id);
  else
    raise "Invalid Argument";
}
Goods &Manager::superuser_modify_item(const SuperUser &u, const Goods &item) {
  if (has_superuser(u))
    return modify_item(item.get_id());
  else
    raise "Invalid Argument";
}
std::string Manager::superuser_view_sell_list(const SuperUser &u) {}

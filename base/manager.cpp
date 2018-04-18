#include <algorithm>

#include "manager.h"

Manager::Manager(const std::string filename) : configfile(filename), users(), admins(), stock() {
  // TODO finish initializing library from file
  // users.emplace_back();
  throw "Not Complited Error"
}
SuperUser &Manager::superuser_login(std::string uname, std::string pwd) {
  auto iter = std::find_if(admins.begin(), admins.end(), [uname] (const SuperUser &u) -> bool {return u.get_username() == uname;});
  if ((iter != user_list.end()) and (iter->verify(pwd)))
    return *iter;
  //FIX report this error correctly
  throw "Invalid Argument";
}
bool Manager::superuser_remove_item(const SuperUser &u, const std::string &id) {
  auto iter = std::find_if(stock.begin(), stock.end(), [id] (const Goods &g) {return g.get_id() == id;});
  if (iter == stock.end())  return false;
  *iter.set_number(-1);
}
bool Manager::superuser_remove_item(const SuperUser &u, const Goods &item) {}
bool Manager::superuser_add_item(const SuperUser &u, const Goods &item) {}
bool Manager::superuser_modify_item(const SuperUser &u, const Goods &item) {}
std::string Manager::superuser_view_sell_list(const SuperUser &u) {}

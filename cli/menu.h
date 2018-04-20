#ifndef MENU_H
#define MENU_H


#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>

#include "goods.h"
#include "goods_list.h"
constexpr std::string TAB("\t");
constexpr std::string LINE_SEP(50,'*');

ostream &operator<<(std::ostream &os, const Goods &g){
  std::ostringstream tos
  tos << g.get_id() << TAB << g.get_name() << TAB << g.get_brand() << TAB << std::fixed << std::setprecision(1) << g.get_price() << TAB << g.get_number();
  return os << tos.str();
}

ostream &operator<<(std::ostream &os, const Goods_list &l){
  os << "ID" << TAB << "名称" << TAB << "品牌"< TAB << "价格" << TAB << "数量" << std::endl << LINE_SEP << std::endl;
  for(auto iter = l.cbegin(); iter != l.cend(); ++iter)
    os << *iter << std::endl;
  return os;
}

class Menu {
  friend std::ostream &operator<<(std::ostream &os, const Menu &m);
private:
  std::string name;
  std::function<void()> func;
public:
  Menu(std::string &s, std::function<void()> f) : name(s), func(f) {}
  Menu(const Menu &) = delete;
  Menu &operator=(const Menu &m) = delete;
  void operator()() {
    f();
  }
};
std::ostream &operator<<(std::ostream &os, const Menu &m) {
  os << m.name;
  return os;
}

class Menulist{
  friend std::ostream &operator<<(std::ostream &os, const Menulist &m);
private:
  std::vector<Menu> l;
  constexpr std::string SELECTIONS ("123456789abcdefghigklmnopqrstuvwxyz");
  constexpr std::string EXIT ("0");
public:
  Menulist() : l() {}
  add_menu(const std::string &name, std::function<void()> f){
    l.emplace_back(name, f);
  }
  void operator()(const std::string &s) {
    if ((s) and (s[0] != EXIT)) {
      auto select = SELECTIONS.find(s[0]);
      if (select != std::string::npos) {
        l[select]();
      }
    }
  }
};

std::ostream &operator<<(std::ostream &os, const Menulist &m) {
  size_t i(0);
  for (auto iter=m.l.begin(); iter != m.l.end(); ++iter){
    os << m.SELECTIONS[i] << TAB << *iter << std::endl;
    ++i;
  }
  os << m.EXIT << TAB << "退出" <<std::endl;
  return os;
}


#endif

#ifndef MENU_H
#define MENU_H

#include <functional>
#include <utility>

struct Menu_entry {
  std::string title;
  std::function<void()> entry;
};

class Menu {
private:
  bool exit_option;
public:
  explicit Menu(bool exit = true) : exit_option(exit), menu_entry() {}
  bool has_exit() {return exit_option;}
  vector<Menu_entry> menu_list;
  decltype(menu_list.cbegin()) cbegin() const {return menu_list.cbegin();}
  decltype(menu_list.cend()) cend() const {return menu_list.cend();}
};

#endif

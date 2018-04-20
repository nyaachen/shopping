#include <iostream>
#include <fstream>

#include "init.h"
#include "menu.h"
#include "manager.h"
#include "user.h"
#include "goods.h"
#include "goods_list.h"



void main_loop(Manager &m ,std::istream &is, std::ostream &os);

std::function<void()> init_cli(const std::string &cfg, std::istream &is, std::ostream &os) {
  Manager my_manager(cfg);
  return [&] () {main_loop(my_manager, is, os);}
}

void user_login(Manager &m, std::istream &is, std::ostream &os);
void user_register(Manager &m, std::istream &is, std::ostream &os);
void superuser_login(Manager &m, std::istream &is, std::ostream &os);

void main_loop(Manager &m, std::istream &is, std::ostream &os)
  // prompt user login like this
  Menulist main_menu();
  main_menu.add_menu("用户登录", [&] () {user_login(m, is, os);} );
  main_menu.add_menu("用户注册", [&] () {user_register(m, is, os);} );
  main_menu.add_menu("管理员登录", [&] () {superuser_login(m, is, os);} );
  os << main_menu << "选择:";
  std::string choices;
  is >> choices;
  main_menu(choices);
}
void user_interface(Manager &m, User &u, std::istream &is, std::ostream &os);
void superuser_interface(Manager &m, SuperUser &u, std::istream &is, std::ostream &os);
void user_login(Manager &m, std::istream &is, std::ostream &os) {
  cout << "请输入用户名";
  cin >> uname;
  cout << "请输入密码";
  cin >> pwd;
  try {
    User &u = manager.login(uname, pwd);
    user_interface(m, u, is, os);
  }
  catch (...) { os << "登陆失败" << std::endl;}
}
void user_register(Manager &m, std::istream &is, std::ostream &os) {
  cout << "请输入用户名";
  cin >> uname;
  cout << "请输入密码";
  cin >> pwd;
  try {
    manager.new_user(uname, pwd);
    User &u = manager.login(uname, pwd);
    user_interface(m, u, is, os);
  }
  catch (...) { os << "注册失败" << std::endl;}
}

void superuser_login(Manager &m, std::istream &is, std::ostream &os) {
  cout << "请输入管理员名";
  cin >> uname;
  cout << "请输入密码";
  cin >> pwd;
  try {
    SuperUser &u = manager.superuser_login(uname, pwd);
    superuser_interface(m, u, is, os);
  }
  catch (...) { os << "登陆失败" << std::endl;}
}

void view_item(Manager &m, std::ostream &os, bool showneg=false) {
  for(auto iter = m.cbegin(); iter != m.cend(); ++iter) {
    if ((showneg) or (*iter.get_number() > 0))
      os << *iter << std::endl;
  }
}
void search_item(Manager &m, std::istream &is, std::ostream &os) {
  os << "请输入商品名";
  std::string name;
  is >> name;
  auto r = m.find_by_name(name);
  if (r.is_empty()) os << "没有相关商品" << std::endl;
  else os << "找到以下商品\n" << r;
}
void user_add_item(Manager &m, User &u, std::istream &is, std::ostream &os) {
  os << "要添加的商品id和数量";
  std::string id; int count(0);
  is >> id >> count;
  auto r = m.find_by_id(id);
  if (r.is_empty()) os << "没有该商品" << std::endl;
  else u.cart += r;
}
void user_modify_item(Manager &m, User &u, std::istream &is, std::ostream &os) {
  
}
void user_interface(Manager &m, User &u, std::istream &is, std::ostream &os) {
  Menulist m();
  m.add_menu("查看商品", [&] () {view_item(m, os);} );
  m.add_menu("搜索商品", [&] () {search_item(m, is, os);});
  m.add_menu("加入购物车", [&] () {user_add_item(m, u, is, os);});
  m.add_menu("修改购物车", [&] () {user_modify_item(m, u, is, os);});
  while (true) {

  }
}
void superuser_interface(Manager &m, SuperUser &u, std::istream &is, std::ostream &os);

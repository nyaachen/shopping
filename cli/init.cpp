#include <iostream>
#include <fstream>

#include "init.h"
#include "menu.h"
#include "manager.h"
#include "user.h"
#include "goods.h"
#include "goods_list.h"

constexpr std::string LINE_SEP(50,'*');

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
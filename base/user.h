#ifndef USER_H
#define USER_H

#include <utility>
#include "goods_list.h"

class SuperUser;
class User {
private:
  std::string username;
  std::string password;
public:
  Goods_list cart;
  User(User &a) = delete;
  User &operator=(const User &u) = delete;
  User(std::string uname, std::string pwd, const Goods_list &c) : username(uname), password(pwd), cart(c){}
  const std::string get_username() const {return username;}
  bool verify(std::string pwd) {return password == pwd;}
};
class SuperUser{
private:
  std::string username;
  std::string password;
public:
  SuperUser(SuperUser &a) = delete;
  SuperUser &operator=(const SuperUser &u) = delete;
  SuperUser(std::string uname, std::string pwd) : username(uname), password(pwd) {}
  const std::string get_username() const {return username;}
  bool verify(std::string pwd) {return pwd == password;}
};

#endif

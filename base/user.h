#ifndef USER_H
#define USER_H

#include <utility>
class SuperUser;
class User {
  friend class SuperUser;
private:
  std::string username;
  std::string password;
  bool privilege_level;
public:
  User(User &a) = delete;
  User(std::string uname, std::string pwd) : username(uname), password(pwd) {}
  const std::string get_username() const {return username;}
  bool verify(std::string pwd) {return password == pwd;}
};
class SuperUser{
private:
  std::string username;
  std::string password;
public:
  SuperUser(SuperUser &a) = delete;
  SuperUser(std::string uname, std::string pwd) : username(uname), password(pwd) {}
  bool give_privilege(User &u) {u.privilege_level = true;}
  bool remove_privilege(User &u) {u.privilege_level = false;}
  void set_pwd(std::string pwd) {password = pwd;}
  void set_pwd(User &u, std::string pwd) {u.password = pwd;}
  bool verify(std::string pwd) {return pwd == password;}
};

#endif

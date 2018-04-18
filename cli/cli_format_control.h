#ifndef CLI_FORMAT_CONTROL_H
#define CLI_FORMAT_CONTROL_H


#include <iostream>
#include <sstream>
#include <string>

#include "goods.h"
#include "goods_list.h"
constexpr std::string TAB("\t");
constexpr std::string line_sep(60, "*");

ostream &operator<<(std::ostream &os, const Goods &g){
  std::ostringstream tos
  tos << g.get_id() << TAB << g.get_name() << TAB << g.get_brand() << TAB << std::fixed << std::setprecision(1) << g.get_price() << TAB << g.get_number();
  return os << tos.str();
}

ostream &operator<<(std::ostream &os, const Goods_list &l){
  for(auto iter = l.cbegin(); iter != l.cend(); ++iter)
    os << *iter << std::endl;
  return os;
}

#endif

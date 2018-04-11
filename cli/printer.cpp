#include <string>
#include <sstream>
#include <iomanip>

#include "cls.h"
#include "../base/goods.h"

const std::string line_split(80,'*');
std::string pretty_list_printer();
std::string pretty_goods_printer(const Goods &s){
  std::string str;
  std::ostringstream os(str);
  os << std::setw(8) << s.get_id() << std::setw(10) << s.get_name() << s.get_brand() << std::setw(8) << std::setprecision(2) << s.get_price() << s.get_number();
  return str;
}

#include <iostream>
int main(){Goods test("F0001 三鹿牛奶（天然） 三鹿 32 10"); std::cout << pretty_goods_printer(test); return 0;}

#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "goods_list.h"


Goods_list::Stock(): goods_list() {}
Goods_list::Stock(const std::vector<Goods> &source_list) : goods_list(source_list) {}
Goods_list Goods_list::find_by_id(const std::string &id) {
  Goods_list tmp;
  std::copy_if(goods_list.begin(), goods_list.end(), std::back_inserter(tmp), [id] (Goods &a) {return a.get_id() == id;});
  return Goods_list(tmp);
}
Goods_list Goods_list::find_by_name(const std::string &name) {
  Goods_list tmp;
  std::copy_if(goods_list.begin(), goods_list.end(), std::back_inserter(tmp), [name] (Goods &a) {return a.get_name().find(name) != std::string::npos;});
  return Goods_list(tmp);
}
Goods_list Goods_list::find_by_brand(const std::string &brand) {
  Goods_list tmp;
  std::copy_if(goods_list.begin(), goods_list.end(), std::back_inserter(tmp), [brand] (Goods &a) {return a.get_brand().find(brand) != std::string::npos;});
  return Goods_list(tmp);
}
Stock & Goods_list::sell_cart();
decltype(goods_list.cbegin()) Goods_list::cbegin() {return goods_list.cbegin();}
decltype(goods_list.cend()) Goods_list::cend() {return goods_list.cend();}

bool Goods_list::is_empty() const {return goods_list.empyt();}
bool Goods_list::is_sub_list(const Goods_list &sub) const;

Goods_list Goods_list::operator+(const Goods_list &another) const
Goods_list Goods_list::operator-(const Goods_list &another) const
Goods_list &Goods_list::remove_sub_list(const Goods_list &another);

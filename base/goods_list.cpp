#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "goods_list.h"


Goods_list Goods_list::find_sub_item(std::function<bool(Goods&)> unaryPred){
  Goods_list tmp;
  std::copy_if(goods_list.begin(), goods_list.end(), std::back_inserter(tmp), unaryPred);
  return Goods_list(tmp);
}
Goods_list::Stock(): goods_list() {}
Goods_list::Stock(const std::vector<Goods> &source_list) : goods_list(source_list) {}
Goods_list Goods_list::find_by_id(const std::string &id) {
  return find_item([id] (Goods &a) {return a.get_id() == id;});
}
Goods_list Goods_list::find_by_name(const std::string &name) {
  return find_item([name] (Goods &a) {return a.get_name().find(name) == std::string::npos;});
}
Goods_list Goods_list::find_by_brand(const std::string &brand) {
  return find_item([brand] (Goods &a) {return a.get_brand() == brand;});
}
Stock & Goods_list::sell_cart();
decltype(goods_list.cbegin()) Goods_list::cbegin() {return goods_list.cbegin();}
decltype(goods_list.cend()) Goods_list::cend() {return goods_list.cend();}

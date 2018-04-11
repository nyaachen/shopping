#include <vector>
#include <algorithm>
#include <functional>
#include <utilituy>

#include "goods.h"

class Stock {
  private :
    std::vector<Goods> goods_list;
    decltype(goods_list.begin()) find_item(std::function<bool(Goods&)> unaryPred){
      return std::find_if(goods_list.begin(), goods_list.end(), unaryPred);}
  public :
    Stock(): goods_list() {}
    Goods & find_by_id(std::string id) {
      auto iter = find_item([id] (Goods &a) {return a.get_id() == id;});
      if (iter == goods_list.end())
        return ngoods;
      else
        return *iter;
    }
    Goods & find_by_name(std::string name) {
      auto iter = find_item([name] (Goods &a) {return a.get_name() == name;});
      if (iter == goods_list.end())
        return ngoods;
      else
        return *iter;
    }
    Goods & find_by_brand(std::string brand) {
      auto iter = find_item([brand] (Goods &a) {return a.get_brand() == brand;});
      if (iter == goods_list.end())
        return ngoods;
      else
        return *iter;
    }
    Stock & sell_cart();
    decltype(goods_list.cbegin()) cbegin() {return goods_list.cbegin();}
    decltype(goods_list.cend()) cend() {return goods_list.cend();}
};

#ifndef GOODS_LIST_H
#define GOODS_LIST_H

#include <vector>
#include <functional>


#include "goods.h"

class Goods_list {
  private :
    std::vector<Goods> goods_list;
    Goods_list find_sub_item(std::function<bool(Goods&)> unaryPred);
  public :
    Stock();
    explicit Stock(const std::vector<Goods> &source_list);
    Goods_list find_by_id(const std::string &id);
    Goods_list find_by_name(const std::string &name);
    Goods_list find_by_brand(const std::string &brand);
    Stock & sell_cart();
    decltype(goods_list.cbegin()) cbegin();
    decltype(goods_list.cend()) cend();
};





#endif

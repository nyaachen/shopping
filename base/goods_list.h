#ifndef GOODS_LIST_H
#define GOODS_LIST_H

#include <vector>


#include "goods.h"

class Goods_list {
  private :
    std::vector<Goods> goods_list;
  public :
    Stock();
    explicit Stock(const std::vector<Goods> &source_list);
    Goods_list find_by_id(const std::string &id);
    Goods_list find_by_name(const std::string &name);
    Goods_list find_by_brand(const std::string &brand);
    Stock & sell_cart();
    decltype(goods_list.cbegin()) cbegin();
    decltype(goods_list.cend()) cend();

    bool is_sub_list(const Goods_list &sub) const;
    bool is_empty() const;

    bool all_goods_is_positive() const;

    Goods_list operator+(const Goods_list &another) const;
    Goods_list operator-(const Goods_list &another) const;
    Goods_list &remove_sub_list(const Goods_list &another);
};





#endif

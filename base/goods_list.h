#ifndef GOODS_LIST_H
#define GOODS_LIST_H

#include <list>


#include "goods.h"

class Goods_list : public std::list<Goods> {
  public :
    Goods_list() = default;
    Goods_list find_by_id(const std::string &id);
    Goods_list find_by_name(const std::string &name);
    Goods_list find_by_brand(const std::string &brand);

    bool is_sub_list(const Goods_list &sub) const;
    bool is_empty() const;

    bool all_goods_is_positive() const;

    bool remove_item(const std::string &id);
    bool remove_item(const Goods &g);

    Goods_list operator+(const Goods_list &another) const;
    Goods_list operator-(const Goods_list &another) const;
    Goods_list &operator+=(const Goods_list &another);
    Goods_list &operator-=(const Goods_list &another);
    Goods_list &remove_sub_list(const Goods_list &another);
};





#endif

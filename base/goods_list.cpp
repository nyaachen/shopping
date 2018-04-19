#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "goods_list.h"


Goods_list Goods_list::find_by_id(const std::string &id) {
  Goods_list tmp;
  std::copy_if(begin(), end(), std::back_inserter(tmp), [id] (Goods &a) {return a.get_id() == id;});
  return Goods_list(tmp);
}
Goods_list Goods_list::find_by_name(const std::string &name) {
  Goods_list tmp;
  std::copy_if(begin(), end(), std::back_inserter(tmp), [name] (Goods &a) {return a.get_name().find(name) != std::string::npos;});
  return Goods_list(tmp);
}
Goods_list Goods_list::find_by_brand(const std::string &brand) {
  Goods_list tmp;
  std::copy_if(begin(), end(), std::back_inserter(tmp), [brand] (Goods &a) {return a.get_brand().find(brand) != std::string::npos;});
  return Goods_list(tmp);
}

bool Goods_list::is_empty() const {return goods_list.empty();}


bool remove_item(const std::string &id) {
  auto iter = std::find_if(begin(), end(), [id] (const Goods &g) {return g.get_id() == id;});
  if (iter == end()) return false;
  erase(iter);
  return true;
}
bool remove_item(const Goods &g) {return remove_item(g.get_id());}

Goods_list Goods_list::operator+(const Goods_list &another) const {
  Goods_list tmp(*this);
  for(auto iter = another.cbegin(); iter != another.cend(); ++iter) {
    auto target = std::find_if(tmp.begin(), tmp.end(), [iter] (const Goods &g) {return g.get_id() == iter->get_id();});
    if (target == tmp.end()) tmp.push_back(*iter);
    else *target += *iter;
  }
  return tmp;
}
Goods_list Goods_list::operator-(const Goods_list &another) const {
  Goods_list tmp(*this);
  for(auto iter = another.cbegin(); iter != another.cend(); ++iter) {
    auto target = std::find_if(tmp.begin(), tmp.end(), [iter] (const Goods &g) {return g.get_id() == iter->get_id();});
    if (target == tmp.end()) throw "Invalid Argument"; // FIX using std error
    *target -= *iter;
  }
  return tmp;
}
Goods_list &operator+=(const Goods_list &another){
  for(auto iter = another.cbegin(); iter != another.cend(); ++iter) {
    auto target = std::find_if(begin(), end(), [iter] (const Goods &g) {return g.get_id() == iter->get_id();});
    if (target == end()) push_back(*iter); // FIX using std error
    else *target -= *iter;
  }
  return *this;
}
Goods_list &operator-=(const Goods_list &another){
  for(auto iter = another.cbegin(); iter != another.cend(); ++iter) {
    auto target = std::find_if(begin(), end(), [iter] (const Goods &g) {return g.get_id() == iter->get_id();});
    if (target == end()) throw "Invalid Argument"; // FIX using std error
    *target -= *iter;
  }
  return *this;
}

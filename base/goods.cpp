#include <sstream>
#include <string>

// TODO 优化底层的实现方法

#include "goods.h"

Goods::Goods(std::string s) {
	std::istringstream is(s);
	is >> item_id >> item_name >> item_brand >> price >> number;
}
Goods::Goods(std::string id, std::string name, std::string brand, double p, int n) :
	item_id(id), item_name(name), item_brand(brand), price(p), number(n) {}

const std::string & Goods::get_id() const {return item_id;}
const std::string & Goods::get_name() const {return item_name;}
const std::string & Goods::get_brand() const {return item_brand;}
const double Goods::get_price() const {return price;}
const int Goods::get_number() const {return number;}

Goods Goods::operator-(const Goods &item) const
{return Goods(item_id, item_name, item_brand, price, number-item.number);}
Goods Goods::operator+(const Goods &item) const
{return Goods(item_id, item_name, item_brand, price, number+item.number);}

Goods ngoods("No id","No item","No brand",0,0);

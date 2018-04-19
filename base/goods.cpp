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
double Goods::get_price() const {return price;}
int Goods::get_number() const {return number;}

bool set_price(double a) {price = a; return true;}
bool set_number(int a) {number = a; return true;}

bool Goods::is_same_item(const Goods &g) const {
	return item_id == g.item_id;
}
Goods Goods::operator-(const Goods &item) const{
	return Goods(item_id, item_name, item_brand, price, number-item.number);
}
Goods Goods::operator+(const Goods &item) const{
	return Goods(item_id, item_name, item_brand, price, number+item.number);
}
Goods &operator-=(const Goods &item){
	number -= item.number;
	return *this;
}
Goods &operator+=(const Goods &item){
	number += item.number;
	return *this;
}

bool operator<(const Goods &item) const {
	return number < item.number;
}
bool operator>(const Goods &item) const {
	return number > item.number;
}
bool operator<=(const Goods &item) const {return !(*this>item);}
bool operator>=(const Goods &item) const {return !(*this<item);}

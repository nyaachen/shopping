#ifndef GOODS_H
#define GOODS_H

#include <string>
#include <sstream>

class Goods {
	private :
		std::string item_id;
		std::string item_name;
		std::string item_brand;
		double price;
		int number;
  public :
  	explicit Goods(std::string s);
    Goods(std::string id, std::string name, std::string brand, double p, int n);

    const std::string & get_id() const;
    const std::string & get_name() const;
    const std::string & get_brand() const;
    const double get_price() const;
    const int get_number() const;

    Goods operator-(const Goods &item) const;
    Goods operator+(const Goods &item) const;
		bool operator<(const Goods &item) const;
};

#endif

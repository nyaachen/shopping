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
    double get_price() const;
    int get_number() const;

		bool set_price(double a);
		bool set_number(int a);

		bool is_same_item(const Goods &g) const;
    Goods operator-(const Goods &item) const;
    Goods operator+(const Goods &item) const;
		Goods &operator-=(const Goods &item);
		Goods &operator+=(const Goods &item);
		bool is_no_more_than(const Goods &item) const;
};

#endif

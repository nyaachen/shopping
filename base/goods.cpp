#include <sstream>
#include <string>

// TODO 优化底层的实现方法

class Goods {
	private :
		std::string item_id;
		std::string item_name;
		std::string item_brand;
		double price;
		int number;
	public :
		explicit Goods(std::string s) {
			std::istringstream is(s);
			is >> item_id >> item_name >> item_brand >> price >> number;
		}
		Goods(std::string id, std::string name, std::string brand, double p, int n) :
				item_id(id), item_name(name), item_brand(brand), price(p), number(n) {}

		const std::string & get_id() const {return item_id;}
		const std::string & get_name() const {return item_name;}
		const std::string & get_brand() const {return item_brand;}
		const double get_price() const {return price;}
		const int get_number() const {return number;}

		Goods operator-(const Goods &item) const
			{return Goods(item_id, item_name, item_brand, price, number-item.number);}
		Goods operator+(const Goods &item) const
			{return Goods(item_id, item_name, item_brand, price, number+item.number);}
		bool is_offline() const {return number == -1;}
};

Goods ngoods("No id","No item","No brand",0,0);

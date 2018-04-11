#include <sstream>
#include <string>
#include <vector>

// TODO 优化底层的实现方法

class Goods {
	private :
		std::string main_attribute {};
		std::vector<std::string> attribute_list {};
	public :
		Goods() = default;
		explicit Goods(std::string s) : Goods() {
			std::isstream is(s);
			is >> main_attribute;
			std::string temp;
			while (is >> temp)
				attribute_list.emplace(temp);
		}
		Goods(Goods &goods) = delete;
		Goods * set_main_attribute(const string &s) {main_attribute = s; return this;}
		const string & get_main_attribute() {return main_attribute;}
}

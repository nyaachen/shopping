#include <sstream>
#include <string>
#include <vector>



class Goods {
	private :
		string main_attribute {};
		vector<string> attribute_list {};
	public :
		Goods() = default;
		explicit Goods(string s) : Goods() {
			isstream is(s);
			is >> main_attribute;
			string temp;
			while (is >> temp)
				attribute_list.emplace(temp);
		}
		Goods(Goods &goods) = delete;
		Goods * set_main_attribute(string s) {main_attribute = s; return this;}
		const string & get_main_attribute() {return main_attribute;}
}


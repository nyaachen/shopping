#ifndef PRINTER_H
#define PRINTER_H

#include <string>
#include <sstream>
#include <iomanip>

#include "menu.h"
#include "cls.h"

constexpr std::string sep("  ");

template <typename T> T &get_input(T &a) {};
constexpr std::string line_split(80,'*');

std::string pretty_goods_printer(const Goods &s){
  std::ostringstream os;
  os << std::left << std::setw(8) << s.get_id() << std::setw(20) << s.get_name() << std::setw(20) << s.get_brand() << std::setw(8) << std::fixed << std::setprecision(2) << s.get_price() << std::setw(8) << s.get_number();
  return os.str();
}

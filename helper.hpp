#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

#include "boost/format.hpp"
#include "boost/filesystem.hpp"

class Helper {
public:
  static std::string humn_size(uintmax_t);
  static std::string generate_temp_file_name(const std::string&);
};

#endif

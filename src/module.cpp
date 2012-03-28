#include "module.h"
#include <fstream>

vhdl::module::module(std::string name) {
  name_ = name;
  body_file_name_ = "";
}

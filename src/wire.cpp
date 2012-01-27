#include "wire.h"

vhdl::wire::wire(std::string name, unsigned int size) {
  name_ = name;
  size_ = size;
}

void vhdl::wire::print(std::ostream &stream, std::string append) {
  stream << "signal " << name_ << ": ";
  
  if (size_ > 1)
    stream << "std_logic_vector(" << size_ -1 << " downto 0)";
  else
    stream << "std_logic";

  stream << append;
}

void vhdl::wire::set_name(std::string name) { name_ = name; }
void vhdl::wire::set_size(unsigned int size) { size_ = size; }

std::string vhdl::wire::name() { return name_; }
unsigned int vhdl::wire::size() { return size_; }





vhdl::input_wire::input_wire(std::string name, unsigned int size) 
  : wire(name, size) { }

void vhdl::input_wire::print(std::ostream &stream, std::string append) {
  stream << name_ << ": in ";

  if (size_ > 1)
    stream << "std_logic_vector(" << size_ -1 << " downto 0)";
  else
    stream << "std_logic";

  stream << append;
}





vhdl::output_wire::output_wire(std::string name, unsigned int size)
  : wire(name, size) { }

void vhdl::output_wire::print(std::ostream &stream, std::string append) {
  stream << name_ << ": out ";

  if (size_ > 1)
    stream << "std_logic_vector(" << size_ -1 << " downto 0)";
  else
    stream << "std_logic";

  stream << append;
}

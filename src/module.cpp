#include "module.h"
#include <fstream>

vhdl::module::module(std::string name) {
  this->name = name;
  this->body_file_name = "";
}

void vhdl::module::print_ports(std::ostream &stream) {
  for (int port_num = 0; port_num < this->io_ports.size(); ++port_num) {
    if (this->io_ports[port_num] == this->io_ports.back()) {
      this->io_ports[port_num]->print(stream, "\n");
    }
    else {
      this->io_ports[port_num]->print(stream, ";\n");
    }
  }
}

void vhdl::module::print_architecture_from_file(std::ostream &stream) {

  std::fstream file;
  std::string line;
  file.open(this->body_file_name.c_str(), std::fstream::in);

  if (file.is_open())
    while ( getline(file,line) )
      stream << line << std::endl;
  else
    stream << "Error: Could not open file '" << this->body_file_name << "'.\n";
}

void vhdl::module::print(std::ostream &stream) {
  stream << "library IEEE;\n"
	 << "use ieee.std_logic_1164.all;\n"
	 << "use ieee.std_logic_unsigned.all;\n\n";

  stream << "entity " << this->name << " is port (\n";
  this->print_ports(stream);
  stream << ");\n"
	 << "end " << this->name << ";\n\n";

  stream << "architecture Behavioral of " << this->name << " is\n";
  if (this->body_file_name != "")
    this->print_architecture_from_file(stream);
  stream << "end Behavioral;\n";
}

void vhdl::module::print_component_declaration(std::ostream &stream) {
  stream << "component " << this->name << " is port(\n";
  this->print_ports(stream);
  stream << ");\n"
	 << "end component;\n";
}

void vhdl::module::set_name(std::string name) {
  this->name = name;
}

void vhdl::module::set_body(std::string file_name) {
  this->body_file_name = file_name;
}

void vhdl::module::add_port(vhdl::ports *to_add) {
  // I will not enforce any vhdl rules
  // can add ports with same name, etc.
  this->io_ports.push_back(to_add);
}

std::vector<vhdl::ports *> vhdl::module::get_ports() {
  return this->io_ports;
}

std::string vhdl::module::get_name() {
  return this->name;
}

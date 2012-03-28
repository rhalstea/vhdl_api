#include "module.h"
#include <fstream>

vhdl::module::module(std::string name) {
  name_ = name;
  body_text_ = "";
  body_file_name_ = "";
}

void vhdl::module::set_name(std::string name) {
  name_ = name;
}

void vhdl::module::set_body_text(std::string body_text) {
  body_text_ = body_text;
}

void vhdl::module::set_body_file(std::string file_name) {
  body_file_name_ = file_name;
}

std::string vhdl::module::name() {
  return name_;
}

std::vector<vhdl::wire*> vhdl::module::get_ports() {
  if (body_text_ != "" || body_file_name_ != "")
    return io_ports_;

  // else build io_ports from connection list
  // FIXME: make it do the above comment
  return io_ports_;
}

void vhdl::module::print(std::ostream &stream) {
  if (body_text_ != "") {
    stream << body_text_;
  }
  else if (body_file_name_ != "") {
    std::fstream file;
    std::string line;

    file.open(body_file_name_.c_str(), std::fstream::in);
    while (getline(file,line)) {
      stream << line << std::endl;
    }
    file.close();
  }
  else {
    print_headder(stream);
    print_entity(stream);
    print_architecture(stream);
  }
}

void vhdl::module::print_component(std::ostream &stream) {
  stream << "component " << name_ << " is \n"
	 << "port(\n";

  std::vector<vhdl::wire*> ports = get_ports();
  for (int i = 0; i < ports.size(); ++i)
    if (i == ports.size() -1)
      ports[i]->print(stream, "\n");
    else
      ports[i]->print(stream, ";\n");

  stream << ");\n"
	 << "end component\n";
}

void vhdl::module::add_port(vhdl::wire *w) {
  assert (dynamic_cast<input_wire*>(w) ||
	  dynamic_cast<output_wire*>(w));

  for (int i = 0; i < io_ports_.size(); ++i)
    if (io_ports_[i] == w)
      return;

  io_ports_.push_back(w);
}






void vhdl::module::print_headder(std::ostream &stream) {
  // default headder libraries
  stream << "Headders" << std::endl;
  // user specified libraries
}

void vhdl::module::print_entity(std::ostream &stream) {
  stream << "Entity" << std::endl;
}

void vhdl::module::print_architecture(std::ostream &stream) {
  stream << "Architecture" << std::endl;
}

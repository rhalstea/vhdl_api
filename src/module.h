#ifndef __SRC_MODULE_H__
#define __SRC_MODULE_H__

#include <ostream>
#include <vector>
#include <map>
#include <string>

#include "ports.h"

namespace vhdl {
  
  class module {
  protected:
    std::string name;
    std::vector<vhdl::ports *> io_wires;

    // can write the body from file
    std::string body_file_name;

  private:
    void print_ports(std::ostream &stream);
    void print_architecture_from_file(std::ostream &stream);

  public:
    module(std::string name);

    void print(std::ostream &stream);
    void print_component_declaration(std::ostream &stream);

    void set_name(std::string name);
    void set_body(std::string file_name);
    void add_port(vhdl::ports *to_add);
    
    std::string get_name();
    std::vector<vhdl::ports *> get_ports();

  };

}

#endif

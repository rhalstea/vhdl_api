#ifndef __SRC_MODULE_H__
#define __SRC_MODULE_H__

#include <ostream>
#include <vector>
#include <string>

#include "connection.h"
#include "wire.h"

namespace vhdl {
  
  class module {
  private:
    std::string name_;
    vhdl::connection_list connections_;

    // variables for modules that are not generated
    std::string body_text_;
    std::string body_file_name_;
    std::vector<vhdl::wire*> io_ports_;

    void print_headder(std::ostream &stream);
    void print_entity(std::ostream &stream);
    void print_architecture(std::ostream &stream);

  public:
    module(std::string name);

    void set_name(std::string name);
    void set_body_text(std::string body_text);
    void set_body_file(std::string file_name);

    void add_port(vhdl::wire *w);
    
    std::string name();
    std::vector<vhdl::wire*> get_ports();

    void print(std::ostream &stream);
    void print_component(std::ostream &stream);
  };

}

#endif

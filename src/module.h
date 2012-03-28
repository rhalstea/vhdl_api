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
    std::string body_file_name_;
    vhdl::connection_list connections_;

  public:
    module(std::string name);

    void print(std::ostream &stream);

    void set_name(std::string name);
    void set_body(std::string file_name);
    
    std::string get_name();
    std::vector<vhdl::wire *> get_io_ports();
  };

}

#endif

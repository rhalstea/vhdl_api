#ifndef __SRC_CONNECTION_H__
#define __SRC_CONNECTION_H__

#include "wire.h"

#include <ostream>
#include <string>
#include <vector>
#include <map>

namespace vhdl {

  class connection {
  private:
    vhdl::wire *signal_;
    vhdl::wire *source_;
    std::vector<vhdl::wire *> destinations_;

  public:
    connection(std::string name, vhdl::wire *src, vhdl::wire *dest);
    ~connection();

    void add_destination(vhdl::wire *dest);

    vhdl::wire *source();
    std::string name();
    unsigned size();
    vhdl::wire *destination(unsigned pos);
    vhdl::wire *operator[](unsigned pos);

    bool has_destination(vhdl::wire *dest);

    void print_declaration(std::ostream &stream, std::string append = "");
    void print_name(std::ostream &stream, std::string append = "");
  };

  
  
  class connection_list {
  private:
    // A map for all the sources and destinations
    std::map<vhdl::wire*, vhdl::connection*> sources_;
    std::map<vhdl::wire*, vhdl::connection*> destinations_;
    // A map for all io_connection sources and destinations
    std::map<vhdl::wire*, vhdl::connection*> io_sources_;
    std::map<vhdl::wire*, vhdl::connection*> io_destinations_;

    // A counter used to generate unique connection names
    unsigned int unique_name_counter_;
    std::string unique_id();


    void verify_src_and_dest(vhdl::wire *src, vhdl::wire *dest);
    bool connection_exists(vhdl::wire *src, vhdl::wire *dest);
    vhdl::connection *get_connection_with_source(vhdl::wire *w);
    vhdl::connection *get_connection_with_destination(vhdl::wire *w);

  public:
    // constructor & destructor
    connection_list();
    ~connection_list();

    // add a connection from one port to another
    //   have to check if source already exists, and dest is not a source
    void add_connection(vhdl::wire *src, vhdl::wire *dest);

    // add io connection
    //   check that source is input to input or output to output
    //   if source already exists must be input to input
    void add_io_connection(vhdl::wire *src, vhdl::wire *dest);

    // a search that returns a connection
    vhdl::connection *get_connection(vhdl::wire *w);
    // a search that returns the name of a wire
    std::string get_connection_name(vhdl::wire *w);
    
    // a function to get a list of all connections 
  };

}

#endif

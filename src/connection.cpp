#include "connection.h"

#include <cassert>
#include <sstream>
#include <iostream> // remove me

vhdl::connection::connection(std::string name, 
			     vhdl::wire *src, 
			     vhdl::wire *dest) {
  signal_ = new wire(name, src->size());
  source_ = src;

  destinations_.clear();
  add_destination(dest);
}

vhdl::connection::~connection() {
  delete signal_;
}



void vhdl::connection::add_destination(vhdl::wire *dest) {
  if (has_destination(dest))
    return; // connection already exists

  destinations_.push_back(dest);
}



std::string vhdl::connection::name() {
  return signal_->name();
}

vhdl::wire *vhdl::connection::source() {
  return source_;
}

unsigned vhdl::connection::size() {
  return destinations_.size();
}

vhdl::wire *vhdl::connection::destination(unsigned pos) {
  return destinations_[pos];
}

vhdl::wire *vhdl::connection::operator[](unsigned pos) {
  return destination(pos);
}

bool vhdl::connection::has_destination(vhdl::wire *dest) {
  for (int i = 0; i < size(); ++i)
    if (dest == destination(i))
      return true;

  return false;
}

void vhdl::connection::print_declaration(std::ostream &stream, 
					 std::string append) {
  signal_->print(stream, append);
}

void vhdl::connection::print_name(std::ostream &stream, std::string append) {
  stream << signal_->name() << append;
}





// 
// Connection List Class Functions
// ----- ----- ----- ----- ----- -----
vhdl::connection_list::connection_list() {
  unique_name_counter_ = 0;
}

vhdl::connection_list::~connection_list() {
  // This will go through all source maps and delete the connections
}

void vhdl::connection_list::add_connection(vhdl::wire *src, 
					   vhdl::wire *dest) {
  if (dynamic_cast<vhdl::input_wire*>(src) != NULL ||
      dynamic_cast<vhdl::output_wire*>(dest) != NULL) {
    add_io_connection(src, dest);
    return;
  }

  if (connection_exists(src, dest))
    return;

  verify_src_and_dest(src, dest);

  vhdl::connection *conn = get_connection_with_source(src);
  
  if (conn != NULL) { // source already exists
    conn->add_destination(dest);
    destinations_[dest] = conn;
  }
  else { // source does not exist
    vhdl::connection *new_conn =
      new vhdl::connection(src->name() + unique_id(), src, dest);

    sources_[src] = new_conn;
    destinations_[dest] = new_conn;
  }
  
}

void vhdl::connection_list::add_io_connection(vhdl::wire *src,
					      vhdl::wire *dest) {
  if (connection_exists(src, dest))
    return;

  verify_src_and_dest(src, dest);
  
  assert( dynamic_cast<vhdl::input_wire*>(src) != NULL ||
	  dynamic_cast<vhdl::output_wire*>(dest) != NULL );

  vhdl::connection *conn = get_connection_with_source(src);
  
  if (conn != NULL) { // source already exists
    conn->add_destination(dest);
    io_destinations_[dest] = conn;
  }
  else { // source does not exist
    vhdl::connection *new_conn =
      new vhdl::connection(src->name() + unique_id(), src, dest);

    io_sources_[src] = new_conn;
    io_destinations_[dest] = new_conn;
  }
}

vhdl::connection* vhdl::connection_list::get_connection(vhdl::wire *w) {
  vhdl::connection *conn;

  conn = get_connection_with_source(w);
  if (conn != NULL)
    return conn;
  conn = get_connection_with_destination(w);
  if (conn != NULL)
    return conn;

  return NULL;  
}

std::string vhdl::connection_list::get_connection_name(vhdl::wire *w) {
  vhdl::connection *conn = get_connection(w);

  if (conn != NULL)
    return conn->name();
  else
    return "";
}





std::string vhdl::connection_list::unique_id() {
  std::stringstream ss;
  ss << "_" << unique_name_counter_;
  
  ++unique_name_counter_;
  return ss.str();
}

void vhdl::connection_list::verify_src_and_dest(vhdl::wire *src,
						vhdl::wire *dest) {

  assert( dynamic_cast<vhdl::output_wire*>(src) == NULL
	  and "Source cannot be an output wire");
  assert( dynamic_cast<vhdl::input_wire*>(dest) == NULL
	  and "Destination cannot be an input wire");

  assert( get_connection_with_source(dest) == NULL
	  and "Destination is already a source");
  assert( get_connection_with_destination(src) == NULL
	  and "Source is already a destination");
  assert( get_connection_with_destination(dest) == NULL
	  and "Destination already has a source");
}

bool vhdl::connection_list::connection_exists(vhdl::wire *src,
					      vhdl::wire *dest) {
  vhdl::connection *conn;

  conn = get_connection_with_source(src);
  if (conn != NULL && conn->has_destination(dest))
    return true;

  return false;
}

vhdl::connection* 
vhdl::connection_list::get_connection_with_source(vhdl::wire *w) {
  std::map<vhdl::wire*,vhdl::connection*>::iterator conn;
  std::map<vhdl::wire*,vhdl::connection*>::iterator io_conn;

  conn = sources_.find(w);
  io_conn = io_sources_.find(w);

  if (conn != sources_.end())
    return conn->second;
  else if (io_conn != io_sources_.end())
    return io_conn->second;
  else
    return NULL;
}

vhdl::connection*
vhdl::connection_list::get_connection_with_destination(vhdl::wire *w) {
  std::map<vhdl::wire*,vhdl::connection*>::iterator conn;
  std::map<vhdl::wire*,vhdl::connection*>::iterator io_conn;

  conn = destinations_.find(w);
  io_conn = io_destinations_.find(w);

  if (conn != destinations_.end())
    return conn->second;
  else if (io_conn != io_destinations_.end())
    return io_conn->second;
  else
    return NULL;
}

#include "connection.h"

#include <cassert>

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
}

vhdl::connection_list::~connection_list() {
  // This will go through all source maps and delete the connections
}

void vhdl::connection_list::add_connection(vhdl::wire *src, 
					   vhdl::wire *dest) {
  if (connection_exists(src, dest))
    return;
  
  // Make sure dest is not a source
  assert( is_source(dest) and "A destination cannot be a source");

  // FIXME: should I check if destination is already used?

  vhdl::connection *conn;
  get_connection_with_source(src);

  if (conn != NULL) {// if source exists
    conn->add_destination(dest);
    destinations_[dest] = conn
  }
  else { // new connection
    vhdl::connection *new_conn = 
      new vhdl::connection(src->name() + unique_id(), src, dest);

    sources_[src] = new_conn;
    destinations_[dest] = new_conn;
  }
}

void vhdl::connection_list::add_io_connection(vhdl::wire *src,
					      vhdl::wire *dest) {

}

bool vhdl::connection_list::connection_exists(vhdl::wire *src,
					      vhdl::wire *dest) {
  // check internal connections
  std::map<vhdl::wire*,vhdl::connection*>::iterator src_iter;
  for (src_iter = sources_.begin(); src_iter != sources_.end(); ++src_iter)
    if (src_iter->first == src && src_iter->second->has_destination(dest))
      return true;

  // check io connections (do I really want to do this?)

  return false;
}

bool vhdl::connection_list::is_source(vhdl::wire *w) {
  std::map<vhdl::wire*,vhdl::connection*>::iterator src_iter;
  for (src_iter = sources_.begin(); src_iter != sources_.end(); ++src_iter)
    if (src_iter->first == w)
      return true;

  return false;
}

vhdl::connection* 
vhdl::connection_list::get_connection_with_source(vhdl::wire *w) {
  std::map<vhdl::wire*,vhdl::connection*>::iterator src_iter;
  for (src_iter = sources_.begin(); src_iter != sources_.end(); ++src_iter)
    if (src_iter->first == w)
      return src_iter->second;

  for (src_iter = io_sources_.begin(); 
       src_iter != io_sources_.end(); 
       ++src_iter)
    if (src_iter->first == w)
      return src_iter->second;

  return NULL:
}

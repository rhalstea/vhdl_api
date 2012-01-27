#ifndef __SRC_WIRE_H__
#define __SRC_WIRE_H__

#include <ostream>
#include <string>

namespace vhdl {
  
  class wire {
  protected:
    std::string name_;
    unsigned int size_;

  public:
    wire(std::string name, unsigned int size);
    virtual void print(std::ostream &stream, std::string append = "");

    void set_name(std::string name);
    void set_size(unsigned size);

    std::string name();
    unsigned int size();
  };


  class input_wire : wire {
  public:
    input_wire(std::string name, unsigned int size);
    void print(std::ostream &stream, std::string append = "");
  };

  class output_wire : public wire {
  public:
    output_wire(std::string name, unsigned int size);
    void print(std::ostream &stream, std::string append = "");
  };
}

#endif

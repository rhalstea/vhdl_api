#ifndef __VHDL_SIGNALS_H__
#define __VHDL_SIGNALS_H__

#include <string>
#include <ostream>

namespace vhdl {
   class signal {
      protected:
         std::string _name;
         unsigned    _size;

      public:
         signal(std::string name, unsigned bit_width);
         ~signal();

         virtual void print(std::ostream &stream, std::string append = "");

         std::string name();
         unsigned    size();

         void set_name(std::string name);
         void set_size(unsigned size);
   };

   class input_port : public signal {
      public:
         input_port(std::string name, unsigned bit_width);
         ~input_port();
         virtual void print(std::ostream &stream, std::string append = "");
   };
   
   class output_port : public signal {
      public:
         output_port(std::string name, unsigned bit_width);
         ~output_port();
         virtual void print(std::ostream &stream, std::string append = "");

   };
}

#endif

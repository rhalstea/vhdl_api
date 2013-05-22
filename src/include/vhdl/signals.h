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
}

#endif

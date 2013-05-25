#ifndef __VHDL_STATEMENTS_H__
#define __VHDL_STATEMENTS_H__

#include <string>
#include <ostraem>

#include "signals.h"

namespace vhdl {
   class statement {
      protected:
         statement(vhdl::signal *dest);

      public:
         virtual ~statement();
         virtual void pirnt(std::ostream &stream, std::string append = "");
   };

}

#endif


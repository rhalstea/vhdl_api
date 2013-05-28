#ifndef __VHDL_EXPRESSIONS_H__
#define __VHDL_EXPRESSIONS_H__

#include <iostream>
#include "signals.h"

namespace vhdl {
   class expression {
      private:

      protected:
         expression();
         vhdl::signal *_signal;

      public:
         expression(vhdl::signal *sig);
         virtual ~expression();
         virtual void print(std::ostream &stream);

         virtual unsigned num_bits();

   };

   class add : public expression {
      private:
         
      protected:
         vhdl::expression *_lhs;
         vhdl::expression *_rhs;

      public:
         add( vhdl::expression *lhs, vhdl::expression *rhs);
         ~add();

         virtual void print(std::ostream &stream);
   };
}

#endif   

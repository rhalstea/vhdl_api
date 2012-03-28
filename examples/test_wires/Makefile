VHDL_INSTALL_PATH = /Users/rhalstea/git/vhdl_api

GCC 	  = g++
GCC_FLAGS = 

INCLUDES  = -I$(VHDL_INSTALL_PATH)/src

LIBS	  = -L$(VHDL_INSTALL_PATH)/lib
LIBS	  += -lvhdl

default:
	@echo "specify file to make"

%.exe: %.cpp
	$(GCC) $(GCC_FLAGS) $(INCLUDES) $(LIBS) -o $@ $<
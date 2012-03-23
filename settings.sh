#!/bin/bash

if [ "$OSTYPE" = "darwin11" ] ; then
    export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:/Users/rhalstea/git/vhdl_api/lib
else if [ "$OSTYPE" = "linux-gnu" ] ; then
   export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/rhalstea/programs/vhdl_api/lib
fi 
fi
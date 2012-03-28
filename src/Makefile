GCC = g++
GCC_FLAGS = -fPIC
OBJECTS = wire.o connection.o module.o

OS_TYPE = $(shell uname)

BUILD_SHARED_LIBRARY=@echo "Unsupported OS"

ifeq ($(OS_TYPE), Linux)
	BUILD_SHARED_LIBRARY=ld -G *.o -o ../lib/libvhdl.so
endif

ifeq ($(OS_TYPE), Darwin)
	BUILD_SHARED_LIBRARY=$(GCC) -dynamiclib -undefined suppress -flat_namespace *.o -o ../lib/libvhdl.so
endif

all: $(OBJECTS)
	@mkdir -p ../lib
	$(BUILD_SHARED_LIBRARY)

%.o: %.cpp %.h
	$(GCC) $(GCC_FLAGS) -c $<

clean:
	rm -rf *.o ../lib/*.so ../lib/*.dylib *.~
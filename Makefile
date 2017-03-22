
CC := g++
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
HEADERDIR := include
TARGET := lib/libress.so

#SOURCES := $(shell find $(SRCDIR) -type f -name "*.cpp")
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
#OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.cpp=.o))
OBJECTS := $(SOURCES:.cpp=.o)

CFLAGS := -fPIC -Wall -Wextra -O2 -g
LDFLAGS := -shared
LIB := -Llib
INC := -Iinclude

all: ${TARGET}

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ ${LDFLAGS}

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "Cleaning...";
	$(RM) $(RM) $(OBJECTS) $(TARGET)

# Tests
test: test/test_ress.cpp
	$(CC) $(CFLAGS) test/test_ress.cpp $(INC) $(LIB) -lress -o bin/test_ress

.PHONY: clean
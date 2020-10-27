KAKOUNE ?=

ifeq ($(KAKOUNE),)
$(error Please pass the KAKOUNE variable, which must point to the project directory)
endif

SRC ?= \
    $(KAKOUNE)/src/exception.cc \
    $(KAKOUNE)/src/memory.cc \
    $(KAKOUNE)/src/string.cc \
    $(KAKOUNE)/src/string_utils.cc \
    $(KAKOUNE)/src/unit_tests.cc
OBJECTS = $(SRC:.cc=.o)

CXX := clang++
INCLUDE ?= -I$(KAKOUNE)/src
CXXFLAGS ?= \
    -g -O1 -fsanitize=fuzzer-no-link,address \
    -pedantic -std=c++17 -Wall -Wextra -Wno-unused-parameter -Wno-sign-compare -Wno-address -frelaxed-template-template-args
LDFLAGS ?= -fsanitize=fuzzer,address

all: kakfuzz-for_each_diff

clean:
	rm -f $(OBJECTS) for_each_diff.o

distclean: clean
	rm -f kakfuzz-for_each_diff

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

kakfuzz-for_each_diff: $(OBJECTS) for_each_diff.o
	$(CXX) $(LDFLAGS) -o $@ $^

.PHONY: all clean distclean

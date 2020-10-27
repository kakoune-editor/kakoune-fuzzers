KAKOUNE ?=

ifeq ($(KAKOUNE),)
$(error Please pass the KAKOUNE variable, which must point to the project directory)
endif

SRC ?= \
    $(KAKOUNE)/src/exception.cc \
    $(KAKOUNE)/src/memory.cc \
    $(KAKOUNE)/src/json.cc \
    $(KAKOUNE)/src/hash.cc \
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

all: kakfuzz-json_parse

clean:
	rm -f $(OBJECTS) json_parse.o

distclean: clean
	rm -f kakfuzz-json_parse

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

kakfuzz-json_parse: $(OBJECTS) json_parse.o
	$(CXX) $(LDFLAGS) -o $@ $^

.PHONY: all clean distclean

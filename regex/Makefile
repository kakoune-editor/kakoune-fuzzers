KAKOUNE ?=

ifeq ($(KAKOUNE),)
$(error Please pass the KAKOUNE variable, which must point to the project directory)
endif

SRC ?= \
    $(KAKOUNE)/src/exception.cc \
    $(KAKOUNE)/src/memory.cc \
    $(KAKOUNE)/src/regex.cc \
    $(KAKOUNE)/src/regex_impl.cc \
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

all: kakfuzz-regex_match kakfuzz-regex_search

clean:
	rm -f $(OBJECTS) match.o search.o

distclean: clean
	rm -f kakfuzz-regex_match kakfuzz-regex_search

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

kakfuzz-regex_match: $(OBJECTS) match.o
	$(CXX) $(LDFLAGS) -o $@ $^

kakfuzz-regex_search: $(OBJECTS) search.o
	$(CXX) $(LDFLAGS) -o $@ $^

.PHONY: all clean distclean

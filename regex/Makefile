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
CFLAGS ?= \
    -g -O1 -fsanitize=fuzzer-no-link,address \
    -pedantic -std=c++17 -Wall -Wextra -Wno-unused-parameter -Wno-sign-compare -Wno-address -frelaxed-template-template-args
LDFLAGS ?= -fsanitize=fuzzer,address

all: kakfuzz-regex_match_self kakfuzz-regex_search_self

clean:
	rm -f $(OBJECTS) match_self.o search_self.o

distclean: clean
	rm -f kakfuzz-regex_match_self kakfuzz-regex_search_self

%.o: %.cc
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

kakfuzz-regex_match_self: $(OBJECTS) match_self.o
	$(CXX) $(LDFLAGS) -o $@ $^

kakfuzz-regex_search_self: $(OBJECTS) search_self.o
	$(CXX) $(LDFLAGS) -o $@ $^

.PHONY: all clean distclean
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
CFLAGS ?= \
    -g -O1 -fsanitize=fuzzer-no-link,address \
    -pedantic -std=c++17 -Wall -Wextra -Wno-unused-parameter -Wno-sign-compare -Wno-address -frelaxed-template-template-args
LDFLAGS ?= -fsanitize=fuzzer,address

all: kakfuzz-for_each_diff_lorem_sentence

clean:
	rm -f $(OBJECTS) for_each_diff_lorem_sentence.o

distclean: clean
	rm -f kakfuzz-for_each_diff_lorem_sentence

%.o: %.cc
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

kakfuzz-for_each_diff_lorem_sentence: $(OBJECTS) for_each_diff_lorem_sentence.o
	$(CXX) $(LDFLAGS) -o $@ $^

.PHONY: all clean distclean
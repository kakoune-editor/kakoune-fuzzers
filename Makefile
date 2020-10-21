##
## Makefile for kakoune-fuzzers
## by lenormf
##

KAKOUNE ?=
ifeq ($(KAKOUNE),)
$(error Please pass the KAKOUNE variable, which must point to the project directory)
endif

FUZZERS ?= regex json

all:
	@for dir in $(FUZZERS); do make -C "$${dir}" KAKOUNE="$(KAKOUNE)" all; done

%: ALWAYS
	@for dir in $(FUZZERS); do make -C "$${dir}" KAKOUNE="$(KAKOUNE)" $@; done

.PHONY: all ALWAYS

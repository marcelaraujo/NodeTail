# My Node.js project
#
SHELL := /bin/bash
NODEJS = $(if $(shell test -f /usr/bin/nodejs && echo "true"),nodejs,node)
CWD := $(shell pwd)
PROJECT = "My Yeap project"

all: clean build test

build:
	@echo "Building ${PROJECT}.....";
	node-gyp clean
	node-gyp configure
	cp binding.gyp ${CWD}/build
	node-gyp build
	
test:
	@echo "Testing ${PROJECT}.....";

clean:
	@echo "Cleaning ${PROJECT}.....";
	node-gyp clean
	rm -Rf build
 
.PHONY: clean compile

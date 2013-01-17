# My Node.js project
#
SHELL := /bin/bash
NODEJS = $(if $(shell test -f /usr/bin/nodejs && echo "true"),nodejs,node)
CWD := $(shell pwd)
PROJECT = "My Yeap project"

all: clean build test

build:
	@echo "Building ${PROJECT}.....";
	@./node_modules/.bin/node-gyp configure
	@./node_modules/.bin/node-gyp build
	
test:
	@echo "Testing ${PROJECT}.....";

clean:
	@echo "Cleaning ${PROJECT}.....";
	@./node_modules/.bin/node-gyp clean
 
.PHONY: clean build
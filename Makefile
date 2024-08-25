CC = gcc
LANG = c
CFLAGS = -g
OUT_FILE = test

default: all

all: build install

test: build run

build: src/main.$(LANG)
	@if [ ! -d bin ]; then mkdir bin; fi
	$(CC) $(CFLAGS) src/main.$(LANG) -o bin/$(OUT_FILE)

install: bin/$(OUT_FILE)
	cp -rf bin/$(OUT_FILE) /usr/bin

uninstall: bin/$(OUT_FILE)
	rm -f /usr/bin/$(OUT_FILE)

run:
	./bin/$(OUT_FILE)

clean veryclean:
	rm -f bin/**


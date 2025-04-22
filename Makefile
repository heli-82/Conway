.PHONY: build run

CC      = gcc
CFLAGS  = 
FILES   = src/main.c

target: 
	mkdir -p $@

build: target
	$(CC) $(CFLAGS) -o target/game_of_life $(FILES)

run: build
	./target/game_of_life
CC := clang++
f = src
cfiles := $(f)/main.cpp $(f)/game.cpp
hfiles := $(f)/game.hpp
files := $(cfiles) $(hfiles) Makefile
out := bin/main
args := -lcursesw -O3 -Wall -Wextra -o $(out)

main: $(files)
	$(CC) $(args) $(cfiles)

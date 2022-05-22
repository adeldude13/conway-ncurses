CC := clang++
cfiles := main.cpp game.cpp
hfiles := game.hpp
files := $(cfiles) $(hfiles) Makefile
out := ../bin/main
args := -lcursesw -O0 -ggdb3 -Wall -Wextra -o $(out)

main: $(files)
	$(CC) $(args) $(cfiles) && ./$(out)

clean:
	rm $(out)

#include <cursesw.h>
#include <iostream>
#include "game.hpp"

int main() {
	setlocale(LC_ALL, "");	
	Game game;
	game.loop();	
	return 0;
}


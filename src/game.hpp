#ifndef GAME
#define GAME
#include <cursesw.h>
#include <vector>

typedef enum {
	STOP,
	NONSTOP,
} State;


class Game {
	public:	
		Game();
		void exit();
		void render();
		void loop();
		void input();
		void INC();
		void DEC();
		int checkLeft(int, int);
		int checkRight(int, int);
		int checkTop(int, int);
		int checkBottom(int, int);
		int x;
		int y;
		std::vector<std::vector<int>> arr;
		int isRunning = 1;
		State state = NONSTOP;
		unsigned short speed = 200;
};

#endif

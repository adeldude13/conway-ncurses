#include "game.hpp"
#include <stdlib.h>
#include <time.h>
#include <cursesw.h>
#include <math.h>

using namespace std;

Game::Game() {
	initscr();
	noecho();
	cbreak();
  nodelay(stdscr, true);
	int x, y;
	srand(time(0));	
	getmaxyx(stdscr, y, x);
	this->y = y;
	this->x = x;
	for(int i=0; i<y; i++) {
		std::vector<int> tmp;	
		for(int j = 0; j<x;j++) {
			float r = (float)(rand())/(float)RAND_MAX;
			tmp.push_back(r > 0.9 ? 1 : 0);
		}
		this->arr.push_back(tmp);
	}
	curs_set(0);
	timeout(400);
}

void Game::exit() {
	endwin();
}

void Game::render() {
	vector<vector<int>> newState = this->arr;
	for(int y=0; y<this->y; y++) {
		for(int x = 0; x<this->x;x++) {
			int right = checkRight(y, x) + checkRight(y+1, x) + checkRight(y-1, x);
			int left = checkLeft(y, x) + checkLeft(y+1, x) + checkLeft(y-1, x);
			int bottom = checkBottom(y, x);
			int top = checkTop(y, x);
			int sum = right + left + bottom + top;
			if(this->arr[y][x] == 1) {
				if(sum < 2) {
					newState[y][x] = 0;
				} else if(sum > 3) {
					newState[y][x] = 0;
				}	
			} else if(sum == 3) {
				newState[y][x] = 1;
			}
		}
	}
	this->arr = newState;
	clear();
	for(int y=0; y<this->y;y++) {
		for(int x = 0; x<this->x;x++) {
			addstr(this->arr[y][x] == 1 ? "▀" : " ");	
		}
	}
	refresh();
}

void Game::input() {
	char c = getch();
	if(c == 'q') this->isRunning = 0;
	if(c == 's') this->state = STOP;
	if(c == '\n') this->state = NONSTOP;
}


/* cheking for neighbors */ 
int Game::checkLeft(int y, int index) {
	if(index - 1 < 0 || y >= this->y || y < 0) return 0;
	return this->arr[y][index-1] == 1;
}

int Game::checkRight(int y, int index) {
	if(index + 1 >= this->x || y >= this->y || y < 0) return 0;
		return this->arr[y][index+1] == 1;
}

int Game::checkTop(int y, int index) {
	if(y - 1 < 0) return 0; 
	return this->arr[y-1][index] == 1;
}

int Game::checkBottom(int y, int index) {
	if(y + 1 >= this->y) return 0; 
	return this->arr[y+1][index] == 1;
}
/* cheking for neighbors */ 


void Game::loop() {
	while(this->isRunning) {
		do {
			this->input();
		} while(this->state == STOP && this->isRunning);
		this->render();

	}
	this->exit();
}



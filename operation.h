#pragma once

#include"acllib.h"
#include"test.h"
#include"PAINT.h"
#include"dlist.h"


struct pos {
	int x;
	int y;
	int flag;
};


struct qipan {
	int qp[9][10];
}Q;

struct qizi {
	int x;
	int y;
	int alive;
}C[120];//1-16 »Æ 101-116 ºì


void init_chess();

int can_move(int x, int y, int selected_x, int selected_y);

void move(int x, int y, int button, int event);
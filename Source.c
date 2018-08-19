#include "acllib.h"
#include<string.h>
#include<math.h>
#include"test.h"
#include"operation.h"
#include"PAINT.h"
#include"dlist.h"


int hhs = 0;//回合数
int noeat = 0;
//int red_j = 0, yel_j = 0;

						   //红1  黄0
						   //车1 马2 象3 士4 将5 士6 象7 马8 车9 炮10 炮11 兵12-16

char huang[17][5] = { "","车","马","象","士","将","士","象","马","车","炮","炮","兵","兵","兵","兵","兵" };
char hong[17][5] = { "","车","马","相","仕","帅","仕","相","马","车","炮","炮","卒","卒","卒","卒","卒" };

struct DList record;//记录详细步骤 供悔棋用


int Setup()
{
	initWindow("全球最大的私人棋盘定制游戏", 500, 0, 800, 600);//黄子先手
	terminal
	init_chess();
	paint_chess();
	registerMouseEvent(move);
	return 0;
}


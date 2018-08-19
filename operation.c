#include"operation.h"

extern int hhs;//回合数
extern int noeat;
//extern int red_j, yel_j;


struct pos selected;//是否选择棋子
DataType tmp;

extern char huang[17][5];
extern char hong[17][5];	

extern struct DList record;

int red_jiangjun();
int yellow_jiangjun();

void init_chess()
{
	memset(Q.qp, 0, sizeof(Q.qp));
	int i;
	for (i = 0; i < 9; i++) {
		Q.qp[i][0] = 100 + i + 1;
		C[Q.qp[i][0]].x = i;
		C[Q.qp[i][0]].y = 0;
		C[Q.qp[i][0]].alive = 1;
		Q.qp[i][9] = i + 1;
		C[Q.qp[i][9]].x = i;
		C[Q.qp[i][9]].y = 9;
		C[Q.qp[i][9]].alive = 1;
		if (i % 2 == 0) {
			Q.qp[i][3] = 100 + i / 2 + 12;
			C[Q.qp[i][3]].x = i;
			C[Q.qp[i][3]].y = 3;
			C[Q.qp[i][3]].alive = 1;
			Q.qp[i][6] = i / 2 + 12;
			C[Q.qp[i][6]].x = i;
			C[Q.qp[i][6]].y = 6;
			C[Q.qp[i][6]].alive = 1;
		}
	}
	Q.qp[1][2] = 110;
	C[Q.qp[1][2]].x = 1;
	C[Q.qp[1][2]].y = 2;
	C[Q.qp[1][2]].alive = 1;
	Q.qp[7][2] = 111;
	C[Q.qp[7][2]].x = 7;
	C[Q.qp[7][2]].y = 2;
	C[Q.qp[7][2]].alive = 1;
	Q.qp[1][7] = 10;
	C[Q.qp[1][7]].x = 1;
	C[Q.qp[1][7]].y = 7;
	C[Q.qp[1][7]].alive = 1;
	Q.qp[7][7] = 11;
	C[Q.qp[7][7]].x = 7;
	C[Q.qp[7][7]].y = 7;
	C[Q.qp[7][7]].alive = 1;

	dlist_init(&record);
}

int can_move(int x, int y, int selected_x, int selected_y)
{
	if (Q.qp[selected_x][selected_y] / 100 == 1) {//红
		if (Q.qp[selected_x][selected_y] % 100 < 10) {
			if (abs(Q.qp[selected_x][selected_y] - 105) == 0) {//将
				if (x >= 3 && x <= 5 && y >= 0 && y <= 2) {
					if (abs(x - selected_x) + abs(y - selected_y) == 1) {
						if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 0)) {
							if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
								noeat = -1;
								//C[Q.qp[x][y]].alive = 0;
							}
							noeat++;
							return 1;
						}
					}
				}
				else if (x >= 3 && x <= 5 && y >= 7 && y <= 9) {
					if (Q.qp[x][y] == 5) {
						if (x == selected_x) {
							int i, flag = 1;
							for (i = selected_y + 1; i < y; i++) {
								if (Q.qp[x][i]) {
									flag = 0;
									break;
								}
							}
							if (flag) {
								noeat = -1;
								//C[Q.qp[x][y]].alive = 0;
								return 1;
							}
						}
					}
				}
			}
			else if (abs(Q.qp[selected_x][selected_y] - 105) == 1) {//士
				if (x >= 3 && x <= 5 && y >= 0 && y <= 2) {
					if (abs(x - selected_x) == 1 && abs(y - selected_y) == 1) {
						if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 0)) {
							if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
								noeat = -1;
								//C[Q.qp[x][y]].alive = 0;
							}
							noeat++;
							return 1;
						}
					}
				}
			}
			else if (abs(Q.qp[selected_x][selected_y] - 105) == 2) {//象
				if (abs(x - selected_x) == 2 && abs(y - selected_y) == 2 && y <= 4) {
					if (x > selected_x&&y > selected_y) {
						if (!Q.qp[selected_x + 1][selected_y + 1]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 0)) {
								if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
					else if (x > selected_x&&selected_y > y) {
						if (!Q.qp[selected_x + 1][selected_y - 1]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 0)) {
								if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
					else if (selected_x > x&&y > selected_y) {
						if (!Q.qp[selected_x - 1][selected_y + 1]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 0)) {
								if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
					else {
						if (!Q.qp[selected_x - 1][selected_y - 1]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 0)) {
								if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
				}
			}
			else if (abs(Q.qp[selected_x][selected_y] - 105) == 3) {//马
				if ((abs(x - selected_x) == 1 && abs(y - selected_y) == 2) || (abs(x - selected_x) == 2 && abs(y - selected_y) == 1)) {
					if (((x - selected_x) == 1 && (y - selected_y == 2)) || ((selected_x - x) == 1 && (y - selected_y) == 2)) {
						if (!Q.qp[selected_x][selected_y + 1]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 0)) {
								if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
					else if (((x - selected_x) == 1 && (selected_y - y) == 2) || ((selected_x - x) == 1 && (selected_y - y) == 2)) {
						if (!Q.qp[selected_x][selected_y - 1]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 0)) {
								if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
					else if (((x - selected_x) == 2 && (y - selected_y == 1)) || ((x - selected_x) == 2 && (selected_y - y) == 1)) {
						if (!Q.qp[selected_x + 1][selected_y]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 0)) {
								if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
					else if (((selected_x - x) == 2 && (y - selected_y == 1)) || ((selected_x - x) == 2 && (selected_y - y) == 1)) {
						if (!Q.qp[selected_x - 1][selected_y]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 0)) {
								if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
				}
			}
			else if (abs(Q.qp[selected_x][selected_y] - 105) == 4) {//车
				if (selected_x == x && selected_y != y) {
					int i, flag = 1;
					if (selected_y > y) {
						for (i = y + 1; i < selected_y; i++) {
							if (Q.qp[x][i]) {
								flag = 0;
								break;
							}
						}
					}
					else {
						for (i = selected_y + 1; i < y; i++) {
							if (Q.qp[x][i]) {
								flag = 0;
								break;
							}
						}
					}
					if (flag) {
						if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 0)) {
							if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
								noeat = -1;
								//C[Q.qp[x][y]].alive = 0;
							}
							noeat++;
							return 1;
						}
					}
				}
				else if (selected_y == y && selected_x != x) {
					int i, flag = 1;
					if (selected_x > x) {
						for (i = x + 1; i < selected_x; i++) {
							if (Q.qp[i][y]) {
								flag = 0;
								break;
							}
						}
					}
					else {
						for (i = selected_x + 1; i < x; i++) {
							if (Q.qp[i][y]) {
								flag = 0;
								break;
							}
						}
					}
					if (flag) {
						if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 0)) {
							if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
								noeat = -1;
								//C[Q.qp[x][y]].alive = 0;
							}
							noeat++;
							return 1;
						}
					}
				}
			}
		}
		else if (Q.qp[selected_x][selected_y] % 100 == 10 || Q.qp[selected_x][selected_y] % 100 == 11) {//炮
			if (selected_x == x && selected_y != y) {
				int i, flag = 0;
				if (selected_y > y) {
					for (i = y + 1; i < selected_y; i++) {
						if (Q.qp[x][i]) {
							flag++;
						}
					}
				}
				else {
					for (i = selected_y + 1; i < y; i++) {
						if (Q.qp[x][i]) {
							flag++;
						}
					}
				}
				if ((!flag && !Q.qp[x][y]) || (flag == 1 && Q.qp[x][y] / 100 == 0 && Q.qp[x][y])) {
					//log("Q.qp[x][y]=%d\n", Q.qp[x][y]);
					if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
						noeat = -1;
						//C[Q.qp[x][y]].alive = 0;
					}
					noeat++;
					return 1;
				}
			}
			else if (selected_y == y && selected_x != x) {
				int i, flag = 0;
				if (selected_x > x) {
					for (i = x + 1; i < selected_x; i++) {
						if (Q.qp[i][y]) {
							flag++;
						}
					}
				}
				else {
					for (i = selected_x + 1; i < x; i++) {
						if (Q.qp[i][y]) {
							flag++;
						}
					}
				}
				if ((!flag && !Q.qp[x][y]) || (flag == 1 && Q.qp[x][y] / 100 == 0 && Q.qp[x][y])) {
					if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
						noeat = -1;
						//C[Q.qp[x][y]].alive = 0;
					}
					noeat++;
					return 1;
				}
			}
		}
		else {//兵
			if (selected_y <= 4) {
				if (x == selected_x && y - selected_y == 1) {
					if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 0)) {
						if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
							noeat = -1;
							//C[Q.qp[x][y]].alive = 0;
						}
						noeat++;
						return 1;
					}
				}
			}
			else {
				if (abs(x - selected_x) + abs(y - selected_y) == 1 && y >= selected_y) {
					if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 0)) {
						if (Q.qp[x][y] && (Q.qp[x][y] / 100 == 0)) {
							noeat = -1;
							//C[Q.qp[x][y]].alive = 0;
						}
						noeat++;
						return 1;
					}
				}
			}
		}
	}
	else {//黄
		if (Q.qp[selected_x][selected_y] % 100 < 10) {
			if (abs(Q.qp[selected_x][selected_y] - 5) == 0) {//将
				if (x >= 3 && x <= 5 && y >= 7 && y <= 9) {
					if (abs(x - selected_x) + abs(y - selected_y) == 1) {
						if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 1)) {
							if (Q.qp[x][y] / 100 == 1) {
								noeat = -1;
								//C[Q.qp[x][y]].alive = 0;
							}
							noeat++;
							return 1;
						}
					}
				}
				else if (x >= 3 && x <= 5 && y >= 0 && y <= 2) {
					if (Q.qp[x][y] == 105) {
						if (x == selected_x) {
							int i, flag = 1;
							for (i = y + 1; i < selected_y; i++) {
								if (Q.qp[x][i]) {
									flag = 0;
									break;
								}
							}
							if (flag) {
								noeat = -1;
								//C[Q.qp[x][y]].alive = 0;
								return 1;
							}
						}
					}
				}
			}
			else if (abs(Q.qp[selected_x][selected_y] - 5) == 1) {//士
				if (x >= 3 && x <= 5 && y >= 7 && y <= 9) {
					if (abs(x - selected_x) == 1 && abs(y - selected_y) == 1) {
						if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 1)) {
							if (Q.qp[x][y] / 100 == 1) {
								noeat = -1;
								//C[Q.qp[x][y]].alive = 0;
							}
							noeat++;
							return 1;
						}
					}
				}
			}
			else if (abs(Q.qp[selected_x][selected_y] - 5) == 2) {//象
				if (abs(x - selected_x) == 2 && abs(y - selected_y) == 2 && y>4) {
					if (x > selected_x&&y > selected_y) {
						if (!Q.qp[selected_x + 1][selected_y + 1]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 1)) {
								if (Q.qp[x][y] / 100 == 1) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
					else if (x > selected_x&&selected_y > y) {
						if (!Q.qp[selected_x + 1][selected_y - 1]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 1)) {
								if (Q.qp[x][y] / 100 == 1) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
					else if (selected_x > x&&y > selected_y) {
						if (!Q.qp[selected_x - 1][selected_y + 1]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 1)) {
								if (Q.qp[x][y] / 100 == 1) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
					else {
						if (!Q.qp[selected_x - 1][selected_y - 1]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 1)) {
								if (Q.qp[x][y] / 100 == 1) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
				}
			}
			else if (abs(Q.qp[selected_x][selected_y] - 5) == 3) {//马
				if ((abs(x - selected_x) == 1 && abs(y - selected_y) == 2) || (abs(x - selected_x) == 2 && abs(y - selected_y) == 1)) {
					if (((x - selected_x) == 1 && (y - selected_y == 2)) || ((selected_x - x) == 1 && (y - selected_y) == 2)) {
						if (!Q.qp[selected_x][selected_y + 1]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 1)) {
								if (Q.qp[x][y] / 100 == 1) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
					else if (((x - selected_x) == 1 && (selected_y - y) == 2) || ((selected_x - x) == 1 && (selected_y - y) == 2)) {
						if (!Q.qp[selected_x][selected_y - 1]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 1)) {
								if (Q.qp[x][y] / 100 == 1) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
					else if (((x - selected_x) == 2 && (y - selected_y == 1)) || ((x - selected_x) == 2 && (selected_y - y) == 1)) {
						if (!Q.qp[selected_x + 1][selected_y]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 1)) {
								if (Q.qp[x][y] / 100 == 1) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
					else if (((selected_x - x) == 2 && (y - selected_y == 1)) || ((selected_x - x) == 2 && (selected_y - y) == 1)) {
						if (!Q.qp[selected_x - 1][selected_y]) {
							if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 1)) {
								if (Q.qp[x][y] / 100 == 1) {
									noeat = -1;
									//C[Q.qp[x][y]].alive = 0;
								}
								noeat++;
								return 1;
							}
						}
					}
				}
			}
			else if (abs(Q.qp[selected_x][selected_y] - 5) == 4) {//车
				if (selected_x == x && selected_y != y) {
					int i, flag = 1;
					if (selected_y > y) {
						for (i = y + 1; i < selected_y; i++) {
							if (Q.qp[x][i]) {
								flag = 0;
								break;
							}
						}
					}
					else {
						for (i = selected_y + 1; i < y; i++) {
							if (Q.qp[x][i]) {
								flag = 0;
								break;
							}
						}
					}
					if (flag) {
						if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 1)) {
							if (Q.qp[x][y] / 100 == 1) {
								noeat = -1;
								//C[Q.qp[x][y]].alive = 0;
							}
							noeat++;
							return 1;
						}
					}
				}
				else if (selected_y == y && selected_x != x) {
					int i, flag = 1;
					if (selected_x > x) {
						for (i = x + 1; i < selected_x; i++) {
							if (Q.qp[i][y]) {
								flag = 0;
								break;
							}
						}
					}
					else {
						for (i = selected_x + 1; i < x; i++) {
							if (Q.qp[i][y]) {
								flag = 0;
								break;
							}
						}
					}
					if (flag) {
						if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 1)) {
							if (Q.qp[x][y] / 100 == 1) {
								noeat = -1;
								//C[Q.qp[x][y]].alive = 0;
							}
							noeat++;
							return 1;
						}
					}
				}
			}
		}
		else if (Q.qp[selected_x][selected_y] % 100 == 10 || Q.qp[selected_x][selected_y] % 100 == 11) {//炮
			if (selected_x == x && selected_y != y) {
				int i, flag = 0;
				if (selected_y > y) {
					for (i = y + 1; i < selected_y; i++) {
						if (Q.qp[x][i]) {
							flag++;
						}
					}
				}
				else {
					for (i = selected_y + 1; i < y; i++) {
						if (Q.qp[x][i]) {
							flag++;
						}
					}
				}
				if ((!flag && !Q.qp[x][y]) || (flag == 1 && Q.qp[x][y] / 100 == 1)) {
					if (Q.qp[x][y] / 100 == 1) {
						noeat = -1;
						//C[Q.qp[x][y]].alive = 0;
					}
					noeat++;
					return 1;
				}
			}
			else if (selected_y == y && selected_x != x) {
				int i, flag = 0;
				if (selected_x > x) {
					for (i = x + 1; i < selected_x; i++) {
						if (Q.qp[i][y]) {
							flag++;
						}
					}
				}
				else {
					for (i = selected_x + 1; i < x; i++) {
						if (Q.qp[i][y]) {
							flag++;
						}
					}
				}
				if ((!flag && !Q.qp[x][y]) || (flag == 1 && Q.qp[x][y] / 100 == 1)) {
					if (Q.qp[x][y] / 100 == 1) {
						noeat = -1;
						//C[Q.qp[x][y]].alive = 0;
					}
					noeat++;
					return 1;
				}
			}
		}
		else {//兵
			if (selected_y >= 5) {
				if (x == selected_x && y - selected_y == -1) {
					if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 1)) {
						if (Q.qp[x][y] / 100 == 1) {
							noeat = -1;
							//C[Q.qp[x][y]].alive = 0;
						}
						noeat++;
						return 1;
					}
				}
			}
			else {
				if (abs(x - selected_x) + abs(y - selected_y) == 1 && y <= selected_y) {
					if (!Q.qp[x][y] || (Q.qp[x][y] / 100 == 1)) {
						if (Q.qp[x][y] / 100 == 1) {
							noeat = -1;
							//C[Q.qp[x][y]].alive = 0;
						}
						noeat++;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

void move(int x, int y, int button, int event)
{
	if (button == LEFT_BUTTON) {
		if (event == BUTTON_UP) {
			if (x >= 25 && x <= 150 && y >= 350 && y <= 400) {//点击重新开始
				init_chess();
				hhs = 0;
				noeat = 0;
				selected.flag = 0;
				paint_chess();
			}
			else if (x >= 25 && x <= 150 && y >= 260 && y <= 310) {//点击悔棋
				if (hhs > 0) {
					hhs--;
					selected.flag = 0;
					tmp = dlist_pop_back(&record);
					log("悔棋成功！\n");
					log("s_x:%d s_y:%d e_x:%d e_y:%d\n", tmp.start_x, tmp.start_y, tmp.end_x, tmp.end_y);
					Q.qp[tmp.start_x][tmp.start_y] = Q.qp[tmp.end_x][tmp.end_y];
					Q.qp[tmp.end_x][tmp.end_y] = tmp.end_qz;
					C[Q.qp[tmp.start_x][tmp.start_y]].x = tmp.start_x;
					C[Q.qp[tmp.start_x][tmp.start_y]].y = tmp.start_y;
					if (tmp.end_qz) {
						C[tmp.end_qz].alive = 1;
					}
					noeat = tmp.start_noeat;
					paint_chess();
				}
			}
		}
	}
	if (C[5].alive&&C[105].alive&&noeat <= 60) {//选中
		if (button == LEFT_BUTTON) {
			if (event == BUTTON_UP) {
				int qp_X, qp_Y;
				qp_X = (x - 175) / 50;
				qp_Y = (y - 50) / 50;
				log("x=%d y=%d qp_X=%d qp_Y=%d\n", x, y, qp_X, qp_Y);
				//log("((Q.qp[qp_X][qp_Y] / 100) % 2) == (hhs % 2)&& Q.qp[qp_X][qp_Y]?%s\n", ((Q.qp[qp_X][qp_Y] / 100) % 2) == (hhs % 2) && Q.qp[qp_X][qp_Y] ? "true" : "false");
				//log("Q.qp[qp_X][qp_Y]=%d\n", Q.qp[qp_X][qp_Y]);
				if (qp_X >= 0 && qp_X <= 9 && qp_Y >= 0 && qp_Y <= 10) {
					if (((Q.qp[qp_X][qp_Y] / 100) % 2) == (hhs % 2) && Q.qp[qp_X][qp_Y]) {
						selected.x = qp_X;
						selected.y = qp_Y;
						selected.flag = 1;
						paint_chess();

						tmp.start_x = qp_X;
						tmp.start_y = qp_Y;
						tmp.start_qz = Q.qp[qp_X][qp_Y];
						tmp.start_noeat = noeat;
					}
					else {
						;
					}
				}
				else {
					;
				}
			}
		}
		if (button == RIGHT_BUTTON) {//移动
			if (event == BUTTON_UP) {
				if (selected.flag) {
					int qp_X, qp_Y;
					qp_X = (x - 175) / 50;
					qp_Y = (y - 50) / 50;
					log("selected.x=%d selected.y=%d qp_X=%d qp_Y=%d\n", selected.x, selected.y, qp_X, qp_Y);
					if (qp_X >= 0 && qp_X <= 9 && qp_Y >= 0 && qp_Y <= 10) {
						if (can_move(qp_X, qp_Y,selected.x,selected.y)) {
							log("can move.\n");
							//selected.flag = 0;
							//del_chess(selected.x, selected.y);
							//beginPaint();
							//setBrushColor(BLUE);
							//ellipse(qp_X * 50 + 175, qp_Y * 50 + 50, qp_X * 50 + 225, qp_Y * 50 + 100);
							////selected.flag = 1;
							//endPaint();
							tmp.end_qz = Q.qp[qp_X][qp_Y];
							tmp.end_x = qp_X;
							tmp.end_y = qp_Y;
							tmp.end_noeat = noeat;
							log("tmp:  start_x=%d start_y=%d end_x=%d end_y=%d\n", tmp.start_x, tmp.start_y, tmp.end_x, tmp.end_y);
							dlist_push_back(&record, tmp);
							log("record.tail:  start_x=%d start_y=%d end_x=%d end_y=%d\n", record.tail->data.start_x, record.tail->data.start_y, record.tail->data.end_x, record.tail->data.end_y);
							selected.flag = 0;

							if (Q.qp[qp_X][qp_Y]) {
								C[Q.qp[qp_X][qp_Y]].alive = 0;
							}
							Q.qp[qp_X][qp_Y] = Q.qp[selected.x][selected.y];
							Q.qp[selected.x][selected.y] = 0;
							C[Q.qp[qp_X][qp_Y]].x = qp_X;
							C[Q.qp[qp_X][qp_Y]].y = qp_Y;
							hhs++;
							paint_chess();
							if (red_jiangjun()) {
								log("黄方被将！\n");
								beginPaint();
								setPenColor(BLACK);
								setTextSize(30);
								paintText(10, 460, "将军");	
								endPaint();
							}
							if (yellow_jiangjun()) {
								log("红方被将！\n");
								beginPaint();
								setPenColor(BLACK);
								setTextSize(30);
								paintText(90, 460, "将军");
								endPaint();
							}
						}
						else {
							log("cannot move.\n");
						}
					}
				}
			}
		}
	}
}

int red_jiangjun() {
	int i,flag=0;
	for (i = 101; i < 117; i++) {
		if (C[i].alive) {
			if (can_move(C[5].x, C[5].y, C[i].x, C[i].y)) {
				flag = 1;
				break;
			}
		}
	}
	/*if (flag) {
		red_j++;
	}
	else {
		red_j = 0;
	}*/
	return flag;
}

int yellow_jiangjun() {
	int i, flag = 0;
	for (i = 1; i < 17; i++) {
		if (C[i].alive) {
			selected.x = C[i].x;
			selected.y = C[i].y;
			if (can_move(C[105].x, C[105].y, C[i].x, C[i].y)) {
				flag = 1;
				break;
			}
		}
	}
	/*if (flag) {
		yel_j++;
	}
	else {
		yel_j = 0;
	}*/
	return flag;
}
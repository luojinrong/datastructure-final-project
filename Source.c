#include "acllib.h"
#include<string.h>
#include<math.h>
#include"test.h"
#include"operation.h"
#include"PAINT.h"
#include"dlist.h"


int hhs = 0;//�غ���
int noeat = 0;
//int red_j = 0, yel_j = 0;

						   //��1  ��0
						   //��1 ��2 ��3 ʿ4 ��5 ʿ6 ��7 ��8 ��9 ��10 ��11 ��12-16

char huang[17][5] = { "","��","��","��","ʿ","��","ʿ","��","��","��","��","��","��","��","��","��","��" };
char hong[17][5] = { "","��","��","��","��","˧","��","��","��","��","��","��","��","��","��","��","��" };

struct DList record;//��¼��ϸ���� ��������


int Setup()
{
	initWindow("ȫ������˽�����̶�����Ϸ", 500, 0, 800, 600);//��������
	terminal
	init_chess();
	paint_chess();
	registerMouseEvent(move);
	return 0;
}


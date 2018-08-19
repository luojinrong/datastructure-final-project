#include"PAINT.h"

extern int hhs;//�غ���
extern int noeat;


extern struct pos selected;

extern char huang[17][5];
extern char hong[17][5];



void paint_fzx()//������
{
	setPenColor(BLUE);
	int i;
	for (i = 0; i < 800; i += 50) {
		line(0, i, 800, i);
		line(i, 0, i, 800);
	}
}

void paint_chess()
{

	beginPaint();
	clearDevice();
	//paint_fzx();//
	paint_tips();
	paint_chessboard();
	int i;
	for (i = 101; i < 117; i++) {
		setBrushColor(RED);
		setTextColor(BLACK);
		setTextSize(40);
		setTextBkColor(EMPTY);
		if (C[i].alive) {
			ellipse(175 + C[i].x * 50, 50 + C[i].y * 50, 225 + C[i].x * 50, 100 + C[i].y * 50);
			paintText(180 + C[i].x * 50, 55 + C[i].y * 50, hong[i % 100]);
		}
	}
	for (i = 1; i < 17; i++) {
		setBrushColor(YELLOW);
		if (C[i].alive) {
			ellipse(175 + C[i].x * 50, 50 + C[i].y * 50, 225 + C[i].x * 50, 100 + C[i].y * 50);
			paintText(180 + C[i].x * 50, 55 + C[i].y * 50, huang[i % 100]);
		}
	}

	endPaint();

}

void paint_tips()
{
	//beginPaint();//��ʾ��
	setTextBkColor(WHITE);
	setTextColor(BLACK);
	setTextSize(25);
	paintText(300, 12, "��ӭ�����й�����");
	setTextSize(10);
	paintText(0, 0, "�ʶ���Ϸ����������");
	paintText(250, 560, "���Ʋ�����Ϸ���ܾ�������Ϸ��ע�����ұ�����������ƭ�ϵ���");
	paintText(250, 575, "�ʶ���Ϸ���ԣ�������Ϸ����������ʱ�䣬���ܽ������");
	setTextSize(15);

	paintText(0, 30, "��ǰ�غ�����");
	char str[10];
	int huihe = hhs, i = 0;
	while (huihe != 0) {
		str[i++] = huihe % 10 + '0';
		huihe /= 10;
	}


	str[i] = 0;
	for (i = 0; i < strlen(str) / 2; i++) {
		char temp = str[i];
		str[i] = str[strlen(str) - i - 1];
		str[strlen(str) - i - 1] = temp;
	}
	paintText(180, 30, str);
	if (str[0] == 0) {
		paintText(180, 30, "0");
	}

	paintText(630, 50, "�������");
	paintText(630, 70, "����ֱ·��̤б");
	paintText(630, 90, "��������ڴ��");
	paintText(630, 110, "ʿ��б·������");
	paintText(630, 130, "С��һȥ������");
	paintText(630, 170, "��Ϸ�淨��");
	paintText(630, 190, "������ѡ������");
	paintText(630, 210, "����Ҽ�ѡ���ƶ�");
	paintText(630, 250, "��Ϸ������ʽ��");
	paintText(630, 270, "һ������");
	paintText(630, 290, "����60�غ�δ��������");
	paintText(630, 400, "bug��������:");
	paintText(630, 420, "��ϵQQ:840841939");
	paintText(630, 440, "��ϵ��:�޽���");

	paintText(0, 50, "��ǰѡ������");

	paintText(0, 240, "����Ի���");
	setPenColor(BLACK);
	line(25, 260, 150, 260);
	line(25, 260, 25, 310);
	line(150, 260, 150, 310);
	line(25, 310, 150, 310);
	setTextSize(20);
	paintText(67, 275, "����");

	setTextSize(15);
	paintText(0, 330, "��������¿�ʼ��Ϸ");
	setPenColor(BLACK);
	line(25, 350, 150, 350);
	line(25, 350, 25, 400);
	line(150, 350, 150, 400);
	line(25, 400, 150, 400);
	setTextSize(20);
	paintText(47, 365, "���¿�ʼ");
	setBrushColor(BLACK);
	rectangle(0, 70, 150, 220);
	setTextSize(15);
	paintText(0, 430, "�����ж�");
	setBrushColor(RED);
	rectangle(0, 450, 80, 500);
	setBrushColor(YELLOW);
	rectangle(80, 450, 160, 500);
	if (C[5].alive&&C[105].alive&&noeat <= 60) {
		if (hhs % 2 == 0) {
			setBrushColor(YELLOW);
		}
		else {
			setBrushColor(RED);
		}
		ellipse(50, 120, 100, 170);
		if (selected.flag) {
			if (Q.qp[selected.x][selected.y] > 100) {
				setTextColor(BLACK);
				setTextSize(40);
				setTextBkColor(EMPTY);
				paintText(55, 125, hong[Q.qp[selected.x][selected.y] % 100]);
			}
			else if (Q.qp[selected.x][selected.y] > 0 && Q.qp[selected.x][selected.y] < 100) {
				setTextColor(BLACK);
				setTextSize(40);
				setTextBkColor(EMPTY);
				paintText(55, 125, huang[Q.qp[selected.x][selected.y] % 100]);
			}
		}
	}
	else if (!C[5].alive&&C[105].alive&&noeat <= 60) {
		setTextColor(RED);
		setTextSize(30);
		setTextBkColor(EMPTY);
		paintText(15, 130, "�췽��ʤ");
	}
	else if (C[5].alive && !C[105].alive&&noeat <= 60) {
		setTextColor(YELLOW);
		setTextSize(30);
		setTextBkColor(EMPTY);
		paintText(15, 130, "�Ʒ���ʤ");
	}
	else if (C[5].alive&&C[105].alive&&noeat > 60) {
		setTextColor(WHITE);
		setTextSize(30);
		setTextBkColor(EMPTY);
		paintText(15, 130, "˫��ƽ��");
	}
	//endPaint();
}

void paint_chessboard()
{
	//beginPaint();//��������
	setBrushColor(BLACK);
	rectangle(175, 50, 625, 550);
	setPenColor(WHITE);
	line(350, 75, 450, 175);//б��
	line(350, 175, 450, 75);
	line(350, 425, 450, 525);
	line(350, 525, 450, 425);
	int i, j;
	for (i = 200; i <= 600; i += 50) {//����
		if (i == 200 || i == 600) {
			line(i, 75, i, 525);
		}
		else {
			line(i, 75, i, 275);
			line(i, 325, i, 525);
		}
	}
	for (i = 75; i <= 525; i += 50) {//����
		line(200, i, 600, i);
	}
	for (i = 200; i <= 500; i += 100) {
		line(i + 5, 210, i + 5, 220);
		line(i + 5, 220, i + 15, 220);
		line(i + 5, 230, i + 5, 240);
		line(i + 5, 230, i + 15, 230);
		line(i + 5, 360, i + 5, 370);
		line(i + 5, 370, i + 15, 370);
		line(i + 5, 380, i + 5, 390);
		line(i + 5, 380, i + 15, 380);
	}
	for (i = 300; i <= 600; i += 100) {
		line(i - 5, 210, i - 5, 220);
		line(i - 15, 220, i - 5, 220);
		line(i - 5, 230, i - 5, 240);
		line(i - 15, 230, i - 5, 230);
		line(i - 5, 360, i - 5, 370);
		line(i - 15, 370, i - 5, 370);
		line(i - 5, 380, i - 5, 390);
		line(i - 15, 380, i - 5, 380);
	}
	for (j = 175; j <= 425; j += 250) {
		for (i = 250; i <= 550; i += 300) {
			line(i - 5, j - 15, i - 5, j - 5);
			line(i - 15, j - 5, i - 5, j - 5);
			line(i + 5, j - 15, i + 5, j - 5);
			line(i + 5, j - 5, i + 15, j - 5);
			line(i - 15, j + 5, i - 5, j + 5);
			line(i - 5, j + 5, i - 5, j + 15);
			line(i + 5, j + 5, i + 15, j + 5);
			line(i + 5, j + 5, i + 5, j + 15);
		}
	}
	setTextBkColor(BLACK);
	setTextColor(WHITE);
	setTextSize(30);
	paintText(260, 285, "��");
	paintText(310, 285, "��");
	paintText(460, 285, "��");
	paintText(510, 285, "��");
	//endPaint();
}
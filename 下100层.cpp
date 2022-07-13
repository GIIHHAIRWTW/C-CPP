#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<easyx.h>
#include<time.h>
#pragma comment(lib,"winmm.lib")


#define MAX_BOARD 11   //��������

struct Player
{
	int x;
	int y;
	int r;//�뾶
	int index;//��ҵ�ǰ���ڰ����±�
	int vy;//y�᷽���ٶȱ仯��
	COLORREF color;//��ɫ
};

void player_init(Player* py, int x, int y, int r)
{
	py->x = x;
	py->y = y-r;
	py->r = r;
	py->index = -1;
	py->vy = 1;
	py->color = RGB(rand() % 256, rand() % 256, rand() % 256);
}

void player_draw(Player* py)
{
	setfillcolor(py->color);
	solidcircle(py->x, py->y, py->r);

}

//��������ƶ�
void player_key_ctrl(Player* py)
{
	//��ȡ���̰���
	if (GetAsyncKeyState(VK_LEFT))  //�������
	{
		py->x -= 3;
	}
	if (GetAsyncKeyState(VK_RIGHT))  //�Ҽ�����
	{
		py->x += 3;
	}
}

//���ӣ����꣬��ȣ��߶�
struct Board
{
	int x;
	int y;
	int w;
	int h;
	COLORREF color;
};

void board_init(Board* b, int x, int y, int w)
{
	b->x = x;
	b->y = y;
	b->w = w;
	b->h = 10;  //�߶ȹ̶�
	b->color = RGB(rand() % 256, rand() % 256, rand() % 256);
}

void board_draw(Board* b)
{
	setfillcolor(b->color);
	//���ƾ���
	solidroundrect(b->x, b->y, b->x + b->w, b->y + b->h, 5, 5);

}

void board_move(Board* b)
{
	b->y -= 1;
}

Player player;  //���
Board board[MAX_BOARD];  //��������
void init()
{
	//��ʼ������
	for (int i = 0; i < MAX_BOARD; i++)
	{
		int w = 50 + rand() % 100;//[50,150)
		int x = rand() % (getwidth() - w); //[0,760]
		if (i == 0)
		{
			board[i].y = 100;
		}
		else
		{
			board[i].y = board[i-1].y + 60;
		}
		board_init(board + i, x, board[i].y, w);
	}
	//��ʼ�����
	int x = board[0].x + rand() % (board->w) - player.r;
	player_init(&player,x , board[0].y, 10);
}

void draw()
{
	player_draw(&player);
	for (int i = 0; i < MAX_BOARD; i++)
	{
		board_draw(board + i);
	}
}

void update()
{
	for (int i = 0; i < MAX_BOARD; i++)
	{
		board_move(board + i);
		if (board[i].y + board[i].h <= 0)
		{
			board[i].y = MAX_BOARD * 60;

			int w = 50 + rand() % 100;//[50,150)
			int x = rand() % (getwidth() - w); //[0,760]
			board_init(board + i, x, board[i].y, w);
		}
	}
	Sleep(10);
}

//�������Ű��Ӷ�
void fllow_move()
{
	//ȷ��λ��(���ĸ�������)
	for (int i = 0; i < MAX_BOARD; i++)
	{
		if (player.x > board[i].x && player.x <= board[i].x + board[i].w &&
			player.y + player.r >= board[i].y - 5 && player.y + player.r <= board[i].y + 5)
		{
			player.index = i;  //��¼���ڰ����±�
			break;
		}
		else
		{
			//���ڰ�����
			player.index = -1;
		}
	}

	if (player.index == -1)
	{
		//���ڰ����ϣ�����,�ٶ��𽥱��
		player.y += player.vy;
		if (player.vy < 10)
		{
			player.vy++;
		}
	}
	else
	{
		player.vy = 1; //�����ٶȱ仯
		//�ڰ����ϣ���������ƶ�
		player.y = board[player.index].y - player.r;
	}
}

int main()
{
	initgraph(760, 640);
	//�������������
	srand(time(NULL));

	//���������ɫ
	//setfillcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
	//����ͼ��
	//solidrectangle(10, 10, 10 + 20, 10 + 20);

	init();
	draw();
	PlaySound(L"go.wav", NULL, SND_ASYNC | SND_FILENAME);
	Sleep(1000);


	while (true)
	{
		BeginBatchDraw();//˫����
		cleardevice();//����
		draw();
		EndBatchDraw();//����˫����

		//���ݸ���
		update();
		if (player.y >= 640 || player.y <= 0)
		{
			closegraph();
		}
		fllow_move();
		player_key_ctrl(&player);
	}
	printf("Game Over!");
	return 0;
}
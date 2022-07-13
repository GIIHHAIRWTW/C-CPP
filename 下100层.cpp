#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<easyx.h>
#include<time.h>
#pragma comment(lib,"winmm.lib")


#define MAX_BOARD 11   //板子数量

struct Player
{
	int x;
	int y;
	int r;//半径
	int index;//玩家当前所在板子下标
	int vy;//y轴方向速度变化量
	COLORREF color;//颜色
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

//控制玩家移动
void player_key_ctrl(Player* py)
{
	//获取键盘按键
	if (GetAsyncKeyState(VK_LEFT))  //左键按下
	{
		py->x -= 3;
	}
	if (GetAsyncKeyState(VK_RIGHT))  //右键按下
	{
		py->x += 3;
	}
}

//板子，坐标，宽度，高度
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
	b->h = 10;  //高度固定
	b->color = RGB(rand() % 256, rand() % 256, rand() % 256);
}

void board_draw(Board* b)
{
	setfillcolor(b->color);
	//绘制矩形
	solidroundrect(b->x, b->y, b->x + b->w, b->y + b->h, 5, 5);

}

void board_move(Board* b)
{
	b->y -= 1;
}

Player player;  //玩家
Board board[MAX_BOARD];  //板子数组
void init()
{
	//初始化板子
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
	//初始化玩家
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

//让球随着板子动
void fllow_move()
{
	//确定位置(在哪个板子上)
	for (int i = 0; i < MAX_BOARD; i++)
	{
		if (player.x > board[i].x && player.x <= board[i].x + board[i].w &&
			player.y + player.r >= board[i].y - 5 && player.y + player.r <= board[i].y + 5)
		{
			player.index = i;  //记录所在扳子下标
			break;
		}
		else
		{
			//不在板子上
			player.index = -1;
		}
	}

	if (player.index == -1)
	{
		//不在板子上，下落,速度逐渐变快
		player.y += player.vy;
		if (player.vy < 10)
		{
			player.vy++;
		}
	}
	else
	{
		player.vy = 1; //重置速度变化
		//在板子上，跟随板子移动
		player.y = board[player.index].y - player.r;
	}
}

int main()
{
	initgraph(760, 640);
	//设置随机数种子
	srand(time(NULL));

	//设置填充颜色
	//setfillcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
	//绘制图形
	//solidrectangle(10, 10, 10 + 20, 10 + 20);

	init();
	draw();
	PlaySound(L"go.wav", NULL, SND_ASYNC | SND_FILENAME);
	Sleep(1000);


	while (true)
	{
		BeginBatchDraw();//双缓冲
		cleardevice();//清屏
		draw();
		EndBatchDraw();//结束双缓冲

		//数据更新
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
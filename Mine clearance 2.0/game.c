#include"game.h"

int success(char show[ROWS][COLS])
{
	int i = 1;
	int j = 1;
	int win = 0;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			if (show[i][j] == '*')
			{
				win++;

			}
		}
	}
	return win;
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y] +
		mine[x + 1][y - 1] +
		mine[x + 1][y + 1]- 8 * '0';
}

void Open(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int count = get_mine_count(mine, x, y);
	if (count == 0)
	{
		show[x][y] = ' ';
		int i = 0;
		int j = 0;
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (show[i][j] == '*' && i > 0 && i < 10 && j > 0 && j < 10)
					Open(mine, show, i, j);
			}
		}
	}
	else
	{
		show[x][y] = count + '0';

	}
}




void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = Easy_Count;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < Easy_Count + 1)
	{
		printf("请输入要排查的坐标:>");

		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else if (show[x][y] != '*')
			{
				printf("选择重复，请重选\n");
			}
			else
			{
				Open(mine, show, x, y);
				DisplayBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("输入非法坐标，请重新输入\n");

		}

		if (success(show) == Easy_Count)
		{
			printf("你赢了\n");
			break;
		}
	}

}


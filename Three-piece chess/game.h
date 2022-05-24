#define _CRT_SECURE_NO_WARNINGS 1

#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//츠
void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL],int row,int col);

//玩家赢-'*'
//电脑赢-'#'
//틱애-'Q'
//셨崎-'C'

char IsWin(char board[ROW][COL], int row, int col);

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

#define BOMB 30  //炸弹

#define ROWS 12		//行
#define COLUMNS 12	//列

#define ROW ROWS-2		//行
#define COLUMN COLUMNS-2	//列

int interface1(); //界面
void intreface2(char ch[][6]); //绘制界面

void game();  //游戏主体

void initialization(char ch[][COLUMNS], char set);  //给数组初始化

void chessboard(char ch[][COLUMNS]); //打印棋盘

void layout(char ch[ROWS][COLUMNS], int row, int column, int count); //布置地雷

int check(char arr1[ROWS][COLUMNS], char arr2[ROWS][COLUMNS]);	//排查雷

void chain(int i, int j, char arr1[ROWS][COLUMN], char arr2[ROWS][COLUMNS]);		//连锁

int detection(int i, int j, char arr1[ROWS][COLUMNS], char arr2[ROWS][COLUMNS]);
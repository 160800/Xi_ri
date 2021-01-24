#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

#define row 10       //行
#define column 10		//列

void interface1();  //界面

int game();		//游戏

void map(char arr[][column]);	//绘制地图

int player(char arr[][column],char* p);  //玩家

int rule1(char* p,int i,int j);			//上规则
int rule2(char* p, int i, int j);			//下规则
int rule3(char* p, int i, int j);			//左规则
int rule4(char* p, int i, int j);			//右规则

int victory(char* p,int* x,int* y,int count); //胜利条件
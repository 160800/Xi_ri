#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

#define BOMB 20  //ը��

#define ROWS 12		//��
#define COLUMNS 12	//��

#define ROW ROWS-2		//��
#define COLUMN COLUMNS-2	//��

int interface1(); //����
void intreface2(char ch[][6]); //���ƽ���

void game();  //��Ϸ����

void initialization(char ch[][COLUMNS], char set);  //�������ʼ��

void chessboard(char ch[][COLUMNS]); //��ӡ����

void layout(char ch[ROWS][COLUMNS],int row ,int column,int count); //���õ���

int check(char arr1[ROWS][COLUMNS], char arr2[ROWS][COLUMNS]);	//�Ų���
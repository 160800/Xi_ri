#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

#define row 10       //��
#define column 10		//��

void interface1();  //����

int game();		//��Ϸ

void map(char arr[][column]);	//���Ƶ�ͼ

int player(char arr[][column],char* p);  //���

int rule1(char* p,int i,int j);			//�Ϲ���
int rule2(char* p, int i, int j);			//�¹���
int rule3(char* p, int i, int j);			//�����
int rule4(char* p, int i, int j);			//�ҹ���

int victory(char* p,int* x,int* y,int count); //ʤ������
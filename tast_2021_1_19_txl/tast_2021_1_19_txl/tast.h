#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 100		//�ṹ���ģ


enum content       //Ŀ¼
{
	Quit,			//�˳�
	Add_friends,		//��Ӻ���
	Delete_friend,	//ɾ������
	Examine,			//�鿴����
	Modification		//�޸���Ϣ
};

struct Stu
{
	char name[20];  //����
	char sex[4];    //�Ա�
	short age;	   //����
	char phone[12]; //�绰

};


void Interface(); //����

void add(struct Stu* p,int* Num);  //��Ӻ���

void del(struct Stu* p, int* Num);		//ɾ������

void exa(const struct Stu *p,const int* Num);  //�鿴����

void mod(struct Stu *p, int* Num);
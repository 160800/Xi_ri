#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 100		//结构体规模


enum content       //目录
{
	Quit,			//退出
	Add_friends,		//添加好友
	Delete_friend,	//删除好友
	Examine,			//查看好友
	Modification		//修改信息
};

struct Stu
{
	char name[20];  //名称
	char sex[4];    //性别
	short age;	   //年龄
	char phone[12]; //电话

};


void Interface(); //界面

void add(struct Stu* p,int* Num);  //添加好友

void del(struct Stu* p, int* Num);		//删除好友

void exa(const struct Stu *p,const int* Num);  //查看好友

void mod(struct Stu *p, int* Num);
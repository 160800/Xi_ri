#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;  //重命名

typedef struct Seqlist
{
	SLDataType* a;
	int size;        //储存有效数据
	int capacity;		//容量
}SL;

void SeqListInit(SL* ps); //初始化

void SeqListCapacity(SL* ps);  //内存不够，扩容

void SeqListprint(const SL* ps); //打印

void SeqListPushBack(SL* ps, SLDataType x); //尾插

void SeqListPopBack(SL* ps);//尾删

void SeqListPushFront(SL* ps, SLDataType x); //头插

void SeqListPopFront(SL* ps);//头删

void SeqListInsert(SL* ps, int pos, SLDataType x); //任意插入  //pos要插入的位置

void SeqListDelete(SL* ps, int pos);//任意位置删除   //pos要删除的位置
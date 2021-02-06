#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;  //������

typedef struct Seqlist
{
	SLDataType* a;
	int size;        //������Ч����
	int capacity;		//����
}SL;

void SeqListInit(SL* ps); //��ʼ��

void SeqListCapacity(SL* ps);  //�ڴ治��������

void SeqListprint(const SL* ps); //��ӡ

void SeqListPushBack(SL* ps, SLDataType x); //β��

void SeqListPopBack(SL* ps);//βɾ

void SeqListPushFront(SL* ps, SLDataType x); //ͷ��

void SeqListPopFront(SL* ps);//ͷɾ

void SeqListInsert(SL* ps, int pos, SLDataType x); //�������  //posҪ�����λ��

void SeqListDelete(SL* ps, int pos);//����λ��ɾ��   //posҪɾ����λ��
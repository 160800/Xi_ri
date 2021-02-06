#include"SeqLIst.h"

void SeqListprint(const SL* ps) //��ӡ
{
	int i = 0;

	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}

void SeqListInit(SL* ps) //��ʼ��
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType)* 4); //�����ڴ� 16�ֽ� SLDataType��int 4�ֽ�

	if (ps->a == NULL)
	{

		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}

	ps->size = 0;
	ps->capacity = 4;

}

void SeqListCapacity(SL* ps) //����
{
	assert(ps);

	if (ps->size >= ps->capacity) //�ڴ��������������
	{
		ps->capacity *= 2; //����2���ռ䣬��ֹ���������ڴ�
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*ps->capacity);

		if (NULL == ps->a) //���ݼ��
		{
			printf("����ռ�ʧ��\n");
			exit(-1);
		}
	}
}

void SeqListPushBack(SL* ps, SLDataType x) //β��
{

	SeqListCapacity(ps); //����

	ps->a[ps->size] = x; //size�������Ч���ݾ������һ��
	ps->size++;
}

void SeqListPopBack(SL* ps) //βɾ
{

	if (ps->size > 0) //����С���㣬������-1�ͻ������
	{
		ps->size--;
	}
}

void SeqListPushFront(SL*ps, SLDataType x) //ͷ����
{
	int i = 0;
	SLDataType* tmp = NULL;

	SeqListCapacity(ps); //����

	ps->size++; //������Ч����

	for (i = 0; i < ps->size; i++)
	{
		tmp = ps->a[ps->size - i];   //����
		ps->a[ps->size - i] = ps->a[ps->size - i - 1];
		ps->a[ps->size - i - 1] = tmp;
	}

	ps->a[0] = x; //ͷ��������
}

void SeqListPopFront(SL* ps)//ͷɾ
{
	SLDataType* tmp = NULL;

	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		tmp = ps->a[i];  //����
		ps->a[i] = ps->a[i + 1];
		ps->a[i + 1] = tmp;
	}
	ps->size--; //ɾ��-1��
}

void SeqListInsert(SL* ps, int pos, SLDataType x) //�м����
{
	SeqListCapacity(ps); //�������

	SLDataType* tmp = NULL;
	int i = 0;
	if (pos > 0 && pos <= ps->size) //�жϲ���λ���Ƿ����
	{
		pos--; //�û����������ܴ�0��ʼ��

		ps->size++; //�����Ҫ��һ��λ��

		for (i = 0; i < ps->size - pos; i++) //��������
		{
			tmp = ps->a[ps->size - i]; //����
			ps->a[ps->size - i] = ps->a[ps->size - i - 1];
			ps->a[ps->size - i - 1] = tmp;

		}
		ps->a[pos] = x; //����Ҫ�����λ��
	}
	else
	{
		printf("�����λ������\n");
	}
}

void SeqListDelete(SL* ps, int pos) //�м�ɾ��
{
	SLDataType* tmp = NULL;
	int i = 0;

	if (pos > 0 && pos <= ps->size) //�ж�ɾ��λ���Ƿ����
	{
		pos--; //�û����������ܴ�0��ʼ��

		for (i = 0; i < ps->size - pos; i++)
		{
			tmp = ps->a[pos + i]; //����
			ps->a[pos + i] = ps->a[pos + 1 + i];
			ps->a[pos + 1 + i] = tmp;
		}

		ps->size--; //��Ч����ɾ��  ��ɾ��
	}
}
//�жϴ�С�˵Ķ��ְ취

//ָ���жϷ�
/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 1;

	char* ch = (char*)&a;

	if (*ch == a)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}

	system("pause");
	return 0;
}
*/

//�������жϷ�
/*
#include<stdio.h>
#include<stdlib.h>

union
{
	int a;
	char b;

}c = {1};

int main()
{
	if (c.a == c.b)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}

	system("pause");
	return 0;
}
*/
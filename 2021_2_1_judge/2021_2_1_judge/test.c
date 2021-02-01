//判断大小端的多种办法

//指针判断法
/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 1;

	char* ch = (char*)&a;

	if (*ch == a)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}

	system("pause");
	return 0;
}
*/

//联合体判断法
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
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}

	system("pause");
	return 0;
}
*/
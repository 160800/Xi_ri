//关机倒计时
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

int main()
{


	system("shutdown -s -t 100");

	char ch[20] = "";

	while (1)
	{
		printf("输入“我是猪”，解除关机\n");
		scanf("%s", &ch);
		int a = strcmp(ch, "我是猪");
		if (0 == a)
		{
			printf("YES\n");
			system("shutdown -a");
			break;
		}
		else
		{
			printf("NO\n");
		}

	}

	system("pause");
	return 0;
}
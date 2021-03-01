#include"tast.h"

int main()
{
	system("shutdown -s -t 600");

	int input = 1; //初始化为1，为后面循环铺路，输入

	while (input)
	{
		input = interface1();
		switch (input)
		{
		case 1:
		{
				  game();
		}break;
		case 0:
		{
				  printf("\n\t退出成功\n\n");
		}break;
		}
	}
	system("pause");
	return 0;
}

interface1() //界面
{
	char ch[2][6] =
	{
		' ', ' ', ' ', '-', '>', ' ',
		' ', ' ', ' ', ' ', ' ', ' ',
	};
	int input = 1;

	int a = 1;

	intreface2(ch);  //绘制界面

	while (input)
	{
		//		_getch();
		input = _getch(); //输入
		system("cls");
		switch (input)
		{
		case 72:		//上箭头
		{
							ch[0][3] = '-';
							ch[0][4] = '>';
							ch[1][3] = ' ';
							ch[1][4] = ' ';
							a = 1;

		}break;
		case 80:		//下箭头
		{
							ch[0][3] = ' ';
							ch[0][4] = ' ';
							ch[1][3] = '-';
							ch[1][4] = '>';
							a = 2;
		}break;
		case 13:		//回车
		{
							if (1 == a)
							{
								return 1;
							}
							else if (2 == a)
							{
								return 0;
							}
		}

		}
		intreface2(ch); //绘制界面
	}
	return 0;
}

void intreface2(char ch[][6])//绘制界面
{
	static int a = 0;
	if (a == 0)
	{
		printf("请在十分钟内通关，否则自动关机\n");
		a++;
	}

	printf("*********************\n");
	int i = 0;
	int j = 0;
	for (i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			printf("*");
		}
		else
		{
			printf("*");
		}
		for (j = 0; j < 6; j++)
		{
			printf("%c", ch[i][j]);
		}
		if (i == 0)
		{
			printf("开始游戏     *");
		}
		else
		{
			printf("结束游戏     *");
		}
		printf("\n");
	}
	printf("*********************\n");
}
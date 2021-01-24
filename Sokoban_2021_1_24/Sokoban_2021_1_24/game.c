﻿#include"tast.h"

void interface1()   //界面
{
	printf("********************\n");
	printf("*      推箱子      *\n");
	printf("********************\n");
	printf("*    1.开始游戏    *\n");
	printf("********************\n");
	printf("*    0.退出游戏    *\n");
	printf("********************\n");
}

int game()	//游戏
{
/*	char arr[row][column] = 
	{
	//   0    1     2    3    4    5    6    7    8    9    10    11   12   13  14   15   16   17   18   19
		'+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+',// 0
		'+', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',// 1
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',// 2
		'+', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', '+',// 3
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',// 4
		'+', ' ', ' ', ' ', 'O', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', '+',// 5
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', '+',// 6
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',// 7
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',// 8
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',// 9
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',// 10
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',// 11
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',// 12
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',// 13
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',// 14
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',// 15
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',// 16
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',// 17
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',// 18
		'+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+', '+',// 19
	};  //创建数组*/

	char arr[row][column] =
	{
		'+', '+', '+', '+', '+', '+', '+', '+', '+', '+',
		'+', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', '+',
		'+', 'X', '+', ' ', ' ', ' ', ' ', 'O', ' ', '+',
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',
		'+', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', '+',
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',
		'+', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '+',
		'+', ' ', ' ', ' ', '+', 'O', '+', 'O', ' ', '+',
		'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+',
		'+', '+', '+', '+', '+', '+', '+', '+', '+', '+',
	};

	//‘+’是墙体■，‘O’是箱子▓，‘X’是目标处○，‘*’是人♀，

	char arr1[row][column]; //复制1份
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			arr1[i][j] = arr[i][j];
		}
	}

	int ch1[20];	//存储X目标点20份
	int ch2[20];

	for (i = 0; i < 20; i++) //初始化
	{
		ch1[i] = 0;
		ch2[i] = 0;
	}

	int k = 0;

	int count = 0; //计‘X’有多少个
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (arr1[i][j] == 'X')
			{
				ch1[k] = i;
				ch2[k] = j;
				count++;
				k++;
			}
		}
	}

	map(arr);	//绘制地图

	int input = 1;

	while (input)
	{
		input = player(arr, arr);	//玩家
		if (input == 0)
		{
			break;
		}
		system("cls");
		input = victory(arr,ch1,ch2,count);  //胜利条件
		map(arr);
						
	}
	printf("\n返回主页面，");
	system("pause");
}

void map(char arr[][column])		//绘制地图
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (arr[i][j] == '+')
			{
				printf("■");
			}
			else if (arr[i][j] == ' ')
			{
				printf("  ");
			}
			else if (arr[i][j] == 'O')
			{
				printf("▓");
			}
			else if (arr[i][j] == '*')
			{
				printf("♀");
			}
			else if (arr[i][j] == 'X')
			{
				printf("○");
			}
		}
		printf("\n");
	}
}

int player(char arr[][column],char* p) //找到玩家位置
{
	int count = 1;

	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (arr[i][j] == '*')
			{
				break;
			}
		}
		if (arr[i][j] == '*')
		{
			break;
		}
	}


	while (count)
	{
//		_getch; //上下左右需要读取2次
		char k = _getch(); 
		switch (k)
		{
			case 27:		//输入esc
			{	
				return 0;	//跳出函数
			}break;
			case 72:
			{		
				if ((*(p + (((i - 1) * column) + j))) != '+')//判断上方墙体
				{
					if ((*(p + (((i - 1) * column) + j))) != 'O') //判断上方有没有箱子
					{
						*(p + (((i - 1) * column) + j)) = '*';		//向上走
						*(p + ((i * column) + j)) = ' '; //清除
						count = 0;	//跳出循环
					}
					else if (rule1(p, i, j) == 1)
					{

						*(p + (((i - 1) * column) + j)) = '*';		//向上走
						*(p + ((i * column) + j)) = ' '; //清除
						count = 0;	//跳出循环
					}
				}
			}break;
		case 80:
			{
				if ((*(p + (((i + 1) * column) + j))) != '+')//判断下方墙体
				{
					if ((*(p + (((i + 1) * column) + j))) != 'O') //判断下方有没有箱子
					{
						*(p + (((i + 1) * column) + j)) = '*';		//向下走
						*(p + ((i * column) + j)) = ' '; //清除
						count = 0;	//跳出循环
					}
					else if (rule2(p, i, j) == 1)
					{

						*(p + (((i + 1) * column) + j)) = '*';		//向下走
						*(p + ((i * column) + j)) = ' '; //清除
						count = 0;	//跳出循环
					}
				}
		}break;
			case 75:
			{
				if ((*(p + ((i * column) + (j - 1))) != '+'))//不能走向墙体
				{
					if ((*(p + ((i * column) + (j - 1))) != 'O'))
					{
						*(p + ((i * column) + (j - 1))) = '*';		//向左走
						*(p + ((i * column) + j)) = ' '; //清除
						count = 0;	//跳出循环
					}
					else if (rule3(p, i, j) == 1)
					{
						*(p + ((i * column) + (j - 1))) = '*';		//向左走
						*(p + ((i * column) + j)) = ' '; //清除
						count = 0;	//跳出循环
					}
				}
			}break;
		case 77:
			{
				if ((*(p + ((i * column) + (j + 1)))) != '+')//不能走向墙体
				{
					if ((*(p + ((i * column) + (j + 1))) != 'O'))
					{
						*(p + ((i * column) + (j + 1))) = '*';		//向右走
						*(p + ((i * column) + j)) = ' '; //清除
						count = 0;	//跳出循环
					}
					else if (rule4(p, i, j) == 1)
					{
						*(p + ((i * column) + (j + 1))) = '*';		//向右走
						*(p + ((i * column) + j)) = ' '; //清除
						count = 0;	//跳出循环
					}
				}
			}break;
		default:
			{
				   count = 1;//继续循环
			}
		}
	}


	printf("%d\n",count);
	
}

int rule1(char* p,int i,int j)	//上规则
{
	int count = 1;
	
	if ((*(p + (((i - 1) * column) + j))) == 'O' && (*(p + (((i - 2) * column) + j))) != 'O')//判断有没有箱子
	{
		if (((*(p + (((i - 2) * column) + j))) != '+'))//判断有没有墙
		{
			(*(p + (((i - 2) * column) + j))) = 'O';
			return 1;
		}
	}

}

int rule2(char* p, int i, int j)	//下规则
{
	int count = 1;

	if ((*(p + (((i + 1) * column) + j))) == 'O' && (*(p + (((i + 2) * column) + j))) != 'O')
	{
		if ((*(p + (((i + 2) * column) + j))) != '+')//判断有没有墙
		{
			(*(p + (((i + 2) * column) + j))) = 'O';
			return 1;
		}
	}
}

int rule3(char* p, int i, int j)	//左规则
{
	int count = 1;

	if ((*(p + ((i * column) + (j - 1)))) == 'O' && (*(p + ((i * column) + (j - 2)))) != 'O')
	{
		if ((*(p + ((i * column) + (j - 2)))) != '+')
		{
			(*(p + ((i * column) + (j - 2)))) = 'O';
			return 1;
		}
	}
}

int rule4(char* p, int i, int j)	//右规则
{
	int count = 1;

	if ((*(p + ((i * column) + (j + 1)))) == 'O' && (*(p + ((i * column) + (j + 2)))) != 'O')
	{
		if ((*(p + ((i * column) + (j + 2)))) != '+')
		{
			(*(p + ((i * column) + (j + 2)))) = 'O';
			return 1;
		}
	}
}

int victory(char* p,int* x,int* y,int count)
{
	int a = 0;	//次数
	int i = 0;
	for (i = 0; i < count; i++)
	{
		if ((*(p + ((*(x+i)) * column) + (*(y+i)))) == ' ') //检查X是否为空格
		{
			(*(p + ((*(x + i)) * column) + (*(y+i)))) = 'X';
		}
	}

	for (i = 0; i < count; i++)
	{
		if ((*(p + ((*(x + i)) * column) + (*(y + i)))) == ' ') //检查X是否为空格
		{
			(*(p + ((*(x + i)) * column) + (*(y + i)))) = 'X';
		}
	}

	for (i = 0; i < count; i++)
	{
		if ((*(p + ((*(x + i)) * column) + (*(y + i)))) == 'O') //检查X是否为空格
		{
			a++;
		}
	}
	if (a == count)
	{
		printf("\n\t\t胜利\n\n");
		return 0;
	}

}
#include"tast.h"

void game() //游戏主体结构
{
	srand((unsigned)time(NULL));
	char arr1[ROWS][COLUMNS];	//创建2个数组
	char arr2[ROWS][COLUMNS];

	initialization(arr1,'0'); //给数组初始化
	initialization(arr2,'*');

	layout(arr1, ROW, COLUMN, BOMB);//布置地雷

		int input = 1;
		while (input)
		{
			system("cls");
			chessboard(arr1);   //作弊打开
			chessboard(arr2);
			
			input = check(arr1, arr2);//排查雷		
		}

	printf("返回菜单，");
	system("pause");
	system("cls");
}

void initialization(char ch[][COLUMNS], char set)//给棋盘初始化
{
	int i = 0;
	int j = 0;

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLUMNS; j++)
		{
			ch[i][j] = set;
		}
	}
}

void chessboard(char ch[][COLUMNS]) //打印棋盘
{
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 1; i <= ROW; i++)
	{
		for (; k <= ROW; k++)
		{
			printf("%2d ",k);
			if (k == ROW)
			printf("\n");
		}
		
		printf("  +--+--+--+--+--+--+--+--+--+--+\n");
		printf("%2d", i);
		printf("|");
		for (j =1 ; j <= COLUMN; j++)
		{
			if (ch[i][j] == '*')
			{
				printf("■|", ch[i][j]);
			}
			else
			printf("%-2c|", ch[i][j]);
		}
		printf("\n");
	}
	printf("  +--+--+--+--+--+--+--+--+--+--+\n\n\n");
}

void layout(char ch[ROWS][COLUMNS],int row,int column,int count)//布置地雷
{
	while (count)
	{
		int x = (rand() % row)+1;
		int y = (rand() % column)+1;
		if (ch[x][y] == '0')
		{
			ch[x][y] = '1';
			count--;
		}
	}
}

int check(char arr1[ROWS][COLUMNS], char arr2[ROWS][COLUMNS])	//排查雷
{
	int i = 0;
	int j = 0;
	int count = 0;
	static int count1 = 0;

	printf("->"); 
	scanf("%d %d",&i,&j);

	if (arr1[i][j] == '0')
	{
		if (arr1[i-1][j- 1] == '1')
			count++;
		if(arr1[i - 1][j] == '1')
			count++;
		if(arr1[i - 1][j + 1] == '1')
			count++;
		if(arr1[i][j - 1] == '1')
			count++;
		if (arr1[i][j + j] == '1')
			count++;
		if(arr1[i + 1][j - 1] == '1')
			count++;
		if(arr1[i + 1][j] == '1')
			count++;
		if(arr1[i + 1][j + 1] == '1')
			count++;
		printf("%d\n",count);
		arr2[i][j] = count+48;
		count1++;
	}
	else if (arr1[i][j] == '1')
	{
		chessboard(arr1);
		printf("\n\t失败\n\n");
		system("pause");
		return 0;
	}
	if (count1 == ((ROW)*(COLUMN)) - (BOMB))
	{
		printf("\n\t胜利\n\n");
		return 0;
	}
}
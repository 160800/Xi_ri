#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HANG 3
#define SU 3

void yxjm()
{
	printf("********************\n");
	printf("*      ������      *\n");
	printf("********************\n");
	printf("***1.��Ϸ��ʼ*******\n");
	printf("***2.�˳���Ϸ*******\n");
	printf("********************\n");
}

void qipan(char arr[][SU])
{
	int i = 0;
	int j = 0;

	int count = 1;
	printf("\n");
	printf("    1   2   3  \n");
	for (i = 0; i < HANG; i++)
	{
		printf("  +---+---+---+\n");
		printf("%d |", count);
		count++;
		for (j = 0; j < SU; j++)
		{

			printf(" %c |", arr[i][j]);
		}
		printf("\n");
	}
	printf("  +---+---+---+\n\n");
}

void xiaqi1(char arr[][SU])
{
	int a = 0;
	int b = 0;
	printf("��������->");
	while (scanf_s("%d %d", &a, &b))
	{
		if (HANG >= a&&a > 0 && SU >= b&&b > 0)
		{
			if (arr[a - 1][b - 1] == ' ')
			{
				arr[a - 1][b - 1] = '*';
				break;
			}
			else
			{
				qipan(arr);
				printf("\n���̱�ռ��,��������->");
			}
		}
		else
		{
			qipan(arr);
			printf("\n��������,��������->");
		}
	}
}

void xiaqi2(char arr[][SU])
{
	int a = 0;
	int b = 0;

	printf("��������->");

	while (~scanf_s("%d %d", &a, &b))
	{
		if (HANG >= a&&a > 0 && SU >= b&&b > 0)
		{
			if (arr[a - 1][b - 1] == ' ')
			{
				arr[a - 1][b - 1] = 'O';
				break;
			}
			else
			{
				qipan(arr);
				printf("\n���̱�ռ��,��������->");
			}
		}
		else
		{
			qipan(arr);
			printf("\n��������,��������->");
		}
	}
}


int guize(char arr[][SU])
{
	int i = 0;
	int j = 0;

	int count = 0;

	for (i = 0; i < HANG; i++)
	{
		for (j = 0; j < SU; j++)
		{
			if (arr[i][j] != ' ')
			{
				count++;
			}
		}
	}

	if (count == 9)
	{
		printf("     ƽ��\n");
		return 1;
	}


	for (i = 0; i < HANG; i++)
	{
		if (arr[i][0] != ' '&&arr[i][1] != ' '&&arr[i][2] != ' ') //��ʤ������
		{
			if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2])
			{
				if (arr[i][0] == '*')
				{
					printf("      *ʤ��\n\n");
					return 2;  //��ʾʤ��
				}
				else
				{
					printf("      Oʤ��\n\n");
					return 3;
				}
			}
		}

		if (arr[0][i] != ' '&&arr[1][i] != ' '&&arr[2][i] != ' ') //��ʤ������
		{
			if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])
			{
				if (arr[i][0] == '*')
				{
					printf("      *ʤ��\n\n");
					return 2;  //��ʾʤ��
				}
				else
				{
					printf("      Oʤ��\n\n");
					return 3;
				}
			}
		}

	}

	//  0 0	0 1	0 2
	//  1 0  1 1 1 2
	//  2 0  2 1 2 2


	for (i = 0; i < HANG - 2; i++)
	{
		if (arr[i][i] != ' '&&arr[i + 1][i + 1] != ' '&&arr[i + 2][i + 2] != ' ')   //б��ʤ������
		{
			if (arr[i][i] == arr[i + 1][i + 1] && arr[i][i] == arr[i + 2][i + 2])
			{
				if (arr[1][1] == '*')
				{
					printf("      *ʤ��\n\n");
					return 2;  //��ʾʤ��
				}
				else
				{
					printf("      Oʤ��\n\n");
					return 3;
				}
			}
		}

		if (arr[i + 2][i] != ' '&&arr[i + 1][i + 1] != ' '&&arr[i][i + 2] != ' ')  //��б��ʤ������
		{
			if (arr[i + 2][i] == arr[i + 1][i + 1] && arr[i + 1][i + 1] == arr[i][i + 2])
			{
				if (arr[1][1] == '*')
				{
					printf("      *ʤ��\n\n");
					return 2;  //��ʾʤ��
				}
				else
				{
					printf("      Oʤ��\n\n");
					return 3;
				}
			}
		}
	}




	count = 0;
	return 0;
}


void yx()
{
	char arr[HANG][SU] = { ' ' };
	memset(arr, ' ', sizeof(arr));
	int i = 0;

	qipan(arr);
	while (1)
	{

		xiaqi1(arr);
		qipan(arr);
		int a = guize(arr);

		if (a == 1)
		{
			qipan(arr);
			break;
		}
		else if (a == 2)
		{
			break;
		}
		else if (a == 3)
		{
			break;
		}



		xiaqi2(arr);
		qipan(arr);
		a = guize(arr);

		if (a == 1)
		{
			break;
		}
		else if (a == 2)
		{
			break;
		}
	}



}



int main()
{

	int a1 = 0;

	while (1)
	{
		yxjm();
		scanf_s("%d", &a1);
		if (a1 == 1)
		{
			yx();
		}
		else if (a1 == 2)
		{
			return 0;
		}
		else
		{
			printf("����������\n");
		}
	}

	system("pause");
	return 0;
}
#include"tast.h"

void game() //��Ϸ����ṹ
{
	srand((unsigned)time(NULL));
	char arr1[ROWS][COLUMNS];	//����2������
	char arr2[ROWS][COLUMNS];

	initialization(arr1, '0'); //�������ʼ��    ���ӻ�����
	initialization(arr2, '*'); //����

	layout(arr1, ROW, COLUMN, BOMB);//���õ���

	int input = 1;
	while (input)
	{
		system("cls");
//		chessboard(arr1);   //���״�
		chessboard(arr2);

		input = check(arr1, arr2);//�Ų���		
	}

	printf("���ز˵���");
	system("pause");
	system("cls");
}

void initialization(char ch[][COLUMNS], char set)//�����̳�ʼ��
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

void chessboard(char ch[][COLUMNS]) //��ӡ����
{
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 1; i <= ROW; i++)
	{
		for (; k <= ROW; k++)
		{
			printf("%2d ", k);
			if (k == ROW)
				printf("\n");
		}

		printf("  +--+--+--+--+--+--+--+--+--+--+\n");
		printf("%2d", i);
		printf("|");
		for (j = 1; j <= COLUMN; j++)
		{
			if (ch[i][j] == '*')
			{
				printf("��|", ch[i][j]);
			}
			else
				printf("%-2c|", ch[i][j]);
		}
		printf("\n");
	}
	printf("  +--+--+--+--+--+--+--+--+--+--+\n\n\n");
}

void layout(char ch[ROWS][COLUMNS], int row, int column, int count)//���õ���
{
	while (count)
	{
		int x = (rand() % row) + 1;
		int y = (rand() % column) + 1;
		if (ch[x][y] == '0')
		{
			ch[x][y] = '1';
			count--;
		}
	}
}

int check(char arr1[ROWS][COLUMNS], char arr2[ROWS][COLUMNS])	//�Ų���
{
	int i = 0;
	int j = 0;
	int count = 0;
	static int count1 = 0;  //ʤ������

	printf("->");
	scanf("%d %d", &i, &j);

	chain(i, j, arr1, arr2); //����

	if (arr1[i][j] == '0')
	{
		if (arr1[i - 1][j - 1] == '1') //����
		{
			count++;
		}

		if (arr1[i - 1][j] == '1') //��
		{
			count++;
		}

		if (arr1[i - 1][j + 1] == '1') //����
		{
			count++;
		}

		if (arr1[i][j - 1] == '1') //��
		{
			count++;
		}

		if (arr1[i][j + 1] == '1') //��
		{
			count++;
		}

		if (arr1[i + 1][j - 1] == '1') //����
		{
			count++;
		}

		if (arr1[i + 1][j] == '1') //��
		{
			count++;
		}

		if (arr1[i + 1][j + 1] == '1') //����
		{
			count++;
		}

		arr2[i][j] = count + 48;
		count1++;
	}
	else if (arr1[i][j] == '1')
	{
		chessboard(arr1);
		printf("\n\tʧ��\n\n");
		system("pause");
		return 0;
	}
	else
	{
		return 1;
	}

	if (count1 == ((ROW)*(COLUMN)) - (BOMB))  //ʤ������
	{

		printf("\n\tʤ��,�ѽ��\n\n");
		system("shutdown -a");
		return 0;
	}
}

int detection(int i, int j, char arr1[ROWS][COLUMNS], char arr2[ROWS][COLUMNS]) //��鸽��
{
	int count = 0;

	if (arr1[i - 1][j - 1] == '1') //����
	{
		count++;
	}

	if (arr1[i - 1][j] == '1') //��
	{
		count++;
	}

	if (arr1[i - 1][j + 1] == '1') //����
	{
		count++;
	}

	if (arr1[i][j - 1] == '1') //��
	{
		count++;
	}

	if (arr1[i][j + 1] == '1') //��
	{
		count++;
	}

	if (arr1[i + 1][j - 1] == '1') //����
	{
		count++;
	}

	if (arr1[i + 1][j] == '1') //��
	{
		count++;
	}

	if (arr1[i + 1][j + 1] == '1') //����
	{
		count++;
	}

	return count;
}

void chain(int i, int j, char arr1[][COLUMNS], char arr2[][COLUMNS]) //i��j��¼ԭʼλ��
{
	int count = 0;

	if (i > 0 && i < ROWS && j>0 && j < COLUMNS)
	{
		char count = detection(i, j, arr1, arr2);
		if (count == 0)
		{
			arr2[i][j] = '0';

			if (arr2[i - 1][j] == '*') //���ϼ��
			{
				//			arr2[i - 1][j] = detection(i - 1, j, arr1, arr2) + 48; //��鸽��
				chain(i - 1, j, arr1, arr2);
			}


			if (arr2[i][j - 1] == '*') //������
			{
				//	arr2[i][j - 1] = detection(i - 1, j, arr1, arr2) + 48; //��鸽��
				chain(i, j - 1, arr1, arr2);
			}

			if (arr2[i][j + 1] == '*') //���Ҽ��
			{
				////	arr2[i][j + 1] = detection(i - 1, j, arr1, arr2) + 48; //��鸽��
				chain(i, j + 1, arr1, arr2);
			}

			if (arr2[i + 1][j] == '*') //���¼��
			{
				//	arr2[i + 1][j] = detection(i - 1, j, arr1, arr2) + 48; //��鸽��
				chain(i + 1, j, arr1, arr2);
			}

		}
		else
		{
			arr2[i][j] = count + 48;
		}
	}

}
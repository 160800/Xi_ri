#include"tast.h"

int main()
{
	system("shutdown -s -t 600");

	int input = 1; //��ʼ��Ϊ1��Ϊ����ѭ����·������

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
				  printf("\n\t�˳��ɹ�\n\n");
		}break;
		}
	}
	system("pause");
	return 0;
}

interface1() //����
{
	char ch[2][6] =
	{
		' ', ' ', ' ', '-', '>', ' ',
		' ', ' ', ' ', ' ', ' ', ' ',
	};
	int input = 1;

	int a = 1;

	intreface2(ch);  //���ƽ���

	while (input)
	{
		//		_getch();
		input = _getch(); //����
		system("cls");
		switch (input)
		{
		case 72:		//�ϼ�ͷ
		{
							ch[0][3] = '-';
							ch[0][4] = '>';
							ch[1][3] = ' ';
							ch[1][4] = ' ';
							a = 1;

		}break;
		case 80:		//�¼�ͷ
		{
							ch[0][3] = ' ';
							ch[0][4] = ' ';
							ch[1][3] = '-';
							ch[1][4] = '>';
							a = 2;
		}break;
		case 13:		//�س�
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
		intreface2(ch); //���ƽ���
	}
	return 0;
}

void intreface2(char ch[][6])//���ƽ���
{
	static int a = 0;
	if (a == 0)
	{
		printf("����ʮ������ͨ�أ������Զ��ػ�\n");
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
			printf("��ʼ��Ϸ     *");
		}
		else
		{
			printf("������Ϸ     *");
		}
		printf("\n");
	}
	printf("*********************\n");
}
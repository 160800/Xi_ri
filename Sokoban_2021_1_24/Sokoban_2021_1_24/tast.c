#include"tast.h"

int main()
{
	int input = 1;  //����
	
	interface1();
	printf("ѡ��->");

	while (input)
	{
		scanf("%d", &input);
		switch (input)
		{
			case 1:
			{
				getchar();		//����������س�
				system("cls");
				game();    //��Ϸ
				system("cls");  //����
				interface1();		//����
				printf("ѡ��->");
			}break;
			case 0:
			{
				printf("�˳�\n");
			}break;
			default:
			{
				printf("��������->");
			}break;
		}
	}
	system("pause");
	return 0;
}
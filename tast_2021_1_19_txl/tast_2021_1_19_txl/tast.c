#include"tast.h"

int main()
{
	int input = 0;  //����

	struct Stu st[size];
	int sz = sizeof(st);	//����st�ṹ���С
	int Num = 0;		//��������
	memset(st,0,sz);		//��ʼ��
	Interface(); //����
	do
	{
		printf("����->");
		scanf("%d", &input);
		switch (input)
		{
			case Add_friends :	//��Ӻ���
			{
				add(st,&Num);
				Interface(); //����
			}break;
			case Delete_friend:	//ɾ������
			{
				del(&st,&Num);
				Interface(); //����
			}break;
			case Examine:			//�鿴
			{
				exa(st, &Num);

			}break;
			case Modification:	//�޸�
			{
				mod(&st, &Num);
				Interface(); //����
			}break;
			case Quit:			//�˳�
			{
				printf("�˳�\n");
			}break;
			default :
			{
				Interface(); //����
				printf("������");
			}
		}

	} while (input);

	 
	system("pause");
	return 0;
}
#include"tast.h"

void Interface() //����
{
	printf("********************\n");
	printf("*    1.��Ӻ���    *\n");
	printf("*    2.ɾ������    *\n");
	printf("*    3.�鿴����    *\n");
	printf("*    4.�޸���Ϣ    *\n");
	printf("*    0.�˳�        *\n");
	printf("********************\n");

}

void add(struct Stu* p,int* Num)	//��Ӻ���
{
	if (*Num >= size)
	{
		printf("��������\n");
	}
	else
	{
		printf("\n����->");
		scanf("%s",(p+(*Num))->name);
		printf("�Ա�->");
		scanf("%s", (p + (*Num))->sex);
		printf("����->");
		scanf("%hd", &(p + (*Num))->age);
		printf("�绰->");
		scanf("%s", (p + (*Num))->phone);
		printf("��Ӻ��ѳɹ�\n");
		(*Num) ++;
	}

}

void exa(const struct Stu *p,const int* Num)	//�鿴����
{
	int i = 0;
	printf("*************************************\n");
	printf("*%-8s*%-7s*%-5s*%-12s*\n", "����:","�Ա�:","����:","�绰:");
	
	for (i = 0; i < *Num; i++)
	{
		printf("*************************************\n");
		printf("*%-8s*%-7s*%-5hd*%-12s*\n", (p + i)->name, (p + i)->sex, (p + i)->age, (p + i)->phone);
	}

	printf("*************************************\n");

}

void del(struct Stu* p, int* Num)		//ɾ������
{
	int a = 1;
	char name[20] = "";

	printf("��������ɾ��->");

	scanf("%s",&name);

	int i = 0;
	for (i = 0; i < *Num; i++)
	{
		a = strcmp((p+i)->name,name);
			if(0 ==  a)
				break;
	}

	int j = 0;

	if (a == 0)
	{
		printf("����ɾ��\n");
		int b = strlen((p + i)->name);//����
		memset((p + i)->name, 0, b);

		b = strlen((p + i)->sex);
		memset((p + i)->sex, 0, b);

		(p + i)->age = 0;

		b = strlen((p + i)->phone);
		memset((p + i)->phone, 0, b);


		memcpy((p + i)->name,(p + (*Num - 1))->name,20);//�滻
		memcpy((p + i)->sex,(p + (*Num - 1))->sex,4);
		(p + i)->age = (p + (*Num - 1))->age;
		memcpy((p + i)->phone,(p + (*Num - 1))->phone,12);

		*Num -= 1;
		printf("ɾ���ɹ�\n");
	}
	else
	{
		printf("û���ҵ�\n");
	}

}

void mod(struct Stu *p, int* Num)	//�޸���Ϣ
{
	int i = 0;
	int sz = 1;

	char ch[20] = "";

	printf("���������޸���Ϣ->");
	scanf("%s",&ch);

	for (i = 0; i < (*Num); i++)
	{
		sz = strcmp((p+i)->name,ch);
		if (0 == sz)
		{
			break;
		}
	}

	if (0 == sz)
	{
		printf("\n����->");
		scanf("%s", (p + i)->name);
		printf("�Ա�->");
		scanf("%s", (p + i)->sex);
		printf("����->");
		scanf("%hd", &(p + i)->age);
		printf("�绰->");
		scanf("%s", (p + i)->phone);
		printf("�޸ĳɹ�\n");
	}
	else
	{
		printf("û���ҵ�\n");
	}
}
#include"SeqList.h"

int main()
{
	SL s;

	SeqListInit(&s); //��ʼ��

	SeqListPushBack(&s, 1); //β��
	SeqListPushBack(&s, 2); //β��
	SeqListPushBack(&s, 3); //β��
	SeqListPushBack(&s, 4); //β��
	SeqListPushBack(&s, 5); //β���5�����ݵ�ʱ���Ѿ�������

	SeqListprint(&s); // ��ӡ
	printf("β����������\n"); //����

	SeqListPopBack(&s);//βɾ

	SeqListprint(&s); // ��ӡ
	printf("βɾһ��ɾ��\n"); //����

	SeqListInsert(&s, 3, 20); //����λ�ò���

	SeqListprint(&s); // ��ӡ
	printf("����λ�ò���\n");

	SeqListDelete(&s, 2); //����λ��ɾ��

	SeqListprint(&s); // ��ӡ
	printf("����λ��ɾ��\n");

	system("pause");
	return 0;
}
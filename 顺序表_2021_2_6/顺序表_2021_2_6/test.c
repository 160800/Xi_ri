#include"SeqList.h"

int main()
{
	SL s;

	SeqListInit(&s); //初始化

	SeqListPushBack(&s, 1); //尾插
	SeqListPushBack(&s, 2); //尾插
	SeqListPushBack(&s, 3); //尾插
	SeqListPushBack(&s, 4); //尾插
	SeqListPushBack(&s, 5); //尾插第5个数据的时候已经扩容了

	SeqListprint(&s); // 打印
	printf("尾插两个数据\n"); //换行

	SeqListPopBack(&s);//尾删

	SeqListprint(&s); // 打印
	printf("尾删一个删除\n"); //换行

	SeqListInsert(&s, 3, 20); //任意位置插入

	SeqListprint(&s); // 打印
	printf("任意位置插入\n");

	SeqListDelete(&s, 2); //任意位置删除

	SeqListprint(&s); // 打印
	printf("任意位置删除\n");

	system("pause");
	return 0;
}
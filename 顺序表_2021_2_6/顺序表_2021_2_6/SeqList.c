#include"SeqLIst.h"

void SeqListprint(const SL* ps) //打印
{
	int i = 0;

	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}

void SeqListInit(SL* ps) //初始化
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType)* 4); //开辟内存 16字节 SLDataType是int 4字节

	if (ps->a == NULL)
	{

		printf("申请内存失败\n");
		exit(-1);
	}

	ps->size = 0;
	ps->capacity = 4;

}

void SeqListCapacity(SL* ps) //扩容
{
	assert(ps);

	if (ps->size >= ps->capacity) //内存如果不够就扩容
	{
		ps->capacity *= 2; //提升2被空间，防止不断申请内存
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*ps->capacity);

		if (NULL == ps->a) //扩容检查
		{
			printf("申请空间失败\n");
			exit(-1);
		}
	}
}

void SeqListPushBack(SL* ps, SLDataType x) //尾插
{

	SeqListCapacity(ps); //扩容

	ps->a[ps->size] = x; //size是最大有效数据就是最后一行
	ps->size++;
}

void SeqListPopBack(SL* ps) //尾删
{

	if (ps->size > 0) //不能小于零，否则变成-1就会出问题
	{
		ps->size--;
	}
}

void SeqListPushFront(SL*ps, SLDataType x) //头插入
{
	int i = 0;
	SLDataType* tmp = NULL;

	SeqListCapacity(ps); //扩容

	ps->size++; //增加有效数据

	for (i = 0; i < ps->size; i++)
	{
		tmp = ps->a[ps->size - i];   //交换
		ps->a[ps->size - i] = ps->a[ps->size - i - 1];
		ps->a[ps->size - i - 1] = tmp;
	}

	ps->a[0] = x; //头插入数据
}

void SeqListPopFront(SL* ps)//头删
{
	SLDataType* tmp = NULL;

	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		tmp = ps->a[i];  //交换
		ps->a[i] = ps->a[i + 1];
		ps->a[i + 1] = tmp;
	}
	ps->size--; //删除-1；
}

void SeqListInsert(SL* ps, int pos, SLDataType x) //中间插入
{
	SeqListCapacity(ps); //检查扩容

	SLDataType* tmp = NULL;
	int i = 0;
	if (pos > 0 && pos <= ps->size) //判断插入位置是否合理
	{
		pos--; //用户心理，不可能从0开始想

		ps->size++; //插入就要加一个位置

		for (i = 0; i < ps->size - pos; i++) //互换次数
		{
			tmp = ps->a[ps->size - i]; //交换
			ps->a[ps->size - i] = ps->a[ps->size - i - 1];
			ps->a[ps->size - i - 1] = tmp;

		}
		ps->a[pos] = x; //插入要插入的位置
	}
	else
	{
		printf("插入的位置有误\n");
	}
}

void SeqListDelete(SL* ps, int pos) //中间删除
{
	SLDataType* tmp = NULL;
	int i = 0;

	if (pos > 0 && pos <= ps->size) //判断删除位置是否合理
	{
		pos--; //用户心理，不可能从0开始想

		for (i = 0; i < ps->size - pos; i++)
		{
			tmp = ps->a[pos + i]; //交换
			ps->a[pos + i] = ps->a[pos + 1 + i];
			ps->a[pos + 1 + i] = tmp;
		}

		ps->size--; //有效数据删除  假删除
	}
}
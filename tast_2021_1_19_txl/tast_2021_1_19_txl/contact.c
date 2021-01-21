#include"tast.h"

void Interface() //界面
{
	printf("********************\n");
	printf("*    1.添加好友    *\n");
	printf("*    2.删除好友    *\n");
	printf("*    3.查看好友    *\n");
	printf("*    4.修改信息    *\n");
	printf("*    0.退出        *\n");
	printf("********************\n");

}

void add(struct Stu* p,int* Num)	//添加好友
{
	if (*Num >= size)
	{
		printf("好友已满\n");
	}
	else
	{
		printf("\n姓名->");
		scanf("%s",(p+(*Num))->name);
		printf("性别->");
		scanf("%s", (p + (*Num))->sex);
		printf("年龄->");
		scanf("%hd", &(p + (*Num))->age);
		printf("电话->");
		scanf("%s", (p + (*Num))->phone);
		printf("添加好友成功\n");
		(*Num) ++;
	}

}

void exa(const struct Stu *p,const int* Num)	//查看好友
{
	int i = 0;
	printf("*************************************\n");
	printf("*%-8s*%-7s*%-5s*%-12s*\n", "姓名:","性别:","年龄:","电话:");
	
	for (i = 0; i < *Num; i++)
	{
		printf("*************************************\n");
		printf("*%-8s*%-7s*%-5hd*%-12s*\n", (p + i)->name, (p + i)->sex, (p + i)->age, (p + i)->phone);
	}

	printf("*************************************\n");

}

void del(struct Stu* p, int* Num)		//删除好友
{
	int a = 1;
	char name[20] = "";

	printf("搜索名字删除->");

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
		printf("正在删除\n");
		int b = strlen((p + i)->name);//清零
		memset((p + i)->name, 0, b);

		b = strlen((p + i)->sex);
		memset((p + i)->sex, 0, b);

		(p + i)->age = 0;

		b = strlen((p + i)->phone);
		memset((p + i)->phone, 0, b);


		memcpy((p + i)->name,(p + (*Num - 1))->name,20);//替换
		memcpy((p + i)->sex,(p + (*Num - 1))->sex,4);
		(p + i)->age = (p + (*Num - 1))->age;
		memcpy((p + i)->phone,(p + (*Num - 1))->phone,12);

		*Num -= 1;
		printf("删除成功\n");
	}
	else
	{
		printf("没有找到\n");
	}

}

void mod(struct Stu *p, int* Num)	//修改信息
{
	int i = 0;
	int sz = 1;

	char ch[20] = "";

	printf("搜索名字修改信息->");
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
		printf("\n姓名->");
		scanf("%s", (p + i)->name);
		printf("性别->");
		scanf("%s", (p + i)->sex);
		printf("年龄->");
		scanf("%hd", &(p + i)->age);
		printf("电话->");
		scanf("%s", (p + i)->phone);
		printf("修改成功\n");
	}
	else
	{
		printf("没有找到\n");
	}
}
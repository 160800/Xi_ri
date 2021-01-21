#include"tast.h"

int main()
{
	int input = 0;  //输入

	struct Stu st[size];
	int sz = sizeof(st);	//计算st结构体大小
	int Num = 0;		//好友数量
	memset(st,0,sz);		//初始化
	Interface(); //界面
	do
	{
		printf("输入->");
		scanf("%d", &input);
		switch (input)
		{
			case Add_friends :	//添加好友
			{
				add(st,&Num);
				Interface(); //界面
			}break;
			case Delete_friend:	//删除好友
			{
				del(&st,&Num);
				Interface(); //界面
			}break;
			case Examine:			//查看
			{
				exa(st, &Num);

			}break;
			case Modification:	//修改
			{
				mod(&st, &Num);
				Interface(); //界面
			}break;
			case Quit:			//退出
			{
				printf("退出\n");
			}break;
			default :
			{
				Interface(); //界面
				printf("请重新");
			}
		}

	} while (input);

	 
	system("pause");
	return 0;
}
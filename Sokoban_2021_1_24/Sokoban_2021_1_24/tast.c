#include"tast.h"

int main()
{
	int input = 1;  //输入
	
	interface1();
	printf("选择->");

	while (input)
	{
		scanf("%d", &input);
		switch (input)
		{
			case 1:
			{
				getchar();		//清除缓存区回车
				system("cls");
				game();    //游戏
				system("cls");  //清屏
				interface1();		//界面
				printf("选择->");
			}break;
			case 0:
			{
				printf("退出\n");
			}break;
			default:
			{
				printf("重新输入->");
			}break;
		}
	}
	system("pause");
	return 0;
}
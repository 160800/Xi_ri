//��ŵ��
/*
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int count = 0;

void pyramid(int a)
{
	if (1 == a)
	{
		count++;
	}
	else
	{
		pyramid(a - 1);
			count++;
		pyramid(a - 1);
	}

}

int main()
{
	int a = 5;

//	scanf("%d",&a);

	pyramid(a);

	printf("%d",count);

	system("pause");
	return 0;
}
*/

//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
/*
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int sum(int a)
{
	if (9 < a)
	{
		sum(a / 10);
		printf("%d ",a%10 );
	}
	else
	{
		printf("%d ",a);
	}	

}

int main()
{
	int a = 0;
	scanf("%d",&a);
	sum(a);

	system("pause");
	return 0;
}
*/

//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩
/*
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int factorial(int a)
{
	if (1 < a)
	{
		return a*factorial(a - 1);
	}
	else
	{
		return a;
	}
}

int main()
{
	int a = 0;
	scanf("%d",&a);

	int sum = factorial(a);

	printf("%d",sum);

	system("pause");
	return 0;
}
*/

//�ǵݹ�ֱ�ʵ����n�Ľ׳�
/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0;
	scanf("%d",&a);

	int num = 1;
	int i = 0;
	for (i = 1; i <= a; i++)
	{
		num = num * i;
	}

	printf("%d",num);

	system("pause");
	return 0;
}
*/

//�ݹ�ͷǵݹ�ֱ�ʵ��strlen
/*
#include<stdio.h>
#include<stdlib.h>

int stlen(char* a)
{
	
	if (*a != '\0')
	{
		a++;
		return 1 + stlen(a);
	}
	return 0;
}

int main()
{
	char ch[10] = "cbafsdf";

	int a = stlen(&ch);
	printf("%d",a);


	system("pause");
	return 0;
}
*/

//�ǵݹ�ֱ�ʵ��strlen
/*
#include<stdio.h>
#include<stdlib.h>

int stlen(char* p)
{
	int count = 0;
	while (*p != '\0')
	{
		p++;
		count++;
	}
	return count;
}

int main()
{
	char ch[] = "auksd";

	printf("%d\n", stlen(&ch));

	system("pause");
	return 0;
}
*/

//�ַ������򣨵ݹ�ʵ�֣�
//�����ӡ

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
void contrary(char* p)
{
	if (*(p+1) != '\0')
	{
		contrary(p+1);	
	}
		printf("%c ", *p);
}

int main()
{
	char ch[5] = "abcd";

	scanf("%s",&ch);
	contrary(&ch);

	system("pause");
	return 0;
}
*/

//����һ������ÿλ֮�ͣ��ݹ�ʵ�֣�
/*
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int count = 0;

int num(int a)
{
	if (0 < a)
	{
		count+= a % 10;
		num(a / 10); 
	}
	return count;
}

int main()
{
	int a = 272397;
	
	scanf("%d",&a);

	printf("%d",num(a));

	system("pause");
	return 0;
}
*/

//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
/*
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int num(int n)
{
	if (2 >= n)
	{
		return 1;
	}
	else
		return num(n - 1) + num(n - 2);

}

int main()
{
	int a = 0;

	scanf("%d",&a);

	printf("%d",num(a));

	system("pause");
	return 0;
}
*/

//
/*
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0;

	scanf("%d",&a);

	int num = 1;
	int sum = 1;
	int con = 0;
	int i = 0;
	for (i = 2; i < a; i++)
	{
		if (i % 2 == 0)
		{
			num = num + sum;
			con = num;
		}
		else
		{
			sum = num + sum;
			con = sum;
		}
	}
	printf("%d",con);

	system("pause");
	return 0;
}
*/

//�ݹ�ʵ��n��k�η�
/*
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int pow1(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n * pow1(n-1);
	}
}

int main()
{
	int a = 0;

	scanf("%d",&a);
	printf("%d",pow1(a));

	system("pause");
	return 0;
}
*/

//����һ������ÿλ֮�ͣ��ݹ�ʵ�֣�
/*
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int num(int a)
{	
	if (10 > a)
	{
		return a;//a%10;
	}
	else
	{
		return num(a/10)+(a%10);
	}

}

int main()
{
	int a = 272397;

	scanf("%d",&a);

	printf("%d",num(a));

	system("pause");
	return 0;
}
*/

//����洢

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void contrary(char* p)
{
	int len = strlen(p);
	char tmp = *p;

	*p = *(p + len - 1);
	*(p + len - 1) = '\0';

	if (strlen(p + 1) >= 2)
	{
		contrary(p + 1);
	}

	*(p + len - 1) = tmp;

}

int main()
{
	char ch[10] = "abcdf";
	contrary(&ch);
	printf("%s",ch);
	system("pause");
	return 0;
}

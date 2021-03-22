#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//表达式求值先看是否存在整形提升或算数转换，再进行计算
//表达式真正计算的时候先看相邻操作符的优先级决定先算谁
//相邻操作符的优先级相同的情况下，看操作符的结合性决定计算顺序

/*关于指针的概念，错误的是：C
A.指针是变量，用来存放地址
B.指针变量中存的有效地址可以唯一指向内存中的一块区域
C.野指针也可以正常使用
D.局部指针变量不初始化就是野指针
*/

// 32位下：int类型占四个字节，指针占四个字节，操作系统可以使用的最大内存空间是2^32
// 64位下：int类型占四个字节，指针占八个字节，操作系统可以使用的最大内存空间是2^64

/*
int main()
{
	int arr[] = { 1,2,3,4,5 };
	short* p = (short*)arr;
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		*(p + i) = 0;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
//输出结果：0 0 3 4 5
*/


/*
int main()
{
	int a = 0x11223344;
	char* pc = (char*)&a; // 44 33 22 11
	*pc = 0;//解引用只能操作一个字节，将44->00
	printf("%x\n", a); //11 22 33 00
	return 0;
}
//输出结果：11223300
*/


/*
int i;
int main()
{
	i--; //全局变量 - 不初始化 - 默认是0；
	if (i > sizeof(i)) //sizeof() - 计算变量/类型所占内存的大小 >=0 无符号数
	{
		printf(">\n");
	}
	else
	{
		printf("<\n");
	}
	return 0;
}
//输出结果: >
*/


/*
int main()
{
	int a, b, c;
	a = 5;
	c = ++a; //c = 6  a = 6
	b = ++c, c++, ++a, a++; //c = 8   b=7  a=8
	b += a++ + c; // b = 23   a = 9
	printf("a = %d b = %d c = %d\n:", a, b, c);
	return 0;
}
//输出结果：a = 9 b = 23 c = 8
*/


// 求二进制中不同位的个数【int（32位）整数m和n的二进制表达中，有多少个位（bit）不同】
/*
int get_diff_bit(int m, int n)
{
	int tmp = m ^ n;
	int count = 0;
	//return count_bit_one(tmp);
	//或者是下面的方法
	while (tmp)
	{
		tmp = tmp & (tmp - 1);
		count++;
	}
	return count;
}

int main()
{
	int m = 0;
	int n = 0;
	scanf("%d%d", &m, &n);
	int count = get_diff_bit(m, n);
	printf("count = %d\n", count);

	return 0;
}
*/



//打印二进制的奇数位和偶数位（获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列）
/*
void print(int m)
{
	int i = 0;
	printf("奇数位: \n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (m >> i) & 1);
	}
	printf("\n");
	printf("偶数位：\n");
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (m >> i) & 1);
	}
	printf("\n");
}

int main()
{
	int m = 0;
	scanf("%d", &m);
	print(m);
	return 0;
}
*/



//统计二进制中的1的个数（写一个函数返回参数二进制中1的个数）
/*
int count_bit_one(unsigned int n) //考虑到负数的情况
{
	int count = 0;
	while (n)
	{
		if (n % 2 == 1)
		{
			count++;
		}
		n = n / 2;
	}
	return count;
}
*/

/*
//另一种方法
int count_bit_one(int n)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (((n >> i) & 1) == 1)
		{
			count++;
		}
	}
	return count;
}
*/

//优化的方法

//n = n&(n-1)
//n = 13
//1101 n
//1100 n-1 -> 与n按位与赋值给n
//1100 n
//1011 n-1
//1000 n
//0111 n-1
//0000 n

/*
int count_bit_one(int n)
{

	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	//写一个函数求a的二进制表示中有几个1
	int count = count_bit_one(a); 
	//-1
	//10000000000000000000000000000001
	//11111111111111111111111111111110
	//11111111111111111111111111111111
	printf("count = %d\n", count);
	return 0;
}
*/




//交换两个变量（不创建临时变量）： 不允许创建临时变量，交换两个整数的内容

//加减的方法
/*
#include<stdlib.h>
int main()
{
	int a, b;
	a = 5;
	b = 7;
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d %d", a, b);
	system("pause");
	return 0;
*/

//异或的方法
/*
int main()
{
	int a, b;
	a = 5;
	b = 7;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d %d", a, b);
	system("pause");
	return 0;
}
*/



//使用指针打印数组内容（写一个函数打印arr数组的内容，不使用数组下标，使用指针） ； arr是一个整形一维数组

void print(int* p, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(p + i));
	}
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	return 0;
}



//求两个数的最大公约数

/*
int main()
{
	int a, b;
		printf("输入两个数字求最大公约数:");
		scanf("%d%d", &a, &b);
		while (a != b)
		{
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		printf("最大公约数是:%d\n", a);
	system("pause");
	return 0;
}

5.(2)
//最小公倍数为 两数之积除以最大公约数
//求两个数的最大公约数
//辗转相除法
int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
//相减法
int gcd(int a, int b) {
	while (a != b) {
		if (a > b) {
			a = a - b;
		}
		else {
			b = b - a;
		}
	}
	return a;
}

int main() {
	int ret = gcd(12,18);
	printf("%d\n", ret);
	printf("%d", ret);
	system("pause");
	return 0;
}
*/






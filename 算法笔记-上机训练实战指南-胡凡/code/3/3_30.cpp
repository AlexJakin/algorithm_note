/**
B1006
**/
#include <stdio.h>
int main(){
	int n;
	int a, b;
	//输入一个三位数 
	scanf("%d", &n);
	
	//计算a 输出B的个数
	a = n / 100;
	
	//计算b 输出C的个数
	b = n % 100 / 10;
	
	for (int i = 0; i < a; i++)
		printf("B");
	for (int i = 0; i < b; i++)
		printf("S");
	printf("1%d", n);
	 
	return 0;
} 
/**
B1006
**/
#include <stdio.h>
int main(){
	int n;
	int a, b;
	//����һ����λ�� 
	scanf("%d", &n);
	
	//����a ���B�ĸ���
	a = n / 100;
	
	//����b ���C�ĸ���
	b = n % 100 / 10;
	
	for (int i = 0; i < a; i++)
		printf("B");
	for (int i = 0; i < b; i++)
		printf("S");
	printf("1%d", n);
	 
	return 0;
} 
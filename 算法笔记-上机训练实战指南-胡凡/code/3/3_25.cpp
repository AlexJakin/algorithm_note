// B1022 D进制的A+B
#include <stdio.h>

int main(){
	int a, b, d;
	scanf("%d %d %d", &a, &b, &d);
	int sum = a + b;
	int ans[31] = {0};
	int num = 0;
	
	while(sum != 0)//直到商为0 
	{
		ans[num++] = sum % d; //存储顺序是从高位到低位 
		sum /= d;
	}
	//输出结果
	for(int i = num - 1; i >= 0; i--)
		printf("%d", ans[i]); 
	return 0;
} 
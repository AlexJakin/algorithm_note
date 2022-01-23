#include <stdio.h>
#include <cmath>

int main(){
	int n;
	char c;
	scanf("%d %c", &n, &c);
	//先计算三角形底边的字符数  
	int bottom = (int)sqrt(2.0 * (n + 1))-1;
	//如果底边是偶数 应该减一变成奇数 
	if(bottom % 2 == 0) bottom--;
	
	//总共的输出的字符数 
	int used = (bottom + 1) * (bottom + 1)/2 -1;
	
	//输出倒三角 每往下一层多输出一个 
	for(int i = bottom; i >= 1;  i -= 2)
	{
		for(int j = 0; j < (bottom - i)/2; j++)
			printf(" "); // 空格个数为(bottom - i)/2 
		for(int j = 0; j < i; j++)
			printf("%c", c);
		printf("\n");
	}
	
	//输出正三角
	for(int i = 3; i <= bottom; i += 2)
	{
 		//打印空格
		for (int j = 0;j < (bottom - i)/2; j++)
 			printf(" ");	
 		//打印*
		 for (int j = 0; j < i; j++)
		 {
 			printf("%c", c);
 		}
 		printf("\n");
	}
	printf("%d\n", n - used);
	return 0;
}
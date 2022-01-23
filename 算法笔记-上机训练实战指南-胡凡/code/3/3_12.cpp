//B1010 一元多项式求导
#include <stdio.h>

int main(){
	int a[1010] = {0};
	int k, e, count = 0;
	while(scanf("%d%d", &k, &e) != EOF)
	{
		a[e] = k; // 用a数组存储 e次项的系数为k 
	}
	// 常数项求导为0 
	a[0] = 0;
	
	/**求导部分**/ 
	for(int i = 1; i <= 1000; i++)
	{
		//求导公式 
		a[i-1] = a[i]*i;
		a[i] = 0;//常数项求导为0
		if(a[i-1] != 0) count++; 
	}
	
	/**输出部分**/
	if(count == 0) 
		printf("0 0");
	else
	{
		for(int i = 1000; i >= 0; i--)
		{
			if(a[i] != 0)
			{
				printf("%d %d", a[i], i);
				count--;
				if(count != 0) printf(" ");
			}
		}
	}
	return 0;
} 
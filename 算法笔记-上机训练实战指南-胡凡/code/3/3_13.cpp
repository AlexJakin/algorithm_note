#include <stdio.h>
const int max_n = 1111;
double p[max_n] = {};

int main(){
	int k, n, count = 0;
	double a;
	//非零项个数 
	scanf("%d", &k);
	// 第一个多项式 
	for(int i = 0; i < k; i++)
	{
		scanf("%d %lf", &n, &a);
		p[n] += a;
	}
	//第二个多项式
	scanf("%d", &k);
	for(int i = 0; i < k; i++)
	{
		scanf("%d %lf", &n, &a);
		p[n] += a;
	} 
	//相加后统计非零项数
	for(int i = 0;i < max_n; i++)
	{
		if(p[i] != 0) count ++;
	}
	printf("%d", count);
	
	/**输出部分**/
	for(int i = max_n - 1; i >= 0; i--)
		if(p[i] != 0)
			printf(" %d %.1f", i, p[i]); 
	return 0;
} 
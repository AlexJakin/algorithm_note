//A1009 多项式乘积 
#include <stdio.h>

struct Poly {
	int exp;//指数 
	double cof;//系数 
}poly[1001]; //第一个多项式 

double ans[2001]; 

int main(){
	int n, m, number = 0;
	//第一个多项式的非零系数 
	scanf("%d", &n);
	//输入第一个多项式 
	for(int i = 0; i < n; i ++)
	{
		scanf("%d %lf", &poly[i].exp, &poly[i].cof);
	}
	//第二个多项式的非零系数 
	scanf("%d", &m);
	//输入第二个多项式并与各项相乘 
	for(int i = 0; i < m; i++)
	{
		int exp;
		double cof;
		scanf("%d %lf", &exp, &cof);
		for(int j = 0; j < n; j++)
		{
			//每一项都和该项相乘 
			ans[exp+poly[j].exp] += (poly[j].cof * cof);
		}
	}
	//统计非零个数
	for(int i = 0; i <= 2000; i++)
	{
		if(ans[i] != 0.0) number++;
	}
	printf("%d", number);
	for(int i = 2000; i >= 0; i--)
	{
		if(ans[i] != 0.0) 
			printf(" %d %.1f", i, ans[i]);
	}
	return 0;
}
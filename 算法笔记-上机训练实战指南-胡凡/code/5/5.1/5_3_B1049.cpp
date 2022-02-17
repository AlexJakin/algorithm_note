// B1049 数列的片段和
// 如果当前是第i个数 出现的总次数为i*（n+1-i） 固定i 长度可变 
#include <stdio.h>
#include <cstring>

int main(){
	// 数组长度
	int  n;
	double v, ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &v);
		ans += v * i *(n + 1 - i);
	}
	printf("%.2f\n", ans);
	return 0;
} 
// A1093 有几个PAT
#include <stdio.h>
#include <cstring>

const int maxn = 100010;
const int mod = 1000000007;
char str[maxn];
int leftNumP[maxn]= {0};  // 每一位A左边P的个数 用数组来记录P的个数（一定是个单调不减数组） 

int main(){
	gets(str);
	int len = strlen(str);
	//遍历字符串 查找P 
	for(int i = 0; i < len; i++)
	{
		if(i > 0) leftNumP[i] = leftNumP[i - 1];
		if(str[i] == 'P') leftNumP[i]++;
	}
	
	int ans = 0, rightNumT = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if(str[i] == 'T') rightNumT++;
		else if(str[i] == 'A') ans = (ans + leftNumP[i] * rightNumT) % mod;
	}
	//输出结果
	printf("%d", ans); 
	return 0;
} 
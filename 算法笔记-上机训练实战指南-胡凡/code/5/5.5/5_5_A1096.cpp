// A1096 Consecutive Factor
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;

int main(){
	LL n;
	scanf("%lld", &n);
	// anslen是最长连续长度 anI是第一个整数 
	LL sqr = (LL)sqrt(1.0 * n), ansI = 0, ansLen = 0;
	
	//寻找连续整数 
	for(int i = 2; i <= sqr; i++)
	{
		// temp连续乘积 j不断增加来判断以i开始的数是否构成连续整数 
		LL temp = 1, j = i;
		while(true)
		{
			temp *= j;
			if(n % temp != 0) break;
			// 如果当前以i为首的连续j-i+1个数是最长的 则更新 
			if(j - i + 1 > ansLen)
			{
				ansLen = j - i + 1; // 更新长度 
				ansI = i; // 更新连续整数的首部 
			}
			j++;
		}
	}
	if(ansLen == 0)// 无解 
		printf("1\n%lld", n);
	else
	{
		printf("%lld\n", ansLen);
		for(int i = 0; i < ansLen; i++)
		{
			printf("%lld",  ansI + i);
			if(i < ansLen - 1)
				printf("*");
		}
	}
	return 0;
}
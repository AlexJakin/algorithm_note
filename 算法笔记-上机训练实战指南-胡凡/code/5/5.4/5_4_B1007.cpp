// B1007 素数对猜想
//求小于N的素数对个数 
#include <stdio.h>
#include <cmath>

// 判断是否是素数 不存在除以小于sqrt(n)的任何数
bool isPrime(int n)
{
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++)
		if(n % i == 0) 
			return false;
	return true;
}

int main(){
	int n, count = 0;
	scanf("%d", &n);
	for(int i = 3; i + 2 <= n; i += 2)
	{
		//如果是素数 
		if(isPrime(i) == true && isPrime(i + 2) == true)
			count++;
	}
	printf("%d\n", count);
	return 0;
}
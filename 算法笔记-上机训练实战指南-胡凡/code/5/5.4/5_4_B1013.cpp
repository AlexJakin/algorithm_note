// B1013 数素数
// 暴力搜索 先建立小于maxn的素数表 
#include <stdio.h>
#include <cmath>

const int maxn = 1000010;

//判断是否是素数 
bool isPrime(int n)
{ 
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++)
		if(n % i == 0)
			return false;
 	return true;
}

int prime[maxn], num = 0;
bool p[maxn] ={0};
//建立素数表 最多只需要n个素数 
void Prime_list(int n)
{
	for(int i = 1; i < maxn; i++)
	{
		if(isPrime(i) == true)
		{
			prime[num++] = i;
			p[i] = true;
			if(num >= n) break; // 只需要n个素数 
		}
	}
}
int main(){
	// 第left个素数输出到第right个素数 
	int left, right;
	int count = 0;// 计数 每10个一行 
	scanf("%d %d",&left, &right);
	Prime_list(right);
	//输出
	for(int i = left; i <= right; i++)
	{
		printf("%d", prime[i - 1]);
		count ++;
		//输出十个换行 
		if(count % 10 != 0 && i < right) printf(" ");
		else printf("\n");
	} 
	return 0;
} 
// A1059 Prime Factors
// 使用素数表寻找 
#include <stdio.h>
#include <math.h>

using namespace std;

const int maxn = 100010;
//判断 是否是素数 
bool is_prime(int n)
{
	if(n == 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i ++)
	{
		if(n % i == 0) return false;
	}
	return true;
}
//素数表 
int prime[maxn], pNum  = 0;
// 求素数表  
void Prime_list()
{
	for(int i = 1; i < maxn;  i++)
		if(is_prime(i) == true)
			prime[pNum++] = i;
} 

struct  factor{
	int x; // 质因数
	int cnt; // 个数 
}fac[10];

int main(){
	Prime_list();
	int n, num = 0;
	scanf("%d", &n);
	//特判
	if(n  == 1)
		printf("1=1");
	else
	{
		printf("%d=", &n);
		int sqr = (int)sqrt(1.0 * n);
		for(int i = 0; i < pNum && prime[i] < sqr; i++)
		{
			//如果Prime[i]是质因数 
			if(n % prime[i] == 0)
			{
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				//相同质因数的个数 
				while(n % prime[i] == 0)
				{
					fac[num].cnt++;//相同质因数的个数加一 
					n /= prime[i];//更新n 
				} 
				num ++; //不同质因数加一 
			}
			if(n == 1) break;
		}
		//如果无法根号n内的质因数除尽 
		if(n != 1)
		{
			fac[num].x = n; 
			fac[num++].cnt = 1;
		}
		//输出
		for(int i = 0; i < num; i++)
		{
			if(i  > 0) printf("*");
			printf("%d", fac[i].x);
			if(fac[i].cnt > 1) printf("^%d", fac[i].cnt);
		} 
	} 
	return 0;
}
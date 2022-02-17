// A1015 Reversible Primes
// 考察进制转化(辗转相除法) 和 素数
#include <stdio.h>
#include <cmath>

//是否是素数 
bool isPrime(int n)
{
	if(n <= 1) return false;
	int sqr = sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++)
		if(n % i == 0) return false;
	return true;	
}
int d[111];
int main(){
	int n, radix;
	while(scanf("%d", &n) != EOF)
	{
		if(n < 0) break;
		scanf("%d", &radix);
		//正序是素数
		if(isPrime(n) == false) 
			printf("No\n");
		else
		{
			//辗转相除法  
			int len = 0;
			do{ // 进制转换 高位在数组第一位 即此时 
				d[len++] = n % radix;
				n /= radix;
			}while(n != 0);
			for(int i = 0; i < len; i++)//秦九韶算法
				n = n * radix + d[i]; 
		}
		if(isPrime(n) == true) printf("Yes\n"); // 逆序是素数 
		else printf("No\n"); // 逆序不是素数 
	}
	return 0;
} 
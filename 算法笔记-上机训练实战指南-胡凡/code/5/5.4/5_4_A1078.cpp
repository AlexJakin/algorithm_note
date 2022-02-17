// A1078 Hashing
#include <stdio.h>
#include <cmath>
#include <vector>
const int N = 11111;
using namespace std;

// 判断是否是素数
bool isPrime(int n) 
{
	if(n <= 1) return false;
	int sqr = sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i ++)
		if(n % 2 == 0) return false;
	return true;
}
//哈希表
bool hashTable[N] = {0};  

int main(){
	int n, Tsize, a;
	scanf("%d %d", &Tsize, &n);
	// 寻找大于Tsize的最小素数 
	while(isPrime(Tsize) == false) Tsize++;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		//寻找插入位置M 如果M位置已经插入使用二次方探查法 
		int M = a % Tsize;
		if(hashTable[M] == false)
		{
			hashTable[M] = true;
			//输出插入位置 
			if(i == 0) printf("%d", M);
			else printf(" %d", M);
		}
		else // 使用二次方探查法 (题目只要求正向)
		{
			int step;//步长
			for(step = 1; step < Tsize; step++)
			{
				M = (a + step * step) % Tsize; // 下一个检查法
				if(hashTable[M] == false)
				{
					hashTable[M] = true;
					// 输出插入位置 
					if(i == 0) printf("%d", M);
					else printf(" %d", M);
					break; // 一定要跳出循环 
				} 
			}
			//找不到插入位置 
			if(step >= Tsize)
			{
				if(i > 0) printf(" ");
				printf("-");
			}	
		}
	}
	return 0;
}
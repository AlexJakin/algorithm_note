// B1008 数组元素循环右移问题
// 让移动次数最少
// 求最大公约数来减少循环次数
 
#include <stdio.h>
#include <cstring>

//求最大公约数的递归算法 
int gcd(int a, int b)
{
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int main(){
	int a[110];
	// temp临时变量 pos当前处理位置  next下一个处理位置  
	int n, m, temp, pos, next;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	m = m % n; // 经过m次循环的结果和m%n次一样 
	if(m != 0)
	{
		int d = gcd(m, n);
		// 从n-m处开始 
		for(int i = n - m; i < n - m + d; i++)
		{
			temp = a[i];
			pos = i; // 记录当前位置
			
			do{
				next = (pos - m + n) % n;
				if(next != i) a[pos] = a[next];
				else a[pos] = temp;
				pos = next;
			}while(pos != i);
		}
	}
	
	// 输出
	for(int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if(i < n - 1) printf(" ");
	} 
	
	return 0;
}

/**
因为每次步骤1的跨度为K（设K为最大公倍数），K/M即为每次步骤1所重排的数字个数。（因为移动的距离为4，而返回起始位需要移动距离为6的倍数，所以完成一次步骤1一共跨越了12个数，有3个数字被重排）

每个数字经历一次重排就可到达指定位置，且一共有N个数字需要重排，N/(K/M)即为需要进行步骤1的次数。（MN/K即d，因此进行d次步骤1即可）

易知连续地选取起始位即可使每个数字都被重排。
参考 https://www.cnblogs.com/Ivan-Luo/p/11150804.html 
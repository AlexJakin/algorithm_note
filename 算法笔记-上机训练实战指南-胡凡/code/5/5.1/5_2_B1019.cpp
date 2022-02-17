#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

// 非递减
bool cmp_1(int a, int b)
{
	return a < b;
} 

// 非递增
bool cmp_2(int a, int b)
{
	return a > b;
}

//将四位正整数转化为数组
void to_array(int a, int num[])
{
	for(int i = 0; i < 4; i++)
	{
		num[i] = a % 10;
		a = a / 10;
	}
}

// 将num数组转为数字
int to_number(int num[])
{
	int sum = 0;
	for(int i = 0; i < 4; i++) sum = sum * 10 + num[i];
	return sum;
} 
int main(){
	int n; //  四位正整数 
	int min, max; 
	scanf("%d", &n);
	
	int num[4]; 
 	while(1)
 	{
 		//获取被减数 
		to_array(n, num);
		sort(num, num + 4, cmp_1); // 从小到大排序
 		min = to_number(num);
	 	//获取减数
	  	sort(num, num + 4, cmp_2);
	  	max = to_number(num);
	  	n = max - min;
	  	printf("%04d - %04d = %04d\n", max, min, n);
	  	if(n == 0 || n == 6174) break;
 	}
 	return 0;
}
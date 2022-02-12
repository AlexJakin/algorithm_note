//B1023 组个最小数
//策略：1-9选择一个不为0的数输出 0-9选择最小的输出 
#include <stdio.h>
#include <cstring>
//记录0-9的个数
int count[10];

int main(){
	for(int i = 0; i < 10; i++)
	{
		scanf("%d", &count[i]);
	}
	
	//从1-9中选择count不为0的最小的数字 输出的是最高位 
	for(int i = 1; i < 10; i++)
	{
		if(count[i] > 0)
		{
			printf("%d", i);
			count[i]--;
			break;
		}
	}
	// 从0-9输出数字 从最小数字开始输出 
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < count[i]; j++)
		{
			printf("%d", i);
		}
	}
	return 0;
} 
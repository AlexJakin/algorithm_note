/**
1. start[] 存放初始数组  end[] 存放相当于  next[]存放变化顺序 
   1~13 表示 S 14~26 表示 H  等等推断出 (x-1)%13+1 为所属花色序号 
**/ 
#include <stdio.h>
const int N = 54;
char mp[5] = {
	'S', 'H', 'C', 'D', 'J'
};
int start[N+1], end[N+1], next[N+1];
int main(){
	/**      input part      **/
 	//变化次数 
	int K;
	scanf("%d", &K);
	//初始化牌位 
	for(int i = 1; i <= N; i++)
	{
		start[i] = i;
	}
	//初始化移动数组
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &next[i]);
	} 
	
	/**      process      **/
	for(int step = 0; step < K; step++)
	{
		for(int i = 1; i <= N; i++)
		{
			//变换 
			end[next[i]] = start[i];
		}
		for(int i = 1; i <= N; i++)
		{
			start[i] = end[i];
		}
	}
	
	/**      output      **/
	for(int i = 1; i <= N; i++)
	{
		//输出格式 第一个不输出空格 
		if(i != 1) printf(" ");
		start[i]--;//数组下标以0为起点 
		//最终start[]是存放结果顺序 
		printf("%c%d", mp[(start[i]/13)], (start[i]%13+1));
	}
	return 0;
} 

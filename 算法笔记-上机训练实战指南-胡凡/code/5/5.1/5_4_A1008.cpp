// A1008 Elevator
#include <stdio.h>

int main(){
	int n; //换乘次数
	int total = 0, now = 0, to;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &to);
		if(to > now)// 上楼 
		{
			total += ((to - now) * 6);
		}
		else//下楼 
		{
			total += ((now - to) * 4);
		}
		total += 5;
		now = to; // 更新当前已到达 
	}
	printf("%d\n", total);
	return 0;
}
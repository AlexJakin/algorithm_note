// B1047 编程团体赛
#include <stdio.h>
#include <cstring>

const int maxn = 1010;
int hashTable[maxn] = {0};

int main(){
	//参赛人数
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int team, member, score;
		scanf("%d-%d %d", &team, &member, &score);
		hashTable[team] += score;
	}
	//寻找最大值 
	int k, max = -1;
	for(int i = 0; i < maxn; i++)
	{
		if(hashTable[i] > max)
		{
			k = i;
			max = hashTable[i];
		}
	}
	printf("%d %d\n", k, max);
	return 0;
} 
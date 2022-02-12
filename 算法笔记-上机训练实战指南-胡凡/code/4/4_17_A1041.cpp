// A1041 Be Unique
#include <stdio.h>
#include <cstring>

int a[100001], hashTable[10001] = {0};

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		hashTable[a[i]]++;
	}
	
	//存放只有一个数字
	int ans = -1;
	for(int i = 0; i < n; i++)
	{
		if(hashTable[a[i]] == 1)
		{ 
			ans = a[i];
			break;
		}
	} 
	return 0;
} 
// A1048 Find Coins
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1005;
int hashTable[N];
int main(){
	int n, m, a;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		++hashTable[a];
	}
	
	for(int i = 0; i < N; i++)
	{
		//如果i 和 m-i都存在 
		if(hashTable[i] && hashTable[m - i])
		{
			if(i == m - i && hashTable[i] <= 1) continue;
			printf("%d %d\n", i, m - i);
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}
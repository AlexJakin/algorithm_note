// A1029 Median
// 让两个指针同时跑 跑到(n+m-1)/2趟 
#include <stdio.h>

const int maxn = 100010;
const int INF = 0x7ffffff;
int S1[maxn], S2[maxn];

int main(){
	int n, m;
	//第一个序列长度 
	scanf("%d", &n);
	//输入第一个序列 
	for(int i = 0; i < n; i++)
		scanf("%d", &S1[i]);
	//第二个序列长度 
	scanf("%d", &m);
	//输入第二个序列 
	for(int i = 0; i < m; i++)
		scanf("%d", &S2[i]);
	
	S1[n] = S2[n] = INF;
	int i = 0, j = 0, count = 0;
	int mid =(n + m - 1)/ 2; 
	while(count < mid)
	{
		if(S1[i] < S2[j]) i++;
		else j ++;
		count ++;
	}
	if(S1[i] < S2[j]) printf("%d", S1[i]);
	else printf("%d", S2[j]);
	return 0;
}
 
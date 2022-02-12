// A1048 Find Coins
// 1. 先排序 2.  左右指针移动 a+b<m 左指针移动 反之 右指针移动 
#include <stdio.h>
#include <algorithm>

using namespace std;
const int maxn = 100010;
int a[maxn];



int main(){
	//n为元素个数 
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	
	int i = 0;
	int j = n - 1;
	while(i < j)
	{
		// 寻找 
		if(a[i] + a[j] == m) break;
		else if(a[i] + a[j] < m) i++; // 找较大的数 
		else j--; // 找较小的数
	}
	// 有解
	if(i < j) printf("%d %d", a[i], a[j]);
	else printf("No solustion\n"); 
	return 0;
} 
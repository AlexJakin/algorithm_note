// A1085 完美数列
// 先递增排序 取出最大最小值 
#include <stdio.h>
#include <algorithm>

int n, p, a[maxn]
using namespace std;

//二分查找 在[i+1, n-1]内查找第一个大于x的数的位置 
int binarySearch(int i, long long x)
{
	if(a[n-1] <= x) return n;
	//在[l, r]内查找 
	int l = i + 1, r = n - 1, mid;
	while(l < r)
	{
		mid = (l + r) / 2;
		if(a[mid] <= x) l = mid + 1;
		else r = mid; 
	}
	return r;
} 
int main(){
	scanf("%d %d", &n, &p);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	// 递增排序 
	sort(a, a + n);
	
	int ans = 1;
	for(int i = 0; i < n; i++)
	{
		int j = binarySearch(i, (long long)a[i] * p);
		ans = max(ans, j - 1);
	}
	printf("%d\n", ans);
	return 0;
}
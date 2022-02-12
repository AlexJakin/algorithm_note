// A1044 Shooping in Mars
#include <stdio.h>
const int N = 100010;
int sum[N];
int n, S, nearS = 100000010;

//返回在区间内第一个大于x的数
int upper_bound(int left, int right, int x)
{
	int mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(sum[mid] > x) right = mid;
		
		else left = mid + 1;
	}
	return left;
} 
 
int main(){
	scanf("%d %d", &n, &S);
	sum[0] = 0; // 初始化sum[0] = 0
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];//迭代相加前面的数 
	}
	// 寻找左端点i 
	for(int i = 1; i <= n; i++)
	{
		// 找到满足S[i-1] + S = S[j] 寻找S[j]右端点 
		int j = upper_bound(i, n + 1, sum[i - 1] + S);
		if(sum[j - 1] - sum[i - 1] == S)
		{
			nearS = S;
			break;
		}
		else if(j <= n && sum[j] - sum[i - 1] < nearS)
		{
			nearS = sum[j] - sum[i - 1];
		}
	}
	for(int i = 1; i <= n; i++)
	{
		int j = upper_bound(i, n + 1, sum[i - 1] + nearS);
		if(sum[j - 1] - sum[i - 1] == nearS) printf("%d-%d\n", i, j - 1);
	}
	return 0;
}
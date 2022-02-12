// A1010 Radix
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
ll Map[256];
ll inf = (1ll << 63)-1;
char N1[20], N2[20], temp[20];
int tag, radix;

//将a转换为十进制 ，t为上界
ll convertNum10(char a[], ll radix, ll t)
{
	ll ans = 0;
	int len = strlen(a);
	for(int i = 0; i < len; i++)
	{
		ans = ans * radix + Map[a[i]];
		if(ans < 0 || ans > t) return -1;
	}
}

//N2的十进制与t比较

int cmp(char N2[], ll radix, ll t)
{
	int len = strlen(N2);
	ll num = convertNum10(N2, radix, t);
	if(num < 0) return 1;
	if(t > num) return -1;
	else if (t == num) return 0;
	else return 1;
} 
// 二分求N2的进制
ll binarySearch(char N2[], ll left, ll right, ll t)
{
	ll mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		int flag = cmp(N2, mid, t);
		if(flag == 0) return mid;
		else if(flag == 1) left = mid + 1;
		else right = mid - 1; 
	}
}

// 求最大数位
int findLargestDigit(char N2[])
{
	int ans = -1, len = strlen(N2);
	for(int i = 0; i < len; i++)
	{
		if(Map[N2[i]] >ans) ans = Map[N2[i]];
	}
	return ans + 1;
} 
int main(){
	//初始化
	for(char c = '0'; c <= '9'; c++)
		Map[c] = c - '0';
	for(char c = 'a'; c <= 'z'; c++)
		Map[c] = c - 'a' + 10;
	
	//输入
	scanf("%s %s %d %d", &N1, &N2, &tag, &radix);
	if(tag == 2)
	{
		strcpy(temp, N1);
		strcpy(N1, N2);
		strcpy(N2, temp);
	}
	// 将N1从radix进制转换为十进制 
	ll t = convertNum10(N1, radix, inf);
	ll low = findLargestDigit(N2);
	ll high = max(low, t) + 1; //上界
	ll ans = binarySearch(N2, low, high, t);
	if(ans == -1) printf("Impossible\n");
	else printf("%1ld\n", ans);
	return 0;
}
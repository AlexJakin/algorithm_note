// B1030/A1085 完美数列
#include <stdio.h>
#include <algorithm>

using namespace std;
const int maxn = 100010;

int main(){
	int n, p, a[maxn];
	scanf("%d %d", &n, &p);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	//从小到大排序 
	sort(a, a + n);
	int i = 0, j = 0, count = 1;
	while(i < n && j < n)
	{
		while(j < n && a[j] <= (long long)a[i] * p)
		{
			count = j - i + 1;  
			j ++;
		}
		i++;
	}
	printf("%d\n", count);
	return 0;
}
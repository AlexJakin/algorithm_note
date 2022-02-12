// A1048 Find coins
#include <iostream>

using namespace std;
const int maxn = 100010;
int a[maxn];

int binSearch(int left, int right, int x)
{
	int mid;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(a[mid] == x) return mid;
		else if(a[mid] > x) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int main(){
	int i, n, m;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	//ÅÅÐò
	sort(a, a + n);
	//Ñ°ÕÒm-a[i]
	for(i = 0; i < n; i++)
	{
		int pos = binSearch(0, n - 1, m - a[i]);
		//ËµÃ÷ÕÒµ½ 
		if(pos != -1 & i != pos)
		{
			printf("%d %d\n", a[i], a[pos]);
			break;
		} 
	}
	if(i == n) printf("No Solution\n");
	return 0;
} 
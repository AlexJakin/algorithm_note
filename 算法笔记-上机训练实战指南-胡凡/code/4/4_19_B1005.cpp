//B1005 继续(3n+1)猜想
// 背景补充：卡拉兹猜想 
//  对任何一个自然数n 如果是奇数，3n+1后砍一半 如果是偶数砍一半 最后一定能得1 
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace  std;
bool hashTable[1000] = {0}; 
bool cmp (int a, int b)
{
	return a > b; // 从大到小排序 
}
 
int main(){
	int n, m, a[110];
	scanf("%d", &n);
	
	//对m进行猜想操作
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		m = a[i];
		if(m % 2 == 1) m = (3*m + 1) / 2;// 如果偶数奇数 
		else  m = m / 2; //如果是偶数 
		//将被覆盖的数置为true
		hashTable[m] = true; 
	}
	//计数关键字字数 未被覆盖的数 
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(hashTable[i] == false)
		{
			count ++;
		} 
	}
	sort(a, a+n, cmp);
	for(int i = 0; i < n; i++)
	{
		if(hashTable[a[i]] == false)
			{
				printf("%d", a[i]);
				count --;
				if(count > 0) printf(" ");
			}
	}
	return 0;
} 
// A1048 Find Coins
// 1. ������ 2.  ����ָ���ƶ� a+b<m ��ָ���ƶ� ��֮ ��ָ���ƶ� 
#include <stdio.h>
#include <algorithm>

using namespace std;
const int maxn = 100010;
int a[maxn];



int main(){
	//nΪԪ�ظ��� 
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	
	int i = 0;
	int j = n - 1;
	while(i < j)
	{
		// Ѱ�� 
		if(a[i] + a[j] == m) break;
		else if(a[i] + a[j] < m) i++; // �ҽϴ���� 
		else j--; // �ҽ�С����
	}
	// �н�
	if(i < j) printf("%d %d", a[i], a[j]);
	else printf("No solustion\n"); 
	return 0;
} 
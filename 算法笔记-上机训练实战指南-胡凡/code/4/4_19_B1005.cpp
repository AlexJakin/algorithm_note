//B1005 ����(3n+1)����
// �������䣺�����Ȳ��� 
//  ���κ�һ����Ȼ��n �����������3n+1��һ�� �����ż����һ�� ���һ���ܵ�1 
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace  std;
bool hashTable[1000] = {0}; 
bool cmp (int a, int b)
{
	return a > b; // �Ӵ�С���� 
}
 
int main(){
	int n, m, a[110];
	scanf("%d", &n);
	
	//��m���в������
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		m = a[i];
		if(m % 2 == 1) m = (3*m + 1) / 2;// ���ż������ 
		else  m = m / 2; //�����ż�� 
		//�������ǵ�����Ϊtrue
		hashTable[m] = true; 
	}
	//�����ؼ������� δ�����ǵ��� 
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
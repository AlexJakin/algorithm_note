/**
A1046. Shortest Distance

**/
#include <stdio.h>

const int MAXN = 100005;
//dis[i]��ʾ1�Žڵ㰴˳ʱ�뵽��� i+1��� �ľ���  A[i]��ʾi��i+1����ľ��� 
int dis[MAXN], A[MAXN];

//�����м�����Ľ��� 
int swap(int &a, int &b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}

int min(int a, int b)
{
	if(a > b) return b;
	else return a;
}

int main(){
	/**
	sum��һȦȨֵ�ܺ�
	n�������
	query����ѯ���·����
 	left right�����->�յ��Ȩֵ 
	**/
	int sum = 0, n, query, left, right;
	// ������ 
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
		sum += A[i];
		dis[i] = sum; //Ԥ����dis ��ʾ����1������i+1�ľ���
	}
	scanf("&d", &query);
	for(int i = 0; i < query; i++)
	{
		scanf("%d%d", &left, &right);
		if(left > right) swap(left, right);
		int temp = dis[right - 1] - dis[left - 1];
		printf("%d\n", min(temp, sum - temp)); //��ʱ��Ȩֵ�൱��sum��ȥ˳ʱ�� 
	}
	return 0;
}
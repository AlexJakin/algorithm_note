//A1009 ����ʽ�˻� 
#include <stdio.h>

struct Poly {
	int exp;//ָ�� 
	double cof;//ϵ�� 
}poly[1001]; //��һ������ʽ 

double ans[2001]; 

int main(){
	int n, m, number = 0;
	//��һ������ʽ�ķ���ϵ�� 
	scanf("%d", &n);
	//�����һ������ʽ 
	for(int i = 0; i < n; i ++)
	{
		scanf("%d %lf", &poly[i].exp, &poly[i].cof);
	}
	//�ڶ�������ʽ�ķ���ϵ�� 
	scanf("%d", &m);
	//����ڶ�������ʽ���������� 
	for(int i = 0; i < m; i++)
	{
		int exp;
		double cof;
		scanf("%d %lf", &exp, &cof);
		for(int j = 0; j < n; j++)
		{
			//ÿһ��͸������ 
			ans[exp+poly[j].exp] += (poly[j].cof * cof);
		}
	}
	//ͳ�Ʒ������
	for(int i = 0; i <= 2000; i++)
	{
		if(ans[i] != 0.0) number++;
	}
	printf("%d", number);
	for(int i = 2000; i >= 0; i--)
	{
		if(ans[i] != 0.0) 
			printf(" %d %.1f", i, ans[i]);
	}
	return 0;
}
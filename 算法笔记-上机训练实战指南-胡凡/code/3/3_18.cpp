#include <stdio.h>
const int  maxn = 10010;
int school[maxn] = {0};// ������ѧУ��� ֵ���ܷ� 

int main(){
	int n, school_id, score;
	//����ѧ���ɼ�����
	scanf("%d ", &n);
	//����ѧ������ �� ͳ�� 
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &school_id,  &score);
		school[school_id] +=score;
	}
	//���
	int k, max = -1;
	for(int i = 1; i <= n; i++)
	{
		if(school[i] > max)
		{
			k = i;
			max = school[i];
		}
	}
	printf("%d %d\n", k, max);
	return 0;
}
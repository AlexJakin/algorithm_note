// B1049 ���е�Ƭ�κ�
// �����ǰ�ǵ�i���� ���ֵ��ܴ���Ϊi*��n+1-i�� �̶�i ���ȿɱ� 
#include <stdio.h>
#include <cstring>

int main(){
	// ���鳤��
	int  n;
	double v, ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &v);
		ans += v * i *(n + 1 - i);
	}
	printf("%.2f\n", ans);
	return 0;
} 
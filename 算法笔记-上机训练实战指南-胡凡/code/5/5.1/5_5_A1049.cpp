// A1059 Counting Ones
// ��ǰ����kλ��leftΪ��kλ�ĸ�λ����ʾ���� now�ǵ�kλ right��λ����ʾ���� 
//���ڸ�λ���� left*a��
//����ʮλ������Ϊ��λ��Ҫͳ�Ƶ����� ��left * a + right + 1
//������(left+1)*a 
#include <stdio.h>

int main(){
	// a��ĳһλ���� ͳ��a������ 
	int n, a = 1, ans = 0;
	int left, now, right;
	scanf("%d", &n);
	// �Ӹ�λ����ʼ���� 
	while(n/a != 0)
	{
		left = n / (a * 10);//��kλ 
		now = n / a % 10;
		right = n % a;
		
		if(now == 0) ans += left * a; // ��λ 
		else if(now == 1) ans += left * a + right + 1; // ʮλ������Ϊʮλ����a�� 
		else ans += (left + 1) * a; // ���� 
		a *= 10; 
	}
	printf("%d\n", ans);
	return 0;
}
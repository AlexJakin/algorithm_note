// B1013 ������
// �������� �Ƚ���С��maxn�������� 
#include <stdio.h>
#include <cmath>

const int maxn = 1000010;

//�ж��Ƿ������� 
bool isPrime(int n)
{ 
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++)
		if(n % i == 0)
			return false;
 	return true;
}

int prime[maxn], num = 0;
bool p[maxn] ={0};
//���������� ���ֻ��Ҫn������ 
void Prime_list(int n)
{
	for(int i = 1; i < maxn; i++)
	{
		if(isPrime(i) == true)
		{
			prime[num++] = i;
			p[i] = true;
			if(num >= n) break; // ֻ��Ҫn������ 
		}
	}
}
int main(){
	// ��left�������������right������ 
	int left, right;
	int count = 0;// ���� ÿ10��һ�� 
	scanf("%d %d",&left, &right);
	Prime_list(right);
	//���
	for(int i = left; i <= right; i++)
	{
		printf("%d", prime[i - 1]);
		count ++;
		//���ʮ������ 
		if(count % 10 != 0 && i < right) printf(" ");
		else printf("\n");
	} 
	return 0;
} 
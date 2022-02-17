// A1096 Consecutive Factor
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;

int main(){
	LL n;
	scanf("%lld", &n);
	// anslen����������� anI�ǵ�һ������ 
	LL sqr = (LL)sqrt(1.0 * n), ansI = 0, ansLen = 0;
	
	//Ѱ���������� 
	for(int i = 2; i <= sqr; i++)
	{
		// temp�����˻� j�����������ж���i��ʼ�����Ƿ񹹳��������� 
		LL temp = 1, j = i;
		while(true)
		{
			temp *= j;
			if(n % temp != 0) break;
			// �����ǰ��iΪ�׵�����j-i+1��������� ����� 
			if(j - i + 1 > ansLen)
			{
				ansLen = j - i + 1; // ���³��� 
				ansI = i; // ���������������ײ� 
			}
			j++;
		}
	}
	if(ansLen == 0)// �޽� 
		printf("1\n%lld", n);
	else
	{
		printf("%lld\n", ansLen);
		for(int i = 0; i < ansLen; i++)
		{
			printf("%lld",  ansI + i);
			if(i < ansLen - 1)
				printf("*");
		}
	}
	return 0;
}
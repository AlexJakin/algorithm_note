// B1048���ּ���
#include <stdio.h>
#include <cstring>

const int maxn = 110;
char A[maxn], B[maxn], ans[maxn] = {0};

void reverse(char s[])
{
	int len = strlen(s);
	for(int i = 0; i < len/2; i++)
	{
		int temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}

int main(){
	//����A��B
	scanf("%s %s", A, B);
	reverse(A);
	reverse(B);
	int lenA = strlen(A);
	int lenB = strlen(B);
	//A B�ַ������
	int len = lenA > lenB ? lenA : lenB;
	
	//�Ӹ�λ��ʼ 
	for(int i = 0; i < len; i++)
	{
		int numA, numB;
		if(i < lenA) numA = A[i] - '0';
		else numA = 0;
		if(i < lenB) numB = B[i] - '0';
		else numB = 0;

		if(i % 2 == 0)//ż��
		{
			int temp = (numA + numB) % 13;
			if(temp == 10) ans[i] = 'J';
			else if(temp == 11) ans[i] = 'Q';
			else if(temp == 12) ans[i] = 'K';
			else ans[i] = temp + '0';
		}
		else // ż�� 
		{
			int temp = numB - numA;
			if(temp < 0) temp += 10;
			ans[i] = temp + '0';
		}
	}
	reverse(ans);
	puts(ans);
	return 0;
} 
// B1048数字加密
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
	//输入A和B
	scanf("%s %s", A, B);
	reverse(A);
	reverse(B);
	int lenA = strlen(A);
	int lenB = strlen(B);
	//A B字符串最长者
	int len = lenA > lenB ? lenA : lenB;
	
	//从个位开始 
	for(int i = 0; i < len; i++)
	{
		int numA, numB;
		if(i < lenA) numA = A[i] - '0';
		else numA = 0;
		if(i < lenB) numB = B[i] - '0';
		else numB = 0;

		if(i % 2 == 0)//偶数
		{
			int temp = (numA + numB) % 13;
			if(temp == 10) ans[i] = 'J';
			else if(temp == 11) ans[i] = 'Q';
			else if(temp == 12) ans[i] = 'K';
			else ans[i] = temp + '0';
		}
		else // 偶数 
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
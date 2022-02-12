// A1093 �м���PAT
#include <stdio.h>
#include <cstring>

const int maxn = 100010;
const int mod = 1000000007;
char str[maxn];
int leftNumP[maxn]= {0};  // ÿһλA���P�ĸ��� ����������¼P�ĸ�����һ���Ǹ������������飩 

int main(){
	gets(str);
	int len = strlen(str);
	//�����ַ��� ����P 
	for(int i = 0; i < len; i++)
	{
		if(i > 0) leftNumP[i] = leftNumP[i - 1];
		if(str[i] == 'P') leftNumP[i]++;
	}
	
	int ans = 0, rightNumT = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if(str[i] == 'T') rightNumT++;
		else if(str[i] == 'A') ans = (ans + leftNumP[i] * rightNumT) % mod;
	}
	//������
	printf("%d", ans); 
	return 0;
} 
// B1043 ���PATest
#include <stdio.h>
#include <cstring>

const int maxn = 10010;
char str[maxn];
char dict[6] = {
	'P', 'A', 'T', 'e', 's', 't'
};
int hashTable[6] = {0};
int main(){
	gets(str);
	int len = strlen(str);
	int sum = 0; // �ܹ�����ַ��� 
	//���¹�ϣ�� ʹ�ַ���ÿ���ַ������ֵ�Ƚ� ���Ӷ�o(n*m) 
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			if(str[i] == dict[j])
			{
				hashTable[j]++;
				sum++;
			}
		}
	}
	
	//���
	while(sum)
	{
		for(int i = 0; i < 6; i ++)
		{
			if(hashTable[i] > 0)
			{
				printf("%c", dict[i]);
				hashTable[i]--; //���ٴ���
				sum--; 
			}
		}
	} 
	return 0;
}
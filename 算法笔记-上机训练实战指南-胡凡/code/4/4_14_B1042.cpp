//B1042 �ַ�ͳ��
#include <stdio.h>
#include <cstring>

const int maxn= 1010;
char str[maxn]; // �ַ��� 
int hashTable[30]={0}; // ��¼���ִ��� 
int main(){
	gets(str);
	int len = strlen(str);
	//�����ֵ���ĸ��¼����ϣ�� 
	for(int i = 0; i < len; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z') hashTable[str[i] - 'a']++;
		else if(str[i] >= 'A' && str[i] <= 'Z') hashTable[str[i] - 'A']++;
	}
	//����Ƶ����ߵ���ĸ 
	int k = 0;
	for(int i = 0; i < 26; i++)
	{
		if(hashTable[i] > hashTable[k]) k = i; 
	}
	printf("%c %d", 'a' + k, hashTable[k]);
	return 0;
} 
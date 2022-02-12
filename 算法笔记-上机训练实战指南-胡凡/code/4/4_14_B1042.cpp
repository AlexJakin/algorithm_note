//B1042 字符统计
#include <stdio.h>
#include <cstring>

const int maxn= 1010;
char str[maxn]; // 字符串 
int hashTable[30]={0}; // 记录出现次数 
int main(){
	gets(str);
	int len = strlen(str);
	//将出现的字母记录到哈希表 
	for(int i = 0; i < len; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z') hashTable[str[i] - 'a']++;
		else if(str[i] >= 'A' && str[i] <= 'Z') hashTable[str[i] - 'A']++;
	}
	//出现频率最高的字母 
	int k = 0;
	for(int i = 0; i < 26; i++)
	{
		if(hashTable[i] > hashTable[k]) k = i; 
	}
	printf("%c %d", 'a' + k, hashTable[k]);
	return 0;
} 
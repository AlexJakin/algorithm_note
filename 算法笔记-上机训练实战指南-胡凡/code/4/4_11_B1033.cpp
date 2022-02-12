#include <stdio.h>
#include <cstring>

const int maxn = 10010;
//哈希表
bool hashTable[256] = {false}; 
char str1[maxn];
char str2[maxn];
int main(){
	
	gets(str1);//失灵的键位
	gets(str2);//欲输入的字符串 
	memset(hashTable, true, sizeof(hashTable));//初始化哈希表 
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	//处理哈希表
	for(int i = 0; i < len1;  i++)
	{
		//大写转小写 
		if(str1[i] >= 'A'  && str1[i] <= 'Z') str1[i] = str1[i] - 'A' + 'a';
		hashTable[str1[i]] = false; // 该键位失灵 
	} 
	//输出能输出的字符  
	for(int i = 0; i < len2; i++)
	{
		if(str2[i] >= 'A' && str2[i] <='Z')
		{
			int low = str2[i] - 'A' + 'a';
			if(hashTable[low] == true && hashTable['+'] == true)
				printf("%c", str2[i]);	
		}
		else if(hashTable[str2[i]] == true)
			printf("%c", str2[i]);
	}
	printf("\n");
	return 0;
}
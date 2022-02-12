//A1084 旧键盘 
// 主要是字符串比较 比较过程把缺的字符串转大写后放入哈希表 
#include <stdio.h>
#include <cstring>

bool HashTable[128] = {false};

int main(){
	char str1[100], str2[100];
	//输入两个字符串
	gets(str1); gets(str2);
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len1; i ++)
	{
		int j;
		char c1, c2;
		for(j = 0; j < len2; j++)
		{
			c1 = str1[i];
			c2 = str2[j];
			if(c1 >= 'a' && c2 <= 'z') c1 -= 32; // 转大写
			if(c2 >= 'a' && c2 <= 'z') c2 -= 32;
			if(c1 == c2) break; // c1 在第二个字符串中出现跳出循环继续往后 
		}
		if(j == len2 && HashTable[c1] == false)
		{
			printf("%c", c1);
			HashTable[c1] = true;
		}	
			 
	} 
	return 0;
}
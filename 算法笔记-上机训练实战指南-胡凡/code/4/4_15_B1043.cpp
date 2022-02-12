// B1043 输出PATest
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
	int sum = 0; // 总共输出字符数 
	//更新哈希表 使字符串每个字符都与字典比较 复杂度o(n*m) 
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
	
	//输出
	while(sum)
	{
		for(int i = 0; i < 6; i ++)
		{
			if(hashTable[i] > 0)
			{
				printf("%c", dict[i]);
				hashTable[i]--; //减少次数
				sum--; 
			}
		}
	} 
	return 0;
}
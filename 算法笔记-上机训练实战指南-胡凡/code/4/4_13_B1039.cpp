// B1039/A1092 到底买不买
#include <stdio.h>
#include <cstring>
const int maxn = 1010;
//记录第一串每种颜色的个数，用miss记录缺少的珠子数 
int hashTable[80] = {0}, miss = 0;

//将数字和字母转换为hashTable的下标
int change(char c)
{
	if(c >= '0' && c<= '9') return c - '0'; //数字 
	if(c >= 'a' && c<= 'z') return c - 'a' + 10; // 小写字母 
	if(c >= 'A' && c<= 'Z') return c - 'A' + 36; // 大写字母 
} 
int main(){
	char whole[maxn], target[maxn];
	gets(whole);//第一串
	gets(target);//目标串
	
	int len1 = strlen(whole);
	int len2 = strlen(target);
	
	//遍历第一串更新哈希表
	for(int i = 0; i < len1; i++)
	{
		int id = change(whole[i]);
		hashTable[id]++;
	}
	//遍历第二串
	for(int i = 0; i < len2; i++)
	{
		int id = change(target[i]);
		hashTable[id]--;
		if(hashTable[id] < 0) miss ++; //缺少珠子 
	}
	if(miss  > 0) printf("No %d\n", miss);
	else printf("Yes %d\n", len1 - len2);
	return 0;
} 
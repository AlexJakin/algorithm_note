//A1050 String Subtraction
#include <stdio.h>
#include <cstring>

const int max_len = 10005;
char a[max_len], b[max_len];
bool hashTable[128] = {false}; // 出现true表明不输出 

int main(){
	gets(a); gets(b);
	int len_a = strlen(a);
	int len_b = strlen(b);
	// 把第二串字符串放入哈希表 
	for(int i= 0; i < len_b; i++)
	{
		hashTable[b[i]]  = true;
	}
	//准备输出
	for(int i = 0; i < len_a; i++)
	{
		if(hashTable[a[i]] == false) printf("%c", a[i]);
	} 
	return 0;
} 
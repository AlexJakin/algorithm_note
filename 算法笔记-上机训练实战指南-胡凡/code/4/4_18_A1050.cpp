//A1050 String Subtraction
#include <stdio.h>
#include <cstring>

const int max_len = 10005;
char a[max_len], b[max_len];
bool hashTable[128] = {false}; // ����true��������� 

int main(){
	gets(a); gets(b);
	int len_a = strlen(a);
	int len_b = strlen(b);
	// �ѵڶ����ַ��������ϣ�� 
	for(int i= 0; i < len_b; i++)
	{
		hashTable[b[i]]  = true;
	}
	//׼�����
	for(int i = 0; i < len_a; i++)
	{
		if(hashTable[a[i]] == false) printf("%c", a[i]);
	} 
	return 0;
} 
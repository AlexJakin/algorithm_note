#include <stdio.h>
#include <cstring>

const int maxn = 10010;
//��ϣ��
bool hashTable[256] = {false}; 
char str1[maxn];
char str2[maxn];
int main(){
	
	gets(str1);//ʧ��ļ�λ
	gets(str2);//��������ַ��� 
	memset(hashTable, true, sizeof(hashTable));//��ʼ����ϣ�� 
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	//�����ϣ��
	for(int i = 0; i < len1;  i++)
	{
		//��дתСд 
		if(str1[i] >= 'A'  && str1[i] <= 'Z') str1[i] = str1[i] - 'A' + 'a';
		hashTable[str1[i]] = false; // �ü�λʧ�� 
	} 
	//�����������ַ�  
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
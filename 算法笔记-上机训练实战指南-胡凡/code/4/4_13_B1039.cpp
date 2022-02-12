// B1039/A1092 ��������
#include <stdio.h>
#include <cstring>
const int maxn = 1010;
//��¼��һ��ÿ����ɫ�ĸ�������miss��¼ȱ�ٵ������� 
int hashTable[80] = {0}, miss = 0;

//�����ֺ���ĸת��ΪhashTable���±�
int change(char c)
{
	if(c >= '0' && c<= '9') return c - '0'; //���� 
	if(c >= 'a' && c<= 'z') return c - 'a' + 10; // Сд��ĸ 
	if(c >= 'A' && c<= 'Z') return c - 'A' + 36; // ��д��ĸ 
} 
int main(){
	char whole[maxn], target[maxn];
	gets(whole);//��һ��
	gets(target);//Ŀ�괮
	
	int len1 = strlen(whole);
	int len2 = strlen(target);
	
	//������һ�����¹�ϣ��
	for(int i = 0; i < len1; i++)
	{
		int id = change(whole[i]);
		hashTable[id]++;
	}
	//�����ڶ���
	for(int i = 0; i < len2; i++)
	{
		int id = change(target[i]);
		hashTable[id]--;
		if(hashTable[id] < 0) miss ++; //ȱ������ 
	}
	if(miss  > 0) printf("No %d\n", miss);
	else printf("Yes %d\n", len1 - len2);
	return 0;
} 
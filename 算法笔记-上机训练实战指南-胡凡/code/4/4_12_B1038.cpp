//B1038 ͳ��ͬ�ɼ�ѧ��
#include <stdio.h>
#include <cstring>

using namespace std;

int hashTable[256] = {0};

int main(){
	// nΪѧ���� score���� k Ϊ��ѯ���� 
	int n, score, k;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &score);
		hashTable[score]++;
	}
	//��ѯ����
	scanf("%d", &k);
	for(int i = 0; i < k; i ++)
	{
		scanf("%d", &score);
		printf("%d", hashTable[score]);
		//ǰk-1����������ո� 
		if(i <  k - 1) printf(" ");
	} 
	return 0;
} 
//B1023 �����С��
//���ԣ�1-9ѡ��һ����Ϊ0������� 0-9ѡ����С����� 
#include <stdio.h>
#include <cstring>
//��¼0-9�ĸ���
int count[10];

int main(){
	for(int i = 0; i < 10; i++)
	{
		scanf("%d", &count[i]);
	}
	
	//��1-9��ѡ��count��Ϊ0����С������ ����������λ 
	for(int i = 1; i < 10; i++)
	{
		if(count[i] > 0)
		{
			printf("%d", i);
			count[i]--;
			break;
		}
	}
	// ��0-9������� ����С���ֿ�ʼ��� 
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < count[i]; j++)
		{
			printf("%d", i);
		}
	}
	return 0;
} 
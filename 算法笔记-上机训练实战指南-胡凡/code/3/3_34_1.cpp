//B1009 ˵���� ��һ�ֽⷨ 
#include <stdio.h>
#include <cstring>

int main(){
	char str[90];
	gets(str);
	int len = strlen(str), r = 0, h = 0;
	char ans[90][90]; //�洢���ӵĵ���
	
	//�������벿��
	//��str½������ans��
	for (int i = 0; i < len; i++)
	{
		if (str[i] != ' ')
			ans[r][h++] = str[i];
		else
		{
			h = 0;
			ans[++r][h] = '\0'; //������ 
		}
			
	} 
	
	//������� 
 	for(int i = r; i >= 0; i--)
 	{
	 	printf("%s", ans[i]);
		if(i > 0) printf(" ");	
 	}
	return 0;
}
#include <stdio.h>
#include <cmath>

int main(){
	int n;
	char c;
	scanf("%d %c", &n, &c);
	//�ȼ��������εױߵ��ַ���  
	int bottom = (int)sqrt(2.0 * (n + 1))-1;
	//����ױ���ż�� Ӧ�ü�һ������� 
	if(bottom % 2 == 0) bottom--;
	
	//�ܹ���������ַ��� 
	int used = (bottom + 1) * (bottom + 1)/2 -1;
	
	//��������� ÿ����һ������һ�� 
	for(int i = bottom; i >= 1;  i -= 2)
	{
		for(int j = 0; j < (bottom - i)/2; j++)
			printf(" "); // �ո����Ϊ(bottom - i)/2 
		for(int j = 0; j < i; j++)
			printf("%c", c);
		printf("\n");
	}
	
	//���������
	for(int i = 3; i <= bottom; i += 2)
	{
 		//��ӡ�ո�
		for (int j = 0;j < (bottom - i)/2; j++)
 			printf(" ");	
 		//��ӡ*
		 for (int j = 0; j < i; j++)
		 {
 			printf("%c", c);
 		}
 		printf("\n");
	}
	printf("%d\n", n - used);
	return 0;
}
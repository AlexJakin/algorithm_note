#include <cstdio>
int main(){
	int row, col;
	char c;
	
	//�������� �� ʹ�õ��ַ�
	scanf("%d %c", &col, &c);
	//���� 
	if(col % 2 == 1) row = col/2 + 1;
 	else row = col/2;
 	//��ӡ��һ��
	for (int i = 0; i < col; i++)
	{
		printf("%c", c);
	}
	printf("\n");
	//��ӡ�ڶ���
	for (int i = 2; i < row; i++)
	{
		printf("%c", c);
		for(int j = 0; j < col - 2; j ++)
		{
			printf(" ");
		}
		printf("%c", c);
		printf("\n");
	}
	//��ӡ��row��
	for (int i = 0; i < col; i++)
	{
		printf("%c", c);
	}
	return 0;
} 
 /**  ʹ�ö�ά���� **/ 
 #include <stdio.h>
 #include <cstring>
 
 int main(){
	char str[100]; //�ַ�����
 	char ans[40][40]; //�������
	//�������� 
	gets(str);
	//�ַ�����
	int N = strlen(str); 
	//����n1 n2 n3 
 	int n1 = (N + 1)/3; //����
	int n3 = n1; //���� 
	int n2 = N + 2 - n1 - n3;  // ��
	//��ʼ������ 
	for (int i = 0; i < n1; i++)
		for (int j = 0; j< n2; j++)
			ans[i][j] = ' ';
	//str�α� 
	int pos = 0;
	
	//����ans����
	//���� 
	for (int i = 0; i < n1; i++)
		ans[i][0] = str[pos++];
 	//��
 	for (int j = 1; j < n2; j++)
 		ans[n1-1][j] = str[pos++];
	//����
 	for (int i = n3 - 2; i >= 0; i--)
 		ans[i][n2-1] = str[pos++];
	
	//������
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
			printf("%c", ans[i][j]);
		printf("\n");
	}	
 	return 0;
 } 
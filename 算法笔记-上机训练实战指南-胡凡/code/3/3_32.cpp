//B1031 �������֤
 
#include <stdio.h>
#include <cstring>

//ǰ17λȨ��
int w[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char change[15] = {'1','0','X','9','8','7','6','5','4','3','2'};
int main(){
	int n;//���֤�� 
	scanf("%d", &n);
	bool flag = true;
	char str[18];//���֤
	
	for (int i = 0; i < n; i++)
	{
		int j = 0; // �����ж��Ƿ�Ϸ�
		int last =  0;
		for (int j = 0; j < 17; j++)
		{
			if(str[j] < '0' && str[j] > '9') break;
			last += (str[j] - '0') * w[j]; 
		}
		// ����һ��˵�����Ϸ� 
		if(j < 17)
		{
			//ǰ17λ���Ϸ� 
			flag = false;
			printf("%s\n", str);
		}
		else
		{
			//���һλУ���벻�Ϸ� 
			if(change[last % 11] != str[17])
			{
				flag = false;
				printf("%s\n", str);
			}	
		}
	}
	if(flag = true) printf("All passed\n");
	
	return 0;
}
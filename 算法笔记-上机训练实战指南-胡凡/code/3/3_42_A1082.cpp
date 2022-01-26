//A1082 Read Number in chinese
#include <stdio.h>
#include <cstring>

char num[10][6]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};  //��0-9��ƴ��
char position[5][5] = {"Shi","Bai","Qian","Wan","Yi"};  //��λ��ƴ��



int main(){
	char str[15];
	//��ȡ�ַ���
	gets(str);
	int len = strlen(str);
	
	//���Ľ���������λһ������ ������left��right������ 
	//leftָ��ͷ rightָ��β�� 
	int left = 0, right = len - 1;
	
	//�ȴ�����
	if(str[0] == '-')
	{
		printf("Fu");
		left++;
	} 
 	
 	//��right���ƣ�ʹ�ú�left��ͬһ��
	while(left + 4 <= right) right = right - 4;
	
	//����ÿһ������
	while (left < len)
	{
		//��flag��������������
		bool flag = false;
		//�Ƿ������������е�λ 
		bool isPrint = false;
		
		while(left <= right)
		{
			//��ǰλΪ0��left�Ϸ� 
			if(left > 0 && str[left] == '0')
				flag = true;
			else
			{
				//�����ۻ�0 
				if(flag == true)
				{
					printf(" ling");
					flag = false; 
				}
				//������λ ����ÿһλ����ո� 
				if(left > 0) printf(" ");
				printf("%s", num[str[left] - '0']);
				isPrint = true;
				if(left != right) printf(" %s", position[right - left - 1]);
			}
			left ++;
		}
		
		if(isPrint == true && right != len - 1)
			printf(" %s", position[(len  - right) / 4 + 2]);
		right += 4;
	} 
	return 0;
} 
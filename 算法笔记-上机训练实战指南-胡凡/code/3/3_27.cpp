#include <stdio.h>

//�ж�z[]�Ƿ��ǻ����� 
//num�����鳤��
bool Judge(int z[], int num)
{
	for (int i = 0; i <= num / 2; i++)
	{
		//����β��ʼ�ж� 
		if(z[i] != z[num - 1 -i])
			return false;
	}
	return true;
}

//��һ����ת��Ϊb���� �����z
int change_b(int n, int b, int z[])
{
	int num = 0;
	while(n != 0)
	{
		z[num++] = n % b;
		n /= b;
		
	}
	return num;
} 

int main(){
	int n, b, z[40], num = 0;
	bool flag;
	
	scanf("%d%d", &n, &b);
	
	//�Ƚ��н���ת��
	num = change_b(n, b, z);
	
	//�Ƿ�Ϊ������ 
	if(flag = true) printf("Yes\n");
	else printf("No\n");
	
	
	//�������z
	for(int i = num - 1; i >= 0; i--)
	{
		printf("%d", z[i]);
		if(i != 0) printf(" ");
	} 
	return 0;
}
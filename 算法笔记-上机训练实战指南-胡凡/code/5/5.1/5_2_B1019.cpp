#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

// �ǵݼ�
bool cmp_1(int a, int b)
{
	return a < b;
} 

// �ǵ���
bool cmp_2(int a, int b)
{
	return a > b;
}

//����λ������ת��Ϊ����
void to_array(int a, int num[])
{
	for(int i = 0; i < 4; i++)
	{
		num[i] = a % 10;
		a = a / 10;
	}
}

// ��num����תΪ����
int to_number(int num[])
{
	int sum = 0;
	for(int i = 0; i < 4; i++) sum = sum * 10 + num[i];
	return sum;
} 
int main(){
	int n; //  ��λ������ 
	int min, max; 
	scanf("%d", &n);
	
	int num[4]; 
 	while(1)
 	{
 		//��ȡ������ 
		to_array(n, num);
		sort(num, num + 4, cmp_1); // ��С��������
 		min = to_number(num);
	 	//��ȡ����
	  	sort(num, num + 4, cmp_2);
	  	max = to_number(num);
	  	n = max - min;
	  	printf("%04d - %04d = %04d\n", max, min, n);
	  	if(n == 0 || n == 6174) break;
 	}
 	return 0;
}
// B1017 A����B
//���������� 
#include <stdio.h>
#include <cstring>

char str1[1010], str2[1010];

struct bign{
	int d[1010];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};
// ������ת��Ϊbign 
bign change(char str[])
{
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++)
	{
		// ��λ��ǰ ��λ�ź� 
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a; 	
}
//��*���߾��ȳ��� 
bign divide(bign a, int b, int& r)
{
	bign c;
	c.len = a.len;
	for(int i = a.len - 1; i >= 0; i--)
	{
		// �Ӹ�λ��ʼ�� ��������Ĺ��� 
		r = r * 10 + a.d[i];
		if(r < b) // r������ 
			c.d[i] = 0;
		else // ���� 
		{
			c.d[i] = r / b;
			r = r % b;  
		}
	}
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0) //������λ��0 
	{
		c.len--;
	}
	return c;
} 
//���bign
void print_bign(bign a)
{
	for(int i = a.len - 1; i >= 0; i--)
	{
		printf("%d", a.d[i]);
	}
} 

int main(){
	// b �������� r���� 
	int b, r = 0;
	scanf("%s %d", str1, &b);
	bign a = change(str1);
	print_bign(divide(a, b, r));
	printf(" %d", r);
	return 0;
}
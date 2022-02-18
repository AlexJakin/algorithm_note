// A1023 Have Fun With Numbers
#include <stdio.h>
#include <cstring>

struct bign{
	int d[21];
	int len;
	bign()
	{
		memset(d, 0, sizeof(d));
		len = 0;	
	}
};

//������ת��Ϊbign
bign change(char str[])
{
	bign a;
	a.len = strlen(str);
	// �ѵ�λ��ǰ ��λ�ź� 
	for(int i = 0; i < a.len; i++)
		a.d[i] = str[a.len - i - 1] - '0';
	return a;
}

//�߾��ȳ˷�
bign multi(bign a, int b)
{
	bign c; // ���
	int carry = 0; // ��λ
	
	for(int i = 0; i < a.len; i++)
	{
		int temp = a.d[i] * b + carry; // ÿһλ���Գ��� ���� ��λ
		c.d[c.len++] = temp % 10;// ��λ������Ϊ�µĽ�λ
		carry = temp / 10;
	}
	// �ͼӷ���ͬ �˷��Ľ�λ���ܲ�ֹһλ 
	while(carry != 0)
	{
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

// �ж�b������λ��a��ĳ������
bool Judge(bign a, bign b)
{
	if(a.len != b.len) return false;
	int count[10] = {0};
	for(int i = 0; i < 10; i++)
	{
		count[a.d[i]] ++; // ԭ�� 
		count[b.d[i]] --;
	}
	for(int i = 0; i < 10; i++)
		if(count[i] != 0) 
			return false;
	return true;
} 

//���
void print(bign a)
{
	for(int i = a.len - 1; i >= 0; i--)
	{
		printf("%d", a.d[i]);
	}
}

int main(){
	char str[21];
	gets(str);
	bign a = change(str);
	bign mul = multi(a, 2);
	if(Judge(a, mul) == true)
		printf("Yes\n");
	else
		printf("No\n");
	print(mul);
	return 0;
	return 0;
}
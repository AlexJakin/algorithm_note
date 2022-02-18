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

//把整数转化为bign
bign change(char str[])
{
	bign a;
	a.len = strlen(str);
	// 把低位放前 高位放后 
	for(int i = 0; i < a.len; i++)
		a.d[i] = str[a.len - i - 1] - '0';
	return a;
}

//高精度乘法
bign multi(bign a, int b)
{
	bign c; // 结果
	int carry = 0; // 进位
	
	for(int i = 0; i < a.len; i++)
	{
		int temp = a.d[i] * b + carry; // 每一位乘以乘数 加上 进位
		c.d[c.len++] = temp % 10;// 高位部分作为新的进位
		carry = temp / 10;
	}
	// 和加法不同 乘法的进位可能不止一位 
	while(carry != 0)
	{
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

// 判断b的所有位是a的某个排列
bool Judge(bign a, bign b)
{
	if(a.len != b.len) return false;
	int count[10] = {0};
	for(int i = 0; i < 10; i++)
	{
		count[a.d[i]] ++; // 原串 
		count[b.d[i]] --;
	}
	for(int i = 0; i < 10; i++)
		if(count[i] != 0) 
			return false;
	return true;
} 

//输出
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
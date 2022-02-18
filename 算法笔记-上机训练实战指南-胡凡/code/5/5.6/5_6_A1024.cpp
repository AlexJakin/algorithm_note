// A1024 Palindromic Number
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

struct bign{
	int d[1000];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;	
	}	
};

//将整数转换为bign 
bign change(char str[])
{
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++)
	{
		a.d[i] = str[a.len - i - 1] - '0';
	}	
	return a;
}

// 高精度相加
bign add(bign a, bign b)
{
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++)
	{
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] =  temp % 10;
		carry = temp / 10;
	}
	if(carry != 0)
	{
		c.d[c.len++] = carry;
	}
	return c;
}

//判断是否是回文数 
bool Judge_huiwen(bign a)
{
	for(int i = 0; i <= a.len/2; i++)
	{
		if(a.d[i] != a.d[a.len - i - 1])
			return false;
	}
	return true;
}

//输出
void print(bign a)
{
	for(int i = a.len - 1; i >= 0; i--)
		printf("%d", a.d[i]);
	printf("\n");
}

int main(){
	char str[1000];
	int T, k = 0;
	// 初始数字 操作上限 
	scanf("%s %d",  str, &T);
	bign a = change(str);
	//不超过操作上限且a是非回文
	while(k < T && Judge_huiwen(a) == false)
	{
		bign b = a;
		reverse(b.d, b.d + b.len);
		a = add(a, b);
		k++; // 操作次数加一 
	}
	print(a);
	printf("%d\n", k); // 操作次数 
	return 0;
}
// B1017 A除以B
//大整数运算 
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
// 将整数转换为bign 
bign change(char str[])
{
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++)
	{
		// 低位放前 高位放后 
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a; 	
}
//（*）高精度除法 
bign divide(bign a, int b, int& r)
{
	bign c;
	c.len = a.len;
	for(int i = a.len - 1; i >= 0; i--)
	{
		// 从高位开始除 满足除法的过程 
		r = r * 10 + a.d[i];
		if(r < b) // r不够除 
			c.d[i] = 0;
		else // 够除 
		{
			c.d[i] = r / b;
			r = r % b;  
		}
	}
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0) //除掉高位的0 
	{
		c.len--;
	}
	return c;
} 
//输出bign
void print_bign(bign a)
{
	for(int i = a.len - 1; i >= 0; i--)
	{
		printf("%d", a.d[i]);
	}
} 

int main(){
	// b 被除整数 r余数 
	int b, r = 0;
	scanf("%s %d", str1, &b);
	bign a = change(str1);
	print_bign(divide(a, b, r));
	printf(" %d", r);
	return 0;
}
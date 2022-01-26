// A1077 Kuchiguse
#include <stdio.h>
#include <cstring>

char s[100][256];//最多100条字符串 一条字符串256个字符

//字符串反转
void reverse(char s[])
{
	int len = strlen(s);
	for(int i = 0; i < len/2; i ++)
	{
		char temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
} 

int main(){
	//字符串数
	int n;
	int minlen;//最小字符串 
	scanf("%d", &n);
	getchar();//接收换行 
	//使用gets来接收字符串 不使用scanf 因为字符串可能存放空格
	for(int i = 0; i < n; i++)
	{
		gets(s[i]);
		int len = strlen(s[i]);
		if(len < minlen) minlen = len;
		//反转字符串  将求公共后缀问题变成求公共前缀
		reverse(s[i]); 
	}
	
	//公共前缀计数器 若有一个字符相同 则加一 
	//用输出的时候定位 在公共前缀下从后往前输出变成公共后缀 
	int ans = 0;
	
	//判断所有字符串第i个字符串是否全部相等
	for(int i = 0; i < minlen; i++)
	{
		char c = s[0][i];
		bool same = true; //是否相同
		//枚举另外其他j字符串 
		for(int j = 1; j < n ; j++)
		{
			if(s[j][i] != c)
			{
				same = false;
				break;
			}
		}
		if(same) ans++; //相同继续往后查找 
		else break; //不相同 
	}
	
	//输出
	if(ans)
	{
		for(int i = ans - 1; i >= 0; i--)
		{
			printf("%c", s[0][i]);
		}
	}
	else
	{
		printf("nai");
	}
	return 0;
} 
// A1005 Spell it right 
#include <stdio.h>
#include <cstring>

char num[10][10] = {
	"zero", "one", "two", "three", "four", "five",
	"six", "seven", "eight", "nine"
};
//初始字符串 
char s[111];
int digit[10];
 
int main(){
	gets(s);
	int len = strlen(s);
	
	//sum为数位之和numlen是sum的长度
	int sum = 0, numLen = 0;
	for(int i = 0; i < len; i++)
	{
		//求sum 
		sum += (s[i] - '0');
	}
	//特判 
	if(sum == 0)
		printf("%s",num[0]);
	else
	{
		while(sum != 0)
		{
			//将sum的各位数字放入digit中 
			digit[numLen++] = sum % 10;
			sum /= 10;
		}
		
	}
	for(int i = numLen - 1; i >= 0; i--)
	{
		printf("%s", num[digit[i]]);
		if(i !=  0) printf(" ");
	}
	return 0;
} 

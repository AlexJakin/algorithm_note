// A1005 Spell it right 
#include <stdio.h>
#include <cstring>

char num[10][10] = {
	"zero", "one", "two", "three", "four", "five",
	"six", "seven", "eight", "nine"
};
//��ʼ�ַ��� 
char s[111];
int digit[10];
 
int main(){
	gets(s);
	int len = strlen(s);
	
	//sumΪ��λ֮��numlen��sum�ĳ���
	int sum = 0, numLen = 0;
	for(int i = 0; i < len; i++)
	{
		//��sum 
		sum += (s[i] - '0');
	}
	//���� 
	if(sum == 0)
		printf("%s",num[0]);
	else
	{
		while(sum != 0)
		{
			//��sum�ĸ�λ���ַ���digit�� 
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

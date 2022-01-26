//B1009 说反话 第一种解法 
#include <stdio.h>
#include <cstring>

int main(){
	char str[90];
	gets(str);
	int len = strlen(str), r = 0, h = 0;
	char ans[90][90]; //存储句子的单词
	
	//处理输入部分
	//将str陆续放入ans中
	for (int i = 0; i < len; i++)
	{
		if (str[i] != ' ')
			ans[r][h++] = str[i];
		else
		{
			h = 0;
			ans[++r][h] = '\0'; //结束符 
		}
			
	} 
	
	//倒序输出 
 	for(int i = r; i >= 0; i--)
 	{
	 	printf("%s", ans[i]);
		if(i > 0) printf(" ");	
 	}
	return 0;
}
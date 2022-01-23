//B1021
#include <stdio.h>
#include <cstring>

int main(){
	char str[1010];
	gets(str);
	int len = strlen(str);
	
	//记录 0 ~ 9 的出现次数
	int count[10]= {0};
	for(int i = 0; i < len; i++)
	{
		count[str[i] - '0']++;
	}
	
	//枚举输出
	for (int i = 0; i < 10; i++)
	{
		if(count[i] != 0)
			printf("%d:%d\n", i, count[i]);
	} 
	return 0;
} 
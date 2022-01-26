// B1024 科学计数法 

#include <stdio.h>
#include <cstring>
 
int main(){
	char str[10010];
	gets(str);
	int len = strlen(str);
	if(str[0] == '-') printf("-");
	
	int pos = 0; // pos存放字符串E的位置
	while (str[pos] != 'E') pos ++;
	
	// 存放指数 
	int exp = 0;
	for (int i = pos + 2; i < len ; i++)
		exp = exp * 10 + (str[i] - '0');
	
	// 指数为0的情况 
	if(exp == 0)
	{
		for (int i = 0; i < exp - 1; i++) printf("%c", str[i]);
	}
	
	// 指数为负
	if (str[pos + 1] == '-')
	{
		printf("0.");
		for(int i = 0; i < exp - 1; i++) printf("0");
		// 从小数点之前的那个数字输出 
		printf("%c", str[1]);
		// 从小数点后开始输出 
		for (int i = 3; i < pos; i++) printf("%c", str[i]);
	}
	else //指数为正 
	{
		for (int i = 1; i < pos; i++)
		{
			if(str[i] == '.') continue;
			printf("%c", str[i]);
			//小数点在exp + 2 
			if(i == exp + 2 && pos - 3 != exp) printf("."); 
		}
		
		//exp过大
		for(int i = 0; i< exp - (pos - 3); i ++) printf("0"); 
	}
	
	return 0;
} 
#include <cstdio>
int main(){
	int row, col;
	char c;
	
	//输入列数 和 使用的字符
	scanf("%d %c", &col, &c);
	//求行 
	if(col % 2 == 1) row = col/2 + 1;
 	else row = col/2;
 	//打印第一行
	for (int i = 0; i < col; i++)
	{
		printf("%c", c);
	}
	printf("\n");
	//打印第二行
	for (int i = 2; i < row; i++)
	{
		printf("%c", c);
		for(int j = 0; j < col - 2; j ++)
		{
			printf(" ");
		}
		printf("%c", c);
		printf("\n");
	}
	//打印第row行
	for (int i = 0; i < col; i++)
	{
		printf("%c", c);
	}
	return 0;
} 
 /**  使用二维数组 **/ 
 #include <stdio.h>
 #include <cstring>
 
 int main(){
	char str[100]; //字符数组
 	char ans[40][40]; //结果数组
	//输入数组 
	gets(str);
	//字符长度
	int N = strlen(str); 
	//计算n1 n2 n3 
 	int n1 = (N + 1)/3; //左竖
	int n3 = n1; //右竖 
	int n2 = N + 2 - n1 - n3;  // 横
	//初始化数组 
	for (int i = 0; i < n1; i++)
		for (int j = 0; j< n2; j++)
			ans[i][j] = ' ';
	//str游标 
	int pos = 0;
	
	//处理ans数组
	//左竖 
	for (int i = 0; i < n1; i++)
		ans[i][0] = str[pos++];
 	//横
 	for (int j = 1; j < n2; j++)
 		ans[n1-1][j] = str[pos++];
	//右竖
 	for (int i = n3 - 2; i >= 0; i--)
 		ans[i][n2-1] = str[pos++];
	
	//输出结果
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
			printf("%c", ans[i][j]);
		printf("\n");
	}	
 	return 0;
 } 
//B1009 说反话 第二种解法
//注意使用ctrl+z结束输入 
 
#include <stdio.h>
#include <cstring>

int main(){
	int nums = 0;
	int ans[80][80];
	while(scanf("%s", ans[nums]) != EOF) nums++; // 统计单词的个数
	
	//逆向输出 
	for(int i = nums - 1; i >= 0; i--)
	{
		printf("%s", ans[i]);
		if(i > 0) printf(" ");
	}
	return 0;
}
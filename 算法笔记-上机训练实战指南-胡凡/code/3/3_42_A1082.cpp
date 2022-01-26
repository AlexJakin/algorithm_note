//A1082 Read Number in chinese
#include <stdio.h>
#include <cstring>

char num[10][6]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};  //放0-9的拼音
char position[5][5] = {"Shi","Bai","Qian","Wan","Yi"};  //放位数拼音



int main(){
	char str[15];
	//获取字符串
	gets(str);
	int len = strlen(str);
	
	//中文叫数字是四位一组来叫 所以用left和right来控制 
	//left指向头 right指向尾部 
	int left = 0, right = len - 1;
	
	//先处理负号
	if(str[0] == '-')
	{
		printf("Fu");
		left++;
	} 
 	
 	//将right左移，使得和left在同一组
	while(left + 4 <= right) right = right - 4;
	
	//处理每一组数字
	while (left < len)
	{
		//用flag来处理连续的零
		bool flag = false;
		//是否该组输出过其中的位 
		bool isPrint = false;
		
		while(left <= right)
		{
			//当前位为0且left合法 
			if(left > 0 && str[left] == '0')
				flag = true;
			else
			{
				//存在累积0 
				if(flag == true)
				{
					printf(" ling");
					flag = false; 
				}
				//不是首位 后面每一位输出空格 
				if(left > 0) printf(" ");
				printf("%s", num[str[left] - '0']);
				isPrint = true;
				if(left != right) printf(" %s", position[right - left - 1]);
			}
			left ++;
		}
		
		if(isPrint == true && right != len - 1)
			printf(" %s", position[(len  - right) / 4 + 2]);
		right += 4;
	} 
	return 0;
} 
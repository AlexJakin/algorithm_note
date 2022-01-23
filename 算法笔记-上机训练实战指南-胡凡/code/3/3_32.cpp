//B1031 查验身份证
 
#include <stdio.h>
#include <cstring>

//前17位权重
int w[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char change[15] = {'1','0','X','9','8','7','6','5','4','3','2'};
int main(){
	int n;//身份证数 
	scanf("%d", &n);
	bool flag = true;
	char str[18];//身份证
	
	for (int i = 0; i < n; i++)
	{
		int j = 0; // 用于判断是否合法
		int last =  0;
		for (int j = 0; j < 17; j++)
		{
			if(str[j] < '0' && str[j] > '9') break;
			last += (str[j] - '0') * w[j]; 
		}
		// 遍历一半说明不合法 
		if(j < 17)
		{
			//前17位不合法 
			flag = false;
			printf("%s\n", str);
		}
		else
		{
			//最后一位校验码不合法 
			if(change[last % 11] != str[17])
			{
				flag = false;
				printf("%s\n", str);
			}	
		}
	}
	if(flag = true) printf("All passed\n");
	
	return 0;
}
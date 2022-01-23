#include <stdio.h>

//判断z[]是否是回文数 
//num是数组长度
bool Judge(int z[], int num)
{
	for (int i = 0; i <= num / 2; i++)
	{
		//从首尾开始判断 
		if(z[i] != z[num - 1 -i])
			return false;
	}
	return true;
}

//将一个数转化为b进制 存放在z
int change_b(int n, int b, int z[])
{
	int num = 0;
	while(n != 0)
	{
		z[num++] = n % b;
		n /= b;
		
	}
	return num;
} 

int main(){
	int n, b, z[40], num = 0;
	bool flag;
	
	scanf("%d%d", &n, &b);
	
	//先进行进制转化
	num = change_b(n, b, z);
	
	//是否为回文数 
	if(flag = true) printf("Yes\n");
	else printf("No\n");
	
	
	//输出数组z
	for(int i = num - 1; i >= 0; i--)
	{
		printf("%d", z[i]);
		if(i != 0) printf(" ");
	} 
	return 0;
}
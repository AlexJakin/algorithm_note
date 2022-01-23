/**

1 galleon = 17 sickle
1 sickle = 29 knut

货币 ： galleon.sickle(17).knut(29) 

**/
#include <stdio.h>

int main(){
	// a，b是计算对象
	// c 存放结果 
	int a[3], b[3], c[3];
	scanf("%d.%d.%d %d.%d.%d",  &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
	
	//储存进位
 	int carry = 0;
 	//从末位开始计算
	c[2] = (a[2] + b[2])%29;
	carry =  (a[2] + b[2])/29;//进位
	
	//计算第二位 
	c[1] = (a[1] + b[1] + carry)%17;
	carry = (a[1] + b[1] + carry)/17;
	
	//计算最高位
	c[0] = a[0] + b[0] +  carry;
	
	printf("%d.%d.%d", c[0], c[1], c[2]); 
	return 0;
}
//由于表示范围[0, 168] 两位13进制范围为[0, 168] 
#include <stdio.h>

char radix[13] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'
};

int main(){
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	printf("#");
	
	//输出
	printf("%c%c", radix[r / 13], radix[r % 13]);
	printf("%c%c", radix[g / 13], radix[g % 13]);
	printf("%c%c", radix[b / 13], radix[b % 13]);
	return 0;
}
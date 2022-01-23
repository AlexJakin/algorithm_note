#include <stdio.h>

const int galleon = 17*29; // 一个galleon可以换17*29个knut 
const int sickle = 29; // 一个sickle可以换29个knut 

int main(){
	int a1, b1, c1;
	int a2, b2, c2;
	scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
	
	int price = a1 * galleon + b1 * sickle+ c1;
	int money = a2 * galleon + b2 * sickle+ c2;
	
	//找回的零钱
	int change = money - price;
	
	//如果不够钱 提前输入负号
	if(change < 0)
	{
		printf("-");
		change = -change;
	} 
	printf("%d.%d.%d\n", change/galleon, change%galleon/sickle, change%sickle);
	return 0;
}
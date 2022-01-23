#include <stdio.h>

int main(){
	int i, n, failA = 0, failB = 0;
 	scanf("%d", &n);
 	for(i = 0; i < n; i++){
 		int a1, a2, b1, b2;
		scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
		if(a1 + b1 == a2 && a1 + b1 != b2)
			failB++;
		if(a1 + b1 == b2 && a1 + b1 != a2)
			failA++;
	}
	printf("结果：甲输%次，乙输%d次\n", failA, failB);
	return 0;
} 
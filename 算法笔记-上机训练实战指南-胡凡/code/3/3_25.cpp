// B1022 D���Ƶ�A+B
#include <stdio.h>

int main(){
	int a, b, d;
	scanf("%d %d %d", &a, &b, &d);
	int sum = a + b;
	int ans[31] = {0};
	int num = 0;
	
	while(sum != 0)//ֱ����Ϊ0 
	{
		ans[num++] = sum % d; //�洢˳���ǴӸ�λ����λ 
		sum /= d;
	}
	//������
	for(int i = num - 1; i >= 0; i--)
		printf("%d", ans[i]); 
	return 0;
} 
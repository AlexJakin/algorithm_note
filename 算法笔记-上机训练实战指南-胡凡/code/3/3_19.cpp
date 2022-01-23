#include <stdio.h>
char S[3] = {
	'W', 'T', 'L'
};

int main(){
	double ans = 1.0, tmp, a;
	//记录每行最大数字的下标 
	int idx;
 	for(int i = 0; i < 3; i++)
 	{
		tmp = 0.0;
		//找出每行最大的数2 
		for(int j = 0; j < 3; j++)
		{
			scanf("%lf", &a);
			if(a > tmp)
			{
				tmp = a;
				idx = j;
			}	
		} 	
		ans *= tmp;
		printf("%c ", S[idx]);
	}
	printf("%.2f", (ans*0.65 - 1)*2);
	return 0;
}

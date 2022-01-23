#include <stdio.h>

int main()
{
	int T;
	int tcase = 1;
	scanf("%d", &T);
	while(--T)
	{
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if(a+b =< c){
			printf("Case #%d: false\n",  tcase++);
		}else{
			printf("Case #%d: true\n",  tcase++); 
		}
	}
	return 0;
} 
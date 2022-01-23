#include <stdio.h>

typedef long long ll;

int main(){
	int T, tcase = 1;
	scanf("%d", &T);
	while(T--)
	{
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		ll res = a + b;
		bool flag;
		//正溢出 和 无溢出A+B>C 都为true
		//负溢出 和 无溢出A+B<<C 都为false
		if(a > 0 && b > 0 && res < 0) flag = true;
		else if(res > c) flag = true;
		else if(a < 0 && b < 0 && res > 0) flag = false;
		else flag= false;
		if(flag == true) printf("Case #%d：true\n", tcase++);
		if(flag == false) printf("Case #%d：false\n", tcase++);
	}
	return 0;
}
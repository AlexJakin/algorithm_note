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
		//����� �� �����A+B>C ��Ϊtrue
		//����� �� �����A+B<<C ��Ϊfalse
		if(a > 0 && b > 0 && res < 0) flag = true;
		else if(res > c) flag = true;
		else if(a < 0 && b < 0 && res > 0) flag = false;
		else flag= false;
		if(flag == true) printf("Case #%d��true\n", tcase++);
		if(flag == false) printf("Case #%d��false\n", tcase++);
	}
	return 0;
}
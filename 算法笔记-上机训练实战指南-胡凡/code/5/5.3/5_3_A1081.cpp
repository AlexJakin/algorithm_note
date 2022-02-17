// A1081 Rational Sum
//分数四则运算
 #include <stdio.h>
 #include <algorithm>
 using namespace std;
 typedef long long ll;
 
// 求a与b的最大公约数
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
 //分数 
struct Fraction{
	ll up, down; // 分子 分母 
};
 //化简 上下同除分子分母的最大公倍数
Fraction reduction(Fraction result)
{
 	//分母为负数 令分子分母为相反数 
 	if(result.down < 0)
 	{
		result.up = - result.up;
		result.down = - result.down;	
 	}
 	//化简 
 	if(result.up == 0)
 	{
	 	result.down = 1;
 	}
 	else
 	{
 		// 求最大公倍数d 分子分母同除 
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;	
 	}
 	return result; 
}
// 输出结果 
void showResult(Fraction f)
{
	reduction(f);
	if(f.down == 1)// 整数
		printf("%lld\n", f.up); 
	else if(abs(f.up) > f.down)// 假分数 
		printf("%lld %lld/%lld\n", f.up / f.down, abs(f.up)%f.down, f.down);
	else printf("%lld/%lld\n", f.up, f.down);
}
Fraction add(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}
int main(){
	// 输入求和个数 
	int n;
	scanf("%d", &n);
	//求和结果 
	Fraction sum, temp;
	sum.up = 0, sum.down = 1;
	// 一边输入一边相加 
	for(int i = 0; i < n; i++)
	{
		scanf("%lld/%lld", &temp.up, &temp.down);
		sum = add(sum, temp);
	}
	showResult(sum);
	return 0;
}
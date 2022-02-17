//A1088 有理数四则运算 加减乘除 
//A1088 Rational Arithmetic
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

//分数
struct Fraction{
	ll up, down;// 分子分母 
}a, b;

// 求最大公约数
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a%b);
}

//化简
Fraction reduction(Fraction f)
{
	//化简符号
	if(f.down < 0)
	{
		f.up = - f.up;
		f.down = - f.down;
	}
	//分子分母化简
	if(f.up == 0)
	{
		f.down = 1;
	}
	else
	{
		int d = gcd(abs(f.up), abs(f.down));
		f.up /= d;
		f.down /= d;
	}
	return f;
}
// 加
Fraction add(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}
// 减
Fraction minu(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up * f2.down - f1.down * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}
//乘
Fraction multi(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}
//除
Fraction divide(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}
//输出
void showResult(Fraction f)
{
	reduction(f);
	if(f.up < 0) 
		printf("(");
	if(f.down == 1) 
		printf("%lld", f.up); // 整数
	else if(abs(f.up) > f.down) 
		printf("%lld %lld/%lld", f.up / f.down, f.up % f.down, f.down);
	else
		printf("%lld/%lld", f.up, f.down);
	if(f.up < 0) printf(")");
} 
int main(){
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	// 加法
 	showResult(a); printf(" + "); showResult(b); printf(" = ");
 	showResult(add(a, b)); printf("\n");
 	
 	// 减法
	showResult(a); printf(" - "); showResult(b); printf(" = ");
	showResult(minu(a, b)); printf("\n");
	
	// 乘法
	showResult(a); printf(" * "); showResult(b); printf(" = ");
	showResult(multi(a, b)); printf("\n");
	
	// 除法
	showResult(a); printf(" / "); showResult(b); printf(" = ");
	if(b.up == 0) printf("Inf");
	else showResult(divide(a, b));
	printf("\n");
	return 0;
}
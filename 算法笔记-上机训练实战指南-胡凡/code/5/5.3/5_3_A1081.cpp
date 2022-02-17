// A1081 Rational Sum
//������������
 #include <stdio.h>
 #include <algorithm>
 using namespace std;
 typedef long long ll;
 
// ��a��b�����Լ��
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
 //���� 
struct Fraction{
	ll up, down; // ���� ��ĸ 
};
 //���� ����ͬ�����ӷ�ĸ����󹫱���
Fraction reduction(Fraction result)
{
 	//��ĸΪ���� ����ӷ�ĸΪ�෴�� 
 	if(result.down < 0)
 	{
		result.up = - result.up;
		result.down = - result.down;	
 	}
 	//���� 
 	if(result.up == 0)
 	{
	 	result.down = 1;
 	}
 	else
 	{
 		// ����󹫱���d ���ӷ�ĸͬ�� 
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;	
 	}
 	return result; 
}
// ������ 
void showResult(Fraction f)
{
	reduction(f);
	if(f.down == 1)// ����
		printf("%lld\n", f.up); 
	else if(abs(f.up) > f.down)// �ٷ��� 
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
	// ������͸��� 
	int n;
	scanf("%d", &n);
	//��ͽ�� 
	Fraction sum, temp;
	sum.up = 0, sum.down = 1;
	// һ������һ����� 
	for(int i = 0; i < n; i++)
	{
		scanf("%lld/%lld", &temp.up, &temp.down);
		sum = add(sum, temp);
	}
	showResult(sum);
	return 0;
}
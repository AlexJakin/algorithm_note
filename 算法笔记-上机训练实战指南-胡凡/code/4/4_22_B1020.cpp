// B1020/A1070 月饼
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
struct mooncake{
	double store; // 库存量 
	double sell; // 总售价 
	double price; // 单价	
}cake[1010];
bool cmp(mooncake a, mooncake b)// 由高到低排序 
{
	return a.price > b.price;
}
int main(){
	int n; // 月饼种类 
	double d; // 市场最大需求量 
	scanf("%d%lf", &n, &d);
	// 库存 
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &cake[i].store);
	}
	//计算每一件的单价 
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &cake[i].sell);
		cake[i].price = cake[i].sell / cake[i].store;
	}
	// 按照单价排序 
	sort(cake, cake + n, cmp);
	
	// 收益 
	double ans = 0;
	for(int i = 0; i < n; i++)
	{
		//需求量大于月饼库存量 
		if(cake[i].store <= d)
		{
			d -= cake[i].store;
			ans += cake[i].sell; 
		}
		else
		{
			ans += cake[i].price * d;
			break;	
		}
	}
	printf("%.2f\n", ans);
	return 0;
} 
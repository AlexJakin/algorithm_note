// A1033 To Fill or No to Fill
// 起点与终点距离为D 油箱最大油量为Cmax 
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 510;
const int INF = 1000000000;
struct station{
	double price, dis; // 价格 和 起点距离 
}st[maxn];
//按距离小到大比较
bool cmp(station a, station b)
{
	return a.dis < b.dis;
} 
int main(){
	int n;
	double Cmax, D, Davg;
	scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &n);
	//每个加油站的价格和距离 
	for(int i = 0; i < n; i++)
		scanf("%lf %lf", &st[i].price, &st[i].dis);
	//终点加油站 
	st[n].price = 0;
 	st[n].dis = D;
 	// 按距离从小到大排序 
 	sort(st, st + n, cmp);
 	// 排序后第一个加油站距离不是0，说明无法前进
	if(st[0].dis != 0) printf("The maximun travel distance = 0.0\n");
	else
	{
		//当前所处的加油站编号 
		int now = 0;
		// 总费用 当前油量 满油行驶距离 
		double ans = 0, nowTank = 0, MAX = Cmax * Davg;
		
		//每次循环将选出下一个需要到达的加油站
		while(now < n)
		{
			//选出第一个油价低于当前油价加油站
			int k = -1;
			double priceMin = INF;
			for(int i = now + 1; i <= n && st[i].dis - st[now].dis <= MAX; i++)
			{
				if(st[i].price < priceMin)
				{
					priceMin = st[i].price;
				 	k = i;
				 	//如果找到第一个油价低于当前油价的加油站
					 if(priceMin < st[now].price) break; 
				}
			}
			// 说明找不到加油站 
			if(k = -1) break;
			//从now 到 k需要油量 
		 	double need = (st[k].dis - st[now].dis) / Davg;
		 	if(priceMin < st[now].price)
		 	{
	 			if(nowTank < need)
	 			{
			 		 ans += (need - nowTank) * st[now].price;
			 		 nowTank = 0; // 到达加油站k油量为0 
			 	}
			 	else
			 	{
	 				nowTank -= need; 
	 			} 
	 		}
	 		else//加油站k油价高于当当前油价 
	 		{
		 		ans +=  (Cmax - nowTank) * st[now].price;
				nowTank = Cmax - need;	
		 	}
		 	now = k;
		}
		if(now == n) printf("%.2f\n", ans);
		else printf("The maximun travel distance = %.2f\n", st[now].dis + MAX);
	} 
	return 0;
}
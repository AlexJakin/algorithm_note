// A1033 To Fill or No to Fill
// ������յ����ΪD �����������ΪCmax 
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 510;
const int INF = 1000000000;
struct station{
	double price, dis; // �۸� �� ������ 
}st[maxn];
//������С����Ƚ�
bool cmp(station a, station b)
{
	return a.dis < b.dis;
} 
int main(){
	int n;
	double Cmax, D, Davg;
	scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &n);
	//ÿ������վ�ļ۸�;��� 
	for(int i = 0; i < n; i++)
		scanf("%lf %lf", &st[i].price, &st[i].dis);
	//�յ����վ 
	st[n].price = 0;
 	st[n].dis = D;
 	// �������С�������� 
 	sort(st, st + n, cmp);
 	// ������һ������վ���벻��0��˵���޷�ǰ��
	if(st[0].dis != 0) printf("The maximun travel distance = 0.0\n");
	else
	{
		//��ǰ�����ļ���վ��� 
		int now = 0;
		// �ܷ��� ��ǰ���� ������ʻ���� 
		double ans = 0, nowTank = 0, MAX = Cmax * Davg;
		
		//ÿ��ѭ����ѡ����һ����Ҫ����ļ���վ
		while(now < n)
		{
			//ѡ����һ���ͼ۵��ڵ�ǰ�ͼۼ���վ
			int k = -1;
			double priceMin = INF;
			for(int i = now + 1; i <= n && st[i].dis - st[now].dis <= MAX; i++)
			{
				if(st[i].price < priceMin)
				{
					priceMin = st[i].price;
				 	k = i;
				 	//����ҵ���һ���ͼ۵��ڵ�ǰ�ͼ۵ļ���վ
					 if(priceMin < st[now].price) break; 
				}
			}
			// ˵���Ҳ�������վ 
			if(k = -1) break;
			//��now �� k��Ҫ���� 
		 	double need = (st[k].dis - st[now].dis) / Davg;
		 	if(priceMin < st[now].price)
		 	{
	 			if(nowTank < need)
	 			{
			 		 ans += (need - nowTank) * st[now].price;
			 		 nowTank = 0; // �������վk����Ϊ0 
			 	}
			 	else
			 	{
	 				nowTank -= need; 
	 			} 
	 		}
	 		else//����վk�ͼ۸��ڵ���ǰ�ͼ� 
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
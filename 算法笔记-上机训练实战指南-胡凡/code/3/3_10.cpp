/**
A1046. Shortest Distance

**/
#include <stdio.h>

const int MAXN = 100005;
//dis[i]表示1号节点按顺时针到达的 i+1结点 的距离  A[i]表示i与i+1顶点的距离 
int dis[MAXN], A[MAXN];

//不用中间变量的交换 
int swap(int &a, int &b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}

int min(int a, int b)
{
	if(a > b) return b;
	else return a;
}

int main(){
	/**
	sum：一圈权值总和
	n：结点数
	query：查询最短路径数
 	left right：起点->终点的权值 
	**/
	int sum = 0, n, query, left, right;
	// 顶点数 
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
		sum += A[i];
		dis[i] = sum; //预处理dis 表示顶点1到顶点i+1的距离
	}
	scanf("&d", &query);
	for(int i = 0; i < query; i++)
	{
		scanf("%d%d", &left, &right);
		if(left > right) swap(left, right);
		int temp = dis[right - 1] - dis[left - 1];
		printf("%d\n", min(temp, sum - temp)); //逆时针权值相当于sum减去顺时针 
	}
	return 0;
}
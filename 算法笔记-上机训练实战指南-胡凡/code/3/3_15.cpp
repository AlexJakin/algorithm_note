/**
B1041 考试座位号
利用试机座位号为索引 
**/
#include <stdio.h>

const int maxn = 1010;
//学生
struct Student{
	long long id; // 准考证 
	int examSeat; // 考试座位号 
}testSeat[maxn];

int main(){
	int n, m, Tseat, examSeat;
	long long id;
	//考生人数
	scanf("%d", &n);
	
	//输入考生人数 
	for(int i = 0; i < n; i++)
	{
		scanf("%lld %d %d", &id, &Tseat, &examSeat);
		testSeat[Tseat].id = id;
		testSeat[Tseat].examSeat = examSeat;
	}
	
	
	//查询学生数 
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &Tseat);
		printf("%lld %d\n", testSeat[Tseat].id, testSeat[Tseat].examSeat);
	}
	return 0;
}
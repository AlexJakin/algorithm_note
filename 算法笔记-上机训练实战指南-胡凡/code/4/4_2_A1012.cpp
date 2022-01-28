//  A1012 The best Rank
#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;
struct Student{
	int id;// 学生id
	int grade[4];// 存放4个分数 
}stu[2010];

char course[4] = {
	'A', 'C', 'M', 'E'
};

int now;// cmp函数使用 

bool cmp(Student a, Student b)
{
	return a.grade[now] > b.grade[now];
}
int Rank[10000000][4] = {0};

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		//读入分数 
		scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		// round 四舍五入 
		stu[i].grade[0] = round(stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3] / 3.0) + 0.5;
	}
	
	// 枚举A C M E 其中一个
	for(now = 0; now < 4; now ++)
	{
		sort(stu, stu + n, cmp);
		//排序后将分数最高的设为rank1 
		Rank[stu[0].id][now] = 1;
		//为其他人设置排名 
		for(int i = 1; i < n; i++)
		{
			if(stu[i].grade[now] == stu[i-1].grade[now])
				Rank[stu[i].id][now] = Rank[stu[i-1].id][now];//排名相同
			else
				Rank[stu[i].id][now] = i + 1; 
		}
	}
	int query;
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &query);
		if(Rank[query][0] == 0) printf("N/A\n");
		else
		{
			int k = 0;
			for (int j = 0; j < 4; j++)
			{
				if(Rank[query][j] < Rank[query][k]) k = j;
			}
			printf("%d %c\n", Rank[query][k], course[k]);
		}
	}
	
	
	return 0;
}
//A1075 PAT JUADGE
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10010;

//学生结构体 
struct Student{
	int id; // 准考证
	bool flag; //是否通过编译
	int score[6]; //每道题总分 
	int score_all; // 总分
	int solve; //解题数量 
}stu[maxn];

//每道题满分 
int full[6];

//排序算法
bool cmp(Student a, Student b)
{
	
	if(a.score_all != b.score_all) return a.score_all > b.score_all;// 按总分排序
	else if(a.solve != b.solve) return a.solve > b.solve;// 总分相同按照解题数量
	else a.id < b.id; // 按照准叫做 
}

int main(){
	// n 总考生数 k总问题小于等于5 m总提交
	int n , k ,m;
	scanf("%d %d %d", &n, &k, &m);
	
	// 初始化学生信息
	for(int i = 1; i <=n; i++)
	{
		stu[i].id = i; // 准考证 
		stu[i].score_all = 0; // 总分 
		stu[i].solve = 0; // 完美解题数量 
		stu[i].flag = false; // 编译未通过的提交 
		memset(stu[i].score, -1, sizeof(stu[i].score));//题目得分均初始化为-1 编译未通过 
	} 
 	
 	//  k道的满分
	for(int i = 1; i <= k; i++)
		scanf("%d", &full[i]);
	
	//考生id 题目id 所获分值
	int u_id, p_id, score_obtained;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &u_id, &p_id, &score_obtained);
		if(score_obtained != -1) stu[u_id].flag = true;
		//p_id编译错误 记为零分 
		if(score_obtained == -1 && stu[u_id].score[p_id] == -1) 
			stu[u_id].score[p_id] = 0;
		//某题满分 完美解题数加一（注意这里也有可能该同学解多次题 之前有过记录） 
		if(score_obtained == full[p_id] && stu[u_id].score[p_id] < full[p_id]) 
			stu[u_id].solve++;
		//某题解题更高分值 则覆盖
		if(score_obtained > stu[u_id].score[p_id])
			stu[u_id].score[p_id] = score_obtained;	 
	}
	
	//计算总分
	for(int i = 0; i <= n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(stu[i].score[j] != -1)
				stu[i].score_all += stu[i].score[j];
		}
	} 
	
	sort(stu+1, stu+n-1, cmp);
	//当前排名 
	int r = 1;
	for(int i = 1; i <= n && stu[i].flag == true; i++)
	{
		if(i > 1 && stu[i].score_all != stu[i - 1].score_all)
			r = i;
		printf("%d  %05d %d", r, stu[i].id,  stu[i].score_all);
		//输出每道题得分 
		for(int j = 1; j <= k; j++)
		{
			if(stu[i].score[j] == -1) printf(" -");
			else printf(" %d", stu[i].score[j]);
		}
		printf("\n");
	}
	 
	return 0;
}
// A1080 Graduate admission
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 40010;
//学生 
struct Student{
	int GE, GI, sum; // 初试分数 面试分数 总分
	int r, stuID; // 排名、考生编号
	int cho[6]; // K个志愿学校的编号 
}stu[maxn];
//学校 
struct School{
	int quota; // 招生总额
	int stuNum; // 实际招生人数
	int id[maxn]; // 招生编号
	int lastAdmit; // 最后一个招收学生的编号 
}sch[110];

//排序方法
bool cmpStu(Student a, Student b)
{
	if(a.sum != b.sum) return a.sum > b.sum;
	else return a.GE > b.GE;
} 
bool cmpID(int a, int b)
{
	return stu[a].stuID < stu[b].stuID;
}
int main(){
	// n为考生人数 m为学校数 k为每人可以申请的学校数 
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	//初始化学校招生 
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &sch[i].quota); // 招生总额 
		sch[i].stuNum = 0; // 实际人数 
		sch[i].lastAdmit = -1; // 最后一个招收的学生编号 
	}
	// 初始化考生
	for(int i = 0; i < n; i++)
	{
		stu[i].stuID = i;
		scanf("%d %d", &stu[i].GE, &stu[i].GI);
		stu[i].sum= stu[i].GE + stu[i].GI;
		for(int j = 0; j < k; j++)
			scanf("%d", &stu[i].cho[j]);
	}
	
	//学生成绩排序
	sort(stu, stu + n, cmpStu);
	
	for(int i = 0; i < n; i++)
	{
		if(i > 0 && stu[i].sum == stu[i - 1].sum && stu[i].GE == stu[i - 1].GE) 
			stu[i].r = stu[i - 1].r;
		else stu[i].r = i;
	}
	// 对每位考生 判断被哪所学校录取
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			int choice = stu[i].cho[j]; // 考生i的第j志愿 
			int num = sch[choice].stuNum; // 学校当前招生人数 
			int last = sch[choice].lastAdmit; // 该学校最后一位录取考生编号
			if(num < sch[choice].quota 
			|| (last != -1 
			&& stu[i].r == stu[last].r))
			{
				sch[choice].id[num] = i; // 录取该学生 
				sch[choice].lastAdmit = i; // 最后录取的学生
				sch[choice].stuNum++; // 当前招生人数加1
				break;
			}
		}
	}
	
	for(int i = 0; i < m; i ++)
	{
		if(sch[i].stuNum > 0)
		{
			sort(sch[i].id, sch[i].id + sch[i].stuNum, cmpID);
			for(int j = 0; j < sch[i].stuNum; j++)
			{
				printf("%d", stu[sch[j].id[j]].stuID);
				if(j < sch[i].stuNum - 1) printf(" "); 
			}
		}
		printf(" ");
	}
	
	return 0;
} 
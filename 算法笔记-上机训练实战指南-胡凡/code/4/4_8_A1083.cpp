#include <stdio.h>
#include <cstring>
#include <algorithm>
 
using namespace std;

const int maxn = 51;

struct Student{
	char name[11]; // 姓名 
	char id[11]; // 准考证 
	int grade; // 分数 
}stu[maxn];

bool cmp(Student a, Student b)
{
	return a.grade > b.grade; //按分数从大到小排序  
}
 
int main(){
	//n 所有考生 
	int n, left, right;
	
	scanf("%d", &n);
	// 输入考生情况 
	for(int i = 0; i < n; i++)
	{
		scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
	}
	// 区间左右端点
	scanf("%d %d", &left, &right);
	sort(stu, stu+n, cmp);
	
	bool flag = false; // 用于确定是否不存在区间范围内的考生 
	//输出区间范围内的考生
	for(int i = 0; i < n; i++)
	{
		if(stu[i].grade >= left && stu[i].grade <= right)
		{
			printf("%s %s\n", stu[i].name, stu[i].id);
			flag = true; 
		}
	}
	if(flag == false) printf("None\n");
	return 0;
}
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student{
	char id[15]; //准考证 
	int score; // 分数 
	int location_number; //考场号
	int local_rank; // 考场内排名 
}stu[30010];

//比较函数 
bool cmp(Student a, Student b)
{
	if(a.score != b.score) return a.score > b.score; //按分数从高到低
	else return strcmp(a.id, b.id) < 0; // 分数相同 按准考证从小到大排序 
}
 
int main(){
	int n, k, num = 0; //num为总考生数
	//输入考场数n
	scanf("%d", &n); 
	for(int i = 1; i <= n; i++)
	{
		// 该考场内可容纳人数 
		scanf("%d", &k);
		for(int j = 0; j < k; j++)
		{
			//输入考生信息 
			scanf("%s %d", stu[num].id, &stu[num].score);
			//考场号 
			stu[num].location_number = i;
			//总人数加一 
			num ++;
		}
		//对这个考场的考生排序 
		sort(stu + num - k, stu + num, cmp);
		//对该考场第一名的记为第一名 
		stu[num - k].local_rank = 1;
		//对该考场的剩余学生排序 
		for(int j = num - k + 1; j < num; j++)
		{
			if(stu[j].score == stu[j - 1].score)
				stu[j].local_rank = stu[j - 1].local_rank;
			else
				//如果分数和前一位不同 则当前考生排名为j+1 -(num-k) 
				stu[j].local_rank = j + 1 - (num - k);
		}
	}
	
	//输出部分
	printf("%d\n", num); //考生总人数 
	sort(stu, stu + num, cmp); //将所有学生排序
	
	//当前学生排名 用r来动态更新 处理好分数相同并列排名情况 
	int r = 1; 
	for(int i = 0; i < num; i++)
	{
		if(i > 0 && stu[i].score != stu[i-1].score) r = i + 1;
		printf("%s %d %d %d\n", stu[i].id, r, stu[i].location_number, stu[i].local_rank);
	}
	return 0;
} 
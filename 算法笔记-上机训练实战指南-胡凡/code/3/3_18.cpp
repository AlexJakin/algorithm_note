#include <stdio.h>
const int  maxn = 10010;
int school[maxn] = {0};// 索引是学校编号 值是总分 

int main(){
	int n, school_id, score;
	//输入学生成绩总数
	scanf("%d ", &n);
	//输入学生分数 并 统计 
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &school_id,  &score);
		school[school_id] +=score;
	}
	//输出
	int k, max = -1;
	for(int i = 1; i <= n; i++)
	{
		if(school[i] > max)
		{
			k = i;
			max = school[i];
		}
	}
	printf("%d %d\n", k, max);
	return 0;
}
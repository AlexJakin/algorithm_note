#include <stdio.h>

struct person{
	char name[20]; // 姓名 
	char id[15]; // ID
	int score; // 分数 
}men_min_score, femen_max_score, temp;

int main(){
	int n;
	scanf("%d", &n);
	char gender;
	//初始化最大和最小
	men_min_score.score = 101;
	femen_max_score.score = -1; 
	for(int i = 0; i < n; i++)
	{
		scanf("%s %c %s %d", &temp.name, &gender, &temp.id, &temp.score);
		if(gender == 'M'  && temp.score < men_min_score.score)
			men_min_score = temp;
		else if(gender == 'F' && temp.score> femen_max_score.score)
			femen_max_score = temp;
	}
	
	if(femen_max_score.score == -1)//没有女生 
		printf("Absent\n");
	else
		printf("%s %s\n", femen_max_score.name, femen_max_score.id);
	if(men_min_score.score == 101)//没有男生 
		printf("Absent\n");
	else
		printf("%s %s\n", men_min_score.name, men_min_score.id);
	if(femen_max_score.score == -1 || men_min_score.score == 101)
		printf("NA\n");
	else
		printf("%d\n", femen_max_score.score - men_min_score.score);
	return 0;
}
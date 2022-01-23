//B1041 ≥…º®≈≈√˚ 
#include <stdio.h>

struct Student{
	char name[20];
	char id[15];
	int score;
}temp, max_score_student, min_score_student;

int main(){
	int n;
	scanf("%d", &n);
	max_score_student.score = -1;
	min_score_student.score = 101;
	for(int i = 0; i < n; i++)
	{
		scanf("%s%s%d", temp.name, temp.id, &temp.score);
		if(temp.score > max_score_student.score) max_score_student = temp;
		if(temp.score < min_score_student.score) min_score_student = temp;
	}
	printf("%s %s\n", max_score_student.name, max_score_student.id);
	printf("%s %s\n", min_score_student.name, min_score_student.id);
	return 0;
}
 #include <stdio.h>
 #include <cstring>
 #include <algorithm>
 
 using namespace std;
 const int maxn = 100010;
 
 //学生结构
 struct Student{
 	int id; // 准考证号 
 	char name[10]; // 姓名 
 	int score; //分数 
 }stu[maxn];
 
 //C = 1 准考证排序从小到大排序 
 bool cmp1(Student a, Student b) 
 {
 	return a.id < b.id;
 }
 
 //C = 2 姓名从小到大排序
 bool cmp2(Student a, Student b)
 {
 	if(a.name != b.name) return strcmp(a.name, b.name) < 0; //姓名相同 
	else return a.id < b.id; //如果姓名相同 用准考证排名 
 } 
 
 //C = 3 按分数排名 
 bool cmp3(Student a, Student b)
 {
 	if(a.score != b.score) return a.score < b.score;// 按照分数排序 
 	else return a.id < b.id;// 分数相同 准考证排序 
 } 
 
 int main(){
 	//n：考生人数 C：排序方式 
 	int n, c;
 	scanf("%d %d", &n, &c);
 	
 	for(int i = 0; i < n; i++)
 	{
	 	scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].score);
 	}
 	//使用第一种排序 
 	if(c == 1) sort(stu, stu + n, cmp1);
	else if (c == 2) sort(stu, stu + n, cmp2);
	else sort(stu, stu + n,  cmp3);
	
	//输出
	for(int i = 0; i < n; i++)
	{
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
	} 
 	return 0;
 }
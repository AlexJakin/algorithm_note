 #include <stdio.h>
 #include <cstring>
 #include <algorithm>
 
 using namespace std;
 const int maxn = 100010;
 
 //ѧ���ṹ
 struct Student{
 	int id; // ׼��֤�� 
 	char name[10]; // ���� 
 	int score; //���� 
 }stu[maxn];
 
 //C = 1 ׼��֤�����С�������� 
 bool cmp1(Student a, Student b) 
 {
 	return a.id < b.id;
 }
 
 //C = 2 ������С��������
 bool cmp2(Student a, Student b)
 {
 	if(a.name != b.name) return strcmp(a.name, b.name) < 0; //������ͬ 
	else return a.id < b.id; //���������ͬ ��׼��֤���� 
 } 
 
 //C = 3 ���������� 
 bool cmp3(Student a, Student b)
 {
 	if(a.score != b.score) return a.score < b.score;// ���շ������� 
 	else return a.id < b.id;// ������ͬ ׼��֤���� 
 } 
 
 int main(){
 	//n���������� C������ʽ 
 	int n, c;
 	scanf("%d %d", &n, &c);
 	
 	for(int i = 0; i < n; i++)
 	{
	 	scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].score);
 	}
 	//ʹ�õ�һ������ 
 	if(c == 1) sort(stu, stu + n, cmp1);
	else if (c == 2) sort(stu, stu + n, cmp2);
	else sort(stu, stu + n,  cmp3);
	
	//���
	for(int i = 0; i < n; i++)
	{
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
	} 
 	return 0;
 }
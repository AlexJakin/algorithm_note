#include <stdio.h>
#include <cstring>
#include <algorithm>
 
using namespace std;

const int maxn = 51;

struct Student{
	char name[11]; // ���� 
	char id[11]; // ׼��֤ 
	int grade; // ���� 
}stu[maxn];

bool cmp(Student a, Student b)
{
	return a.grade > b.grade; //�������Ӵ�С����  
}
 
int main(){
	//n ���п��� 
	int n, left, right;
	
	scanf("%d", &n);
	// ���뿼����� 
	for(int i = 0; i < n; i++)
	{
		scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
	}
	// �������Ҷ˵�
	scanf("%d %d", &left, &right);
	sort(stu, stu+n, cmp);
	
	bool flag = false; // ����ȷ���Ƿ񲻴������䷶Χ�ڵĿ��� 
	//������䷶Χ�ڵĿ���
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
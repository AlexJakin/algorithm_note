#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

//�����ṹ��
struct Student{
	char id[10]; //׼��֤ 
	int de, cai, sum; // �� �� �ܷ�
	int flag; // �������� һ������ 
}stu[100010]; 

//����Ƚ����࿼�� 
bool cmp(Student a, Student b)
{
	// ���С����ǰ 
	if(a.flag != b.flag) return a.flag < b.flag;
	// ������ͬ��ͬʱ���ָܷ���ǰ�� 
	else if(a.sum != b.sum) return a.sum > b.sum;
	// �ܷ���ͬʱ���·ִ���� 
	else if(a.de != b.de) return a.de > b.de;
	//�·���ͬ��׼��֤С��ǰ 
	else return strcmp(a.id, b.id) < 0;
}

int main(){
	int n, L, H;
	scanf("%d%d%d", &n, &L, &H);
	//m Ϊ�������� 
	int m = n;
	
	//���뿼��
	for(int i = 0; i < n; i++)
	{
		scanf("%s %d %d", stu[i].id, &stu[i].de, &stu[i].cai);
		stu[i].sum = stu[i].de + stu[i].cai;
		if(stu[i].de < L || stu[i].cai < L)
		{
			stu[i].flag= 5;
			m--;
		}
		else if(stu[i].de >= H && stu[i].cai >= H) stu[i].flag = 1;// ��һ��
		else if(stu[i].de >= H && stu[i].cai < H) stu[i].flag = 2;// �ڶ���
		else if(stu[i].de >= stu[i].cai) stu[i].flag = 3;// ������
		else stu[i].flag = 4; // ������Ϊ������ 
	}
	sort(stu, stu + n, cmp);
	printf("%d\n", m);
	
	for(int i = 0; i < m; i++)
	{
		printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
	}
	return 0;
} 
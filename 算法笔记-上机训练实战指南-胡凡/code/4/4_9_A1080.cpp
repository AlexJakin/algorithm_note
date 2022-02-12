// A1080 Graduate admission
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 40010;
//ѧ�� 
struct Student{
	int GE, GI, sum; // ���Է��� ���Է��� �ܷ�
	int r, stuID; // �������������
	int cho[6]; // K��־ԸѧУ�ı�� 
}stu[maxn];
//ѧУ 
struct School{
	int quota; // �����ܶ�
	int stuNum; // ʵ����������
	int id[maxn]; // �������
	int lastAdmit; // ���һ������ѧ���ı�� 
}sch[110];

//���򷽷�
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
	// nΪ�������� mΪѧУ�� kΪÿ�˿��������ѧУ�� 
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	//��ʼ��ѧУ���� 
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &sch[i].quota); // �����ܶ� 
		sch[i].stuNum = 0; // ʵ������ 
		sch[i].lastAdmit = -1; // ���һ�����յ�ѧ����� 
	}
	// ��ʼ������
	for(int i = 0; i < n; i++)
	{
		stu[i].stuID = i;
		scanf("%d %d", &stu[i].GE, &stu[i].GI);
		stu[i].sum= stu[i].GE + stu[i].GI;
		for(int j = 0; j < k; j++)
			scanf("%d", &stu[i].cho[j]);
	}
	
	//ѧ���ɼ�����
	sort(stu, stu + n, cmpStu);
	
	for(int i = 0; i < n; i++)
	{
		if(i > 0 && stu[i].sum == stu[i - 1].sum && stu[i].GE == stu[i - 1].GE) 
			stu[i].r = stu[i - 1].r;
		else stu[i].r = i;
	}
	// ��ÿλ���� �жϱ�����ѧУ¼ȡ
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			int choice = stu[i].cho[j]; // ����i�ĵ�j־Ը 
			int num = sch[choice].stuNum; // ѧУ��ǰ�������� 
			int last = sch[choice].lastAdmit; // ��ѧУ���һλ¼ȡ�������
			if(num < sch[choice].quota 
			|| (last != -1 
			&& stu[i].r == stu[last].r))
			{
				sch[choice].id[num] = i; // ¼ȡ��ѧ�� 
				sch[choice].lastAdmit = i; // ���¼ȡ��ѧ��
				sch[choice].stuNum++; // ��ǰ����������1
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
//A1075 PAT JUADGE
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10010;

//ѧ���ṹ�� 
struct Student{
	int id; // ׼��֤
	bool flag; //�Ƿ�ͨ������
	int score[6]; //ÿ�����ܷ� 
	int score_all; // �ܷ�
	int solve; //�������� 
}stu[maxn];

//ÿ�������� 
int full[6];

//�����㷨
bool cmp(Student a, Student b)
{
	
	if(a.score_all != b.score_all) return a.score_all > b.score_all;// ���ܷ�����
	else if(a.solve != b.solve) return a.solve > b.solve;// �ܷ���ͬ���ս�������
	else a.id < b.id; // ����׼���� 
}

int main(){
	// n �ܿ����� k������С�ڵ���5 m���ύ
	int n , k ,m;
	scanf("%d %d %d", &n, &k, &m);
	
	// ��ʼ��ѧ����Ϣ
	for(int i = 1; i <=n; i++)
	{
		stu[i].id = i; // ׼��֤ 
		stu[i].score_all = 0; // �ܷ� 
		stu[i].solve = 0; // ������������ 
		stu[i].flag = false; // ����δͨ�����ύ 
		memset(stu[i].score, -1, sizeof(stu[i].score));//��Ŀ�÷־���ʼ��Ϊ-1 ����δͨ�� 
	} 
 	
 	//  k��������
	for(int i = 1; i <= k; i++)
		scanf("%d", &full[i]);
	
	//����id ��Ŀid �����ֵ
	int u_id, p_id, score_obtained;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &u_id, &p_id, &score_obtained);
		if(score_obtained != -1) stu[u_id].flag = true;
		//p_id������� ��Ϊ��� 
		if(score_obtained == -1 && stu[u_id].score[p_id] == -1) 
			stu[u_id].score[p_id] = 0;
		//ĳ������ ������������һ��ע������Ҳ�п��ܸ�ͬѧ������ ֮ǰ�й���¼�� 
		if(score_obtained == full[p_id] && stu[u_id].score[p_id] < full[p_id]) 
			stu[u_id].solve++;
		//ĳ�������߷�ֵ �򸲸�
		if(score_obtained > stu[u_id].score[p_id])
			stu[u_id].score[p_id] = score_obtained;	 
	}
	
	//�����ܷ�
	for(int i = 0; i <= n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(stu[i].score[j] != -1)
				stu[i].score_all += stu[i].score[j];
		}
	} 
	
	sort(stu+1, stu+n-1, cmp);
	//��ǰ���� 
	int r = 1;
	for(int i = 1; i <= n && stu[i].flag == true; i++)
	{
		if(i > 1 && stu[i].score_all != stu[i - 1].score_all)
			r = i;
		printf("%d  %05d %d", r, stu[i].id,  stu[i].score_all);
		//���ÿ����÷� 
		for(int j = 1; j <= k; j++)
		{
			if(stu[i].score[j] == -1) printf(" -");
			else printf(" %d", stu[i].score[j]);
		}
		printf("\n");
	}
	 
	return 0;
}
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student{
	char id[15]; //׼��֤ 
	int score; // ���� 
	int location_number; //������
	int local_rank; // ���������� 
}stu[30010];

//�ȽϺ��� 
bool cmp(Student a, Student b)
{
	if(a.score != b.score) return a.score > b.score; //�������Ӹߵ���
	else return strcmp(a.id, b.id) < 0; // ������ͬ ��׼��֤��С�������� 
}
 
int main(){
	int n, k, num = 0; //numΪ�ܿ�����
	//���뿼����n
	scanf("%d", &n); 
	for(int i = 1; i <= n; i++)
	{
		// �ÿ����ڿ��������� 
		scanf("%d", &k);
		for(int j = 0; j < k; j++)
		{
			//���뿼����Ϣ 
			scanf("%s %d", stu[num].id, &stu[num].score);
			//������ 
			stu[num].location_number = i;
			//��������һ 
			num ++;
		}
		//����������Ŀ������� 
		sort(stu + num - k, stu + num, cmp);
		//�Ըÿ�����һ���ļ�Ϊ��һ�� 
		stu[num - k].local_rank = 1;
		//�Ըÿ�����ʣ��ѧ������ 
		for(int j = num - k + 1; j < num; j++)
		{
			if(stu[j].score == stu[j - 1].score)
				stu[j].local_rank = stu[j - 1].local_rank;
			else
				//���������ǰһλ��ͬ ��ǰ��������Ϊj+1 -(num-k) 
				stu[j].local_rank = j + 1 - (num - k);
		}
	}
	
	//�������
	printf("%d\n", num); //���������� 
	sort(stu, stu + num, cmp); //������ѧ������
	
	//��ǰѧ������ ��r����̬���� ����÷�����ͬ����������� 
	int r = 1; 
	for(int i = 0; i < num; i++)
	{
		if(i > 0 && stu[i].score != stu[i-1].score) r = i + 1;
		printf("%s %d %d %d\n", stu[i].id, r, stu[i].location_number, stu[i].local_rank);
	}
	return 0;
} 
// �ֵ���: �� ���� ���� 
//(k2+1)%3== k1 ��k1ʤk2 

#include <stdio.h>

//�� �� ���� ����ת��Ϊ���� 
int change(char c)
{
	if(c == 'B') return 0;
	if(c == 'C') return 1;
	if(c == 'J') return 2;
}

int main(){
	char mp[3] = {
		'B', 'C', 'J'
	};
	int n;
	scanf("%d", &n);
	//��¼���ҵ�ʤƽ������ 
	int times_A[3]={0}, times_B[3]={0};
	//��BCJ�ֵ����¼�����������ƵĻ�ʤ����
	int hand_A[3]={0}, hand_B[3]={0};
	char c1, c2;
	int k1, k2;
	for(int i = 0; i < n; i++)
	{
		getchar();
		scanf("%c %c", &c1, &c2);
		k1 = change(c1);
		k2 = change(c2);
		 
		if(k2 == (k1+1)%3)//�׻�ʤ 
		{
			times_A[0]++;//��Ӯ����
			times_B[2]++;//�������
			hand_A[k1]++;//����mp[k1]��ʤ�Ĵ��� 
		}
		else if(k1 == (k2+1)%3)//�һ�ʤ 
		{
			times_A[2]++;//�������
			times_B[0]++;//��Ӯ����
			hand_B[k2]++;//����mp[k2]��ʤ�Ĵ��� 
		}
		else
		{
			times_A[1]++;//��ƽ�ִ��� 
			times_B[1]++;//��ƽ�ִ��� 
		}
	}
	printf("%d %d %d\n", times_A[0], times_A[1], times_A[2]);
	printf("%d %d %d\n", times_B[0], times_B[1], times_B[2]);
	//�ҳ����Ҹ��Ի�ʤ�������� 
	int id1 = 0, id2 = 0;
	for(int i = 0; i < 3; i++)
	{
		if(hand_A[i] > hand_A[id1]) id1 = i;
		if(hand_B[i] > hand_B[id1]) id2 = i;
	}
	printf("%c %c", mp[id1], mp[id2]);
	return 0;
} 
 
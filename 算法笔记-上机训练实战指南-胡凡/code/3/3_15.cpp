/**
B1041 ������λ��
�����Ի���λ��Ϊ���� 
**/
#include <stdio.h>

const int maxn = 1010;
//ѧ��
struct Student{
	long long id; // ׼��֤ 
	int examSeat; // ������λ�� 
}testSeat[maxn];

int main(){
	int n, m, Tseat, examSeat;
	long long id;
	//��������
	scanf("%d", &n);
	
	//���뿼������ 
	for(int i = 0; i < n; i++)
	{
		scanf("%lld %d %d", &id, &Tseat, &examSeat);
		testSeat[Tseat].id = id;
		testSeat[Tseat].examSeat = examSeat;
	}
	
	
	//��ѯѧ���� 
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &Tseat);
		printf("%lld %d\n", testSeat[Tseat].id, testSeat[Tseat].examSeat);
	}
	return 0;
}
/**
1. start[] ��ų�ʼ����  end[] ����൱��  next[]��ű仯˳�� 
   1~13 ��ʾ S 14~26 ��ʾ H  �ȵ��ƶϳ� (x-1)%13+1 Ϊ������ɫ��� 
**/ 
#include <stdio.h>
const int N = 54;
char mp[5] = {
	'S', 'H', 'C', 'D', 'J'
};
int start[N+1], end[N+1], next[N+1];
int main(){
	/**      input part      **/
 	//�仯���� 
	int K;
	scanf("%d", &K);
	//��ʼ����λ 
	for(int i = 1; i <= N; i++)
	{
		start[i] = i;
	}
	//��ʼ���ƶ�����
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &next[i]);
	} 
	
	/**      process      **/
	for(int step = 0; step < K; step++)
	{
		for(int i = 1; i <= N; i++)
		{
			//�任 
			end[next[i]] = start[i];
		}
		for(int i = 1; i <= N; i++)
		{
			start[i] = end[i];
		}
	}
	
	/**      output      **/
	for(int i = 1; i <= N; i++)
	{
		//�����ʽ ��һ��������ո� 
		if(i != 1) printf(" ");
		start[i]--;//�����±���0Ϊ��� 
		//����start[]�Ǵ�Ž��˳�� 
		printf("%c%d", mp[(start[i]/13)], (start[i]%13+1));
	}
	return 0;
} 

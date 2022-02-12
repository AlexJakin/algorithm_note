// A1067 Sort with swap(0,*)
// 0������뽻�� ÿ�������÷�������ع鱾λ
// ���0�ڵ�iλ �ҵ�����i��λ�� ��0��i���н���
// ps ����ʹ�� ÿ�����ֵ��������� ��pos���� 
#include <stdio.h>

//����Ҳ�в���ָ��ķ������������� 
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
const int maxn = 100010;
int pos[maxn]; // pos���ÿ�����ĵ�ǰ��� 

int main(){
	int n, ans = 0; // ans�ǽ������� 
	scanf("%d", &n);
	//nums��Ų���Ŀ��λ������ numΪ��ǰ�� 
	int nums = n - 1, num;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		pos[num] = i;  // ���num��i��ͬ˵��������Ŀ��λ���� 
		// ��0���ڱ�λ�ϵ���
		if(num == i && num != 0) nums--;
	}
	
	// ����
	int k = 1; // k��ų�0�⵱ǰ���ڱ�λ�ϵ���С����
	while(nums > 0)//ֱ�����������ص�ԭλ 
	{
		//���0�ڵ�ǰλ ѡ����С���ڵ�ǰλ������0����
		//������0�����ı�Ҫ���� 
		if(pos[0] == 0)
		{
			while(k < n)
			{
				// �ҵ�һ�����ڱ�λ�ϵ��� 
				if(pos[k] != k)
				{
					swap(pos[0], pos[k]);
					ans++;
					break; 
				}
				k++;
			}
		}
		//0���ڱ�λ 
		while(pos[0] != 0)
		{
			// 0����λ�õ������� �� ����������λ�û��� ʹ���������ص�Ŀ��λ��
			// ��num = i 
			swap(pos[0], pos[pos[0]]);
			ans++;
			nums--;
		}
	} 
	printf("%d\n", ans);
	return 0;
}
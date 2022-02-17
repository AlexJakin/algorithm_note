// A1078 Hashing
#include <stdio.h>
#include <cmath>
#include <vector>
const int N = 11111;
using namespace std;

// �ж��Ƿ�������
bool isPrime(int n) 
{
	if(n <= 1) return false;
	int sqr = sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i ++)
		if(n % 2 == 0) return false;
	return true;
}
//��ϣ��
bool hashTable[N] = {0};  

int main(){
	int n, Tsize, a;
	scanf("%d %d", &Tsize, &n);
	// Ѱ�Ҵ���Tsize����С���� 
	while(isPrime(Tsize) == false) Tsize++;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		//Ѱ�Ҳ���λ��M ���Mλ���Ѿ�����ʹ�ö��η�̽�鷨 
		int M = a % Tsize;
		if(hashTable[M] == false)
		{
			hashTable[M] = true;
			//�������λ�� 
			if(i == 0) printf("%d", M);
			else printf(" %d", M);
		}
		else // ʹ�ö��η�̽�鷨 (��ĿֻҪ������)
		{
			int step;//����
			for(step = 1; step < Tsize; step++)
			{
				M = (a + step * step) % Tsize; // ��һ����鷨
				if(hashTable[M] == false)
				{
					hashTable[M] = true;
					// �������λ�� 
					if(i == 0) printf("%d", M);
					else printf(" %d", M);
					break; // һ��Ҫ����ѭ�� 
				} 
			}
			//�Ҳ�������λ�� 
			if(step >= Tsize)
			{
				if(i > 0) printf(" ");
				printf("-");
			}	
		}
	}
	return 0;
}
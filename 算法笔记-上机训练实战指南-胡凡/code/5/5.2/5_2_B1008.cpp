// B1008 ����Ԫ��ѭ����������
// ���ƶ���������
// �����Լ��������ѭ������
 
#include <stdio.h>
#include <cstring>

//�����Լ���ĵݹ��㷨 
int gcd(int a, int b)
{
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int main(){
	int a[110];
	// temp��ʱ���� pos��ǰ����λ��  next��һ������λ��  
	int n, m, temp, pos, next;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	m = m % n; // ����m��ѭ���Ľ����m%n��һ�� 
	if(m != 0)
	{
		int d = gcd(m, n);
		// ��n-m����ʼ 
		for(int i = n - m; i < n - m + d; i++)
		{
			temp = a[i];
			pos = i; // ��¼��ǰλ��
			
			do{
				next = (pos - m + n) % n;
				if(next != i) a[pos] = a[next];
				else a[pos] = temp;
				pos = next;
			}while(pos != i);
		}
	}
	
	// ���
	for(int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if(i < n - 1) printf(" ");
	} 
	
	return 0;
}

/**
��Ϊÿ�β���1�Ŀ��ΪK����KΪ��󹫱�������K/M��Ϊÿ�β���1�����ŵ����ָ���������Ϊ�ƶ��ľ���Ϊ4����������ʼλ��Ҫ�ƶ�����Ϊ6�ı������������һ�β���1һ����Խ��12��������3�����ֱ����ţ�

ÿ�����־���һ�����žͿɵ���ָ��λ�ã���һ����N��������Ҫ���ţ�N/(K/M)��Ϊ��Ҫ���в���1�Ĵ�������MN/K��d����˽���d�β���1���ɣ�

��֪������ѡȡ��ʼλ����ʹÿ�����ֶ������š�
�ο� https://www.cnblogs.com/Ivan-Luo/p/11150804.html 
// A1077 Kuchiguse
#include <stdio.h>
#include <cstring>

char s[100][256];//���100���ַ��� һ���ַ���256���ַ�

//�ַ�����ת
void reverse(char s[])
{
	int len = strlen(s);
	for(int i = 0; i < len/2; i ++)
	{
		char temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
} 

int main(){
	//�ַ�����
	int n;
	int minlen;//��С�ַ��� 
	scanf("%d", &n);
	getchar();//���ջ��� 
	//ʹ��gets�������ַ��� ��ʹ��scanf ��Ϊ�ַ������ܴ�ſո�
	for(int i = 0; i < n; i++)
	{
		gets(s[i]);
		int len = strlen(s[i]);
		if(len < minlen) minlen = len;
		//��ת�ַ���  ���󹫹���׺�������󹫹�ǰ׺
		reverse(s[i]); 
	}
	
	//����ǰ׺������ ����һ���ַ���ͬ ���һ 
	//�������ʱ��λ �ڹ���ǰ׺�´Ӻ���ǰ�����ɹ�����׺ 
	int ans = 0;
	
	//�ж������ַ�����i���ַ����Ƿ�ȫ�����
	for(int i = 0; i < minlen; i++)
	{
		char c = s[0][i];
		bool same = true; //�Ƿ���ͬ
		//ö����������j�ַ��� 
		for(int j = 1; j < n ; j++)
		{
			if(s[j][i] != c)
			{
				same = false;
				break;
			}
		}
		if(same) ans++; //��ͬ����������� 
		else break; //����ͬ 
	}
	
	//���
	if(ans)
	{
		for(int i = ans - 1; i >= 0; i--)
		{
			printf("%c", s[0][i]);
		}
	}
	else
	{
		printf("nai");
	}
	return 0;
} 
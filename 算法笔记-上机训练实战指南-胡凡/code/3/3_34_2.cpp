//B1009 ˵���� �ڶ��ֽⷨ
//ע��ʹ��ctrl+z�������� 
 
#include <stdio.h>
#include <cstring>

int main(){
	int nums = 0;
	int ans[80][80];
	while(scanf("%s", ans[nums]) != EOF) nums++; // ͳ�Ƶ��ʵĸ���
	
	//������� 
	for(int i = nums - 1; i >= 0; i--)
	{
		printf("%s", ans[i]);
		if(i > 0) printf(" ");
	}
	return 0;
}
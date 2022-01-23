#include <stdio.h>

using namespace std;
struct pNode{
	char id[20];
	int hh, mm, ss; // ans_min ����ǩ��ʱ�� ans_max ����ǩ��ʱ��	
}temp, ans_min, ans_max;

// �ж� node1�Ƿ����node2
bool great(pNode node1, pNode node2){
	if(node1.hh != node2.hh) return node1.hh > node2.hh;
	if(node1.mm != node2.mm) return node1.mm > node2.mm;
	return node1.ss > node2.ss;
} 

int main(){
	int n;
	scanf("%d", &n);
	ans_min.hh = 24, ans_min.mm = 60, ans_min.ss = 60; //��ǩ��ʱ��Ū����� 
	ans_max.hh =  0, ans_max.mm =  0, ans_max.ss =  0; //��ǩ��ʱ��Ū����С
	for(int i = 0; i < n; i++)
	{
		//����ǩ��ʱ��
		scanf("%s %d:%d:%d", &temp.id, &temp.hh, &temp.mm, &temp.ss);
		//ȡ��С��ǩ��ʱ�� 
		if(great(temp, ans_min) == false)
			ans_min = temp;
		//ȡ�����ǩ��ʱ��
		if(great(temp, ans_max) == true)
			ans_max = temp; 
	}
	printf("%s %s\n", ans_min.id, ans_max.id);
	return 0;
}
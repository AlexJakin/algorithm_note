#include <stdio.h>

using namespace std;
struct pNode{
	char id[20];
	int hh, mm, ss; // ans_min 最早签到时间 ans_max 最晚签离时间	
}temp, ans_min, ans_max;

// 判断 node1是否大于node2
bool great(pNode node1, pNode node2){
	if(node1.hh != node2.hh) return node1.hh > node2.hh;
	if(node1.mm != node2.mm) return node1.mm > node2.mm;
	return node1.ss > node2.ss;
} 

int main(){
	int n;
	scanf("%d", &n);
	ans_min.hh = 24, ans_min.mm = 60, ans_min.ss = 60; //把签道时间弄到最大 
	ans_max.hh =  0, ans_max.mm =  0, ans_max.ss =  0; //把签离时间弄到最小
	for(int i = 0; i < n; i++)
	{
		//读入签到时间
		scanf("%s %d:%d:%d", &temp.id, &temp.hh, &temp.mm, &temp.ss);
		//取更小的签到时间 
		if(great(temp, ans_min) == false)
			ans_min = temp;
		//取更大的签离时间
		if(great(temp, ans_max) == true)
			ans_max = temp; 
	}
	printf("%s %s\n", ans_min.id, ans_max.id);
	return 0;
}
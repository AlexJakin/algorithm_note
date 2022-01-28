#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

//考生结构体
struct Student{
	char id[10]; //准考证 
	int de, cai, sum; // 德 才 总分
	int flag; // 考生类型 一共五类 
}stu[100010]; 

//归类比较四类考生 
bool cmp(Student a, Student b)
{
	// 类别小的在前 
	if(a.flag != b.flag) return a.flag < b.flag;
	// 类型相同相同时，总分高在前面 
	else if(a.sum != b.sum) return a.sum > b.sum;
	// 总分相同时，德分大的在 
	else if(a.de != b.de) return a.de > b.de;
	//德分相同，准考证小在前 
	else return strcmp(a.id, b.id) < 0;
}

int main(){
	int n, L, H;
	scanf("%d%d%d", &n, &L, &H);
	//m 为及格人数 
	int m = n;
	
	//输入考生
	for(int i = 0; i < n; i++)
	{
		scanf("%s %d %d", stu[i].id, &stu[i].de, &stu[i].cai);
		stu[i].sum = stu[i].de + stu[i].cai;
		if(stu[i].de < L || stu[i].cai < L)
		{
			stu[i].flag= 5;
			m--;
		}
		else if(stu[i].de >= H && stu[i].cai >= H) stu[i].flag = 1;// 第一类
		else if(stu[i].de >= H && stu[i].cai < H) stu[i].flag = 2;// 第二类
		else if(stu[i].de >= stu[i].cai) stu[i].flag = 3;// 第三类
		else stu[i].flag = 4; // 其他归为第四类 
	}
	sort(stu, stu + n, cmp);
	printf("%d\n", m);
	
	for(int i = 0; i < m; i++)
	{
		printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
	}
	return 0;
} 
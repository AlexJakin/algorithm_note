// A1055 the world's richest
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10010; 
int Age[maxn] = {0};// 某年龄的人数 
struct Person{
	int age, worths; // 年龄、财富值 
	char name[10]; // 姓名 
}ps[maxn], valid[maxn]; // 所有人、 各自年龄中财富值在100名以内的人 
 
//比较
bool cmp(Person a, Person b)
{
	if(a.worths != b.worths) return a.worths > b.worths;//比较 财富值 
	else if(a.age != b.age) return a.age < b.age;//比较 年龄 
	else  return strcmp(a.name, b.name) < 0;// 姓名 
} 

int main(){
	//n为总人数 k为查询次数 
	int n, k;
	scanf("%d %d",  &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%s %d %d",  ps[i].name, &ps[i].age, &ps[i].worths);
	sort(ps, ps + n, cmp);
	int validNum =  0;
	//把前一百名放入valid数组中
	for(int i = 0; i < n; i++)
	{
		if(Age[ps[i].age] < 100)
		{
			Age[ps[i].age] ++;
			valid[validNum++] = ps[i];
		} 
	}
	
	//输出部分
	int m, ageL, ageR;
	for(int i = 1; i <= k; i++)//i轮询问次数  
	{
		//输入前M人, 年龄区间 
		scanf("%d%d%d", &m, &ageL, &ageR);
		printf("Case #%d:\n", i);
		int printNum = 0; //已输出人数 
		for(int j = 0; j < validNum && printNum <m; j++)
		{
			if(valid[j].age  >= ageL && valid[j].age <= ageR)
			{
				printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worths);
				printNum++;
			}
		}
		if(printNum == 0) printf("None\n");
	}
	
	return 0;
}
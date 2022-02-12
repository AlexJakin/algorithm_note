//B1038 统计同成绩学生
#include <stdio.h>
#include <cstring>

using namespace std;

int hashTable[256] = {0};

int main(){
	// n为学生数 score分数 k 为查询次数 
	int n, score, k;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &score);
		hashTable[score]++;
	}
	//查询次数
	scanf("%d", &k);
	for(int i = 0; i < k; i ++)
	{
		scanf("%d", &score);
		printf("%d", hashTable[score]);
		//前k-1个后面输出空格 
		if(i <  k - 1) printf(" ");
	} 
	return 0;
} 
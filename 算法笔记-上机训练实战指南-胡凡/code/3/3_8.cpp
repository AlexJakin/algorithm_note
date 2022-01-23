// 字典序: 布 锤子 剪刀 
//(k2+1)%3== k1 则k1胜k2 

#include <stdio.h>

//将 布 锤子 剪刀转化为数字 
int change(char c)
{
	if(c == 'B') return 0;
	if(c == 'C') return 1;
	if(c == 'J') return 2;
}

int main(){
	char mp[3] = {
		'B', 'C', 'J'
	};
	int n;
	scanf("%d", &n);
	//记录甲乙的胜平负次数 
	int times_A[3]={0}, times_B[3]={0};
	//用BCJ字典序记录甲乙三种手势的获胜次数
	int hand_A[3]={0}, hand_B[3]={0};
	char c1, c2;
	int k1, k2;
	for(int i = 0; i < n; i++)
	{
		getchar();
		scanf("%c %c", &c1, &c2);
		k1 = change(c1);
		k2 = change(c2);
		 
		if(k2 == (k1+1)%3)//甲获胜 
		{
			times_A[0]++;//甲赢次数
			times_B[2]++;//乙输次数
			hand_A[k1]++;//甲用mp[k1]获胜的次数 
		}
		else if(k1 == (k2+1)%3)//乙获胜 
		{
			times_A[2]++;//甲输次数
			times_B[0]++;//乙赢次数
			hand_B[k2]++;//乙用mp[k2]获胜的次数 
		}
		else
		{
			times_A[1]++;//甲平局次数 
			times_B[1]++;//乙平局次数 
		}
	}
	printf("%d %d %d\n", times_A[0], times_A[1], times_A[2]);
	printf("%d %d %d\n", times_B[0], times_B[1], times_B[2]);
	//找出甲乙各自获胜最多的手势 
	int id1 = 0, id2 = 0;
	for(int i = 0; i < 3; i++)
	{
		if(hand_A[i] > hand_A[id1]) id1 = i;
		if(hand_B[i] > hand_B[id1]) id2 = i;
	}
	printf("%c %c", mp[id1], mp[id2]);
	return 0;
} 
 